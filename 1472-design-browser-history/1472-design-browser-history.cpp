class BrowserHistory {
public:

    int index = -1;
    vector<string> vect;

    BrowserHistory(string homepage) {
        vect.push_back(homepage);
        index++;
    }
    
    void visit(string url) {
        vect.erase(vect.begin() + index + 1, vect.end());
        vect.push_back(url);
        index = vect.size()-1;
    }
    
    string back(int steps) {
        if(index-steps<0){
            index = 0;
            return vect.front();
        } else {
            index-=steps;
            return vect[index];
        }
    }
    
    string forward(int steps) {
        if(index+steps>=vect.size()){
            index = vect.size()-1;
            return vect.back();
        } else {
            index+=steps;
            return vect[index];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */