class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq; // key → {value, freq}
    unordered_map<int, list<int>> freqToKeys;        // freq → keys in LRU order
    unordered_map<int, list<int>::iterator> keyIter; // key → position in list

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!keyToValFreq.count(key)) return -1;

        auto [val, freq] = keyToValFreq[key];

        // Remove from old freq list
        freqToKeys[freq].erase(keyIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (freq == minFreq) minFreq++;
        }

        // Add to new freq list
        freqToKeys[freq + 1].push_back(key);
        keyIter[key] = --freqToKeys[freq + 1].end();
        keyToValFreq[key] = {val, freq + 1};

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (get(key) != -1) {
            keyToValFreq[key].first = value; // update value via get (which bumps freq)
            return;
        }

        // If full, evict LFU + LRU key
        if (keyToValFreq.size() == capacity) {
            int keyToEvict = freqToKeys[minFreq].front();
            freqToKeys[minFreq].pop_front();
            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);
            keyToValFreq.erase(keyToEvict);
            keyIter.erase(keyToEvict);
        }

        // Insert new key with freq = 1
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_back(key);
        keyIter[key] = --freqToKeys[1].end();
        minFreq = 1;
    }
};
