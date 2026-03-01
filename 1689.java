class Solution {
    public int minPartitions(String n) {
        char c = '0';
        for(char ch : n.toCharArray()) if(c < ch)c = ch;
        return c-'0';
    }
}
