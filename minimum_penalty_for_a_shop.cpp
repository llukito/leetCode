class Solution {
public:
    int bestClosingTime(string customers) {
        int current_score = 0;
        int max_score = 0;
        int best_hour = -1;

        for(int i = 0; i < customers.size(); ++i) {
            if(customers[i] == 'Y') {
                current_score++;
            } else {
                current_score--;
            }
            
            // if we found a new maximum score, update the best hour
            if(current_score > max_score) {
                max_score = current_score;
                best_hour = i;
            }
        }
        
        return best_hour + 1;
    }
};
