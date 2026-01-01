public:
    vector<int> plusOne(vector<int>& digits) {
        int rem = 1;
        for(int i=digits.size()-1; i>=0; i--){
            if(rem==0)break;
            digits[i] += rem;
            int h = digits[i];
            digits[i]%=10;
            rem = (h-digits[i])/10;
        }
        if(rem != 0){
            digits.insert(digits.begin(), rem);
        }
        return digits;
    }
};