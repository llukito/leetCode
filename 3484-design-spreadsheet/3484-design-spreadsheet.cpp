class Spreadsheet {
public:
    unordered_map<string,int> map;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        map[cell] = value;
    }
    
    void resetCell(string cell) {
        map[cell] = 0;
    }
    
    int getValue(string formula) {
        string first;
        string second;
        bool b = true;
        bool word1 = true; bool word2 = true;
        for(int i=1; i<formula.length(); i++){
            if(formula[i] == '+'){
                b = false;
            } else {
                if(b){
                    if(!isdigit(formula[i]))word1=false;
                    first+=formula[i];
                } else {
                    if(!isdigit(formula[i]))word2=false;
                    second+=formula[i];
                }
            }
        }
        cout<<first<<" "<<second<<endl;
        int x = 0; int y = 0;
        if(map.count(first) || !word1){
            x = map[first];
        } else {
            x = stoi(first);
        }
        if(map.count(second) || !word2){
            y = map[second];
        } else {
            y = stoi(second);
        }
        return x+y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */