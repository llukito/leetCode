class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int idx = 0;
        int curr = 0;
        while(true){
            int size = students.size();
            int tmp = curr;
            bool b = true;
            for(int i=tmp; i<size; i++){
                if(sandwiches[idx] == students[i]){
                    idx++;
                    curr++;
                    b = false; 
                } else {
                    curr++; 
                    students.push_back(students[i]);
                }
            }
            if(b)break;
        }
        return sandwiches.size()-idx;
    }
};