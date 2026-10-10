class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0;
        int counter = 0;
        for(string s : events){
            if(s == "W"){
                counter++;
            } else if(s == "WD"){
                score++;
            } else if(s == "NB"){
                score++;
            } else {
                score+=stoi(s);
            }
            if(counter == 10){
                return {score, counter};
            }
        }
        return {score, counter};
    }
};
