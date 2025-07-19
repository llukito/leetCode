class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        unordered_set<string> visited;
        for(int i=0; i<folder.size(); i++){
            string curr = folder[i];
            string vis; bool b = true; string chunk;
            for(int i=1; i<curr.length(); i++){
                char ch = curr[i];
                if(ch =='/'){
                    vis+=chunk;chunk = "";
                    if(visited.count(vis)){
                        b = false;
                        break;
                    }
                } else {
                    chunk+=ch;
                }
            }
            if(!chunk.empty())vis+=chunk;
            // cout<<vis<<endl;
            if(b && !visited.count(vis)){
                res.push_back(curr);
                visited.insert(vis);
            }
        }
        return res;
    }
};