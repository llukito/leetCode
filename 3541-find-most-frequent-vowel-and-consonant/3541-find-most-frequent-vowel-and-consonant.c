bool present(char* vowels, char ch){
    for(int i=0; vowels[i]!='\0'; i++){
        if(vowels[i]==ch)return true;
    }
    return false;
}

int maxFreqSum(char* s) {
    int chars[26] = {0}; 
    for(int i=0; s[i]!='\0'; i++){
        chars[s[i]-'a']++;
    }
    int vowNum = 0;
    int conNum = 0;
    char * vowels = "aeiou";
    for(int i=0; i<sizeof(chars)/sizeof(chars[0]); i++){
        if(present(vowels, 'a'+i)){
            if(vowNum < chars[i]){
                vowNum = chars[i];
            }
        } else {
            if(conNum < chars[i]){
                conNum = chars[i];
            }
        }
    }
    return vowNum + conNum;
}