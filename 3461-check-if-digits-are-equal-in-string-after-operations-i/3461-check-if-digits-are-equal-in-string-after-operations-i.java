class Solution {
    public boolean hasSameDigits(String s) {
        while(s.length()!=2){
            String curr = "";
            for(int i=0; i<s.length(); i+=2){
                int ch = s.charAt(i)-'0';
                int ch2 = 0;
                if(i+1 < s.length()){
                    ch2 = s.charAt(i+1)-'0';
                }
                int nw = (ch+ch2)%10;
                curr+= String.valueOf(nw);
            }
            s = curr;
        }
        return s.charAt(0) == s.charAt(1);
    }
}