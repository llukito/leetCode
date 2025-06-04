class Solution {
    public String answerString(String word, int numFriends) {
        if(numFriends == 1)return word;
        int size = word.length() - (numFriends-1);
        String res = "";
        for (int i = 0; i < word.length(); i++) {
    for (int j = Math.min(i + size - 1, word.length() - 1); j >= i; j--) {
                if(j-i+1 > size)break;
                String str = word.substring(i, j+1);
                if(str.compareTo(res) >= 0){
                    res = str;
                } else {
                    break;
                }
            }
        }
        return res;
    }
}