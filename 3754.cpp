class Solution {
    public long sumAndMultiply(int n) {
        String str = String.valueOf(n);
        StringBuilder b = new StringBuilder();
        long sum = 0;
        for(char ch : str.toCharArray()){
            if(ch != '0'){
                b.append(ch);
                sum+=ch-'0';
            }
        }
        if((b.toString()).length() == 0)return 0;
        long num = Integer.valueOf(b.toString());
        return num*sum;
    }
}
