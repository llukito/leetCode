/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        unordered_map<int, Employee*> map;
        for(Employee* em : employees){
            map[em->id] = em;
        }
        for(auto& entry : map){
            int d = entry.first;
            if(d == id){
                check(map, res, d);
                break;
            }
        }
        return res;
    }

    void check(unordered_map<int, Employee*>& map, int& res, int d){
        res+=map[d]->importance;
        if(map[d]->subordinates.empty()){
            return;
        }
        for(int n : map[d]->subordinates){
            check(map, res, n);
        }
    }
};