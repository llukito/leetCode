class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            int m = nums[i];
            while(true){
                if(st.empty()){
                    st.push(m);
                    break;
                }
                int n = st.top();
                int curr = gcd(n,m);
                if(curr <= 1){
                    st.push(m);
                    break;
                }
                st.pop();
                m = n*m/curr;
            }
        }
        vector<int> vect;
        while(!st.empty()){
            vect.push_back(st.top()); st.pop();
        }
        reverse(vect.begin(), vect.end());
        return vect;
    }

    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

};