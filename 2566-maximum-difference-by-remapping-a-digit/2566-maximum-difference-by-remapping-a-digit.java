class Solution {
    public int minMaxDifference(int num) {
        String str = ""+num;
        char changable1 = '0'; char changable2 = '0';
        boolean b1 = false; boolean b2 = false;
        for(char ch : str.toCharArray()){
            if(ch!='9' && !b1){
                changable1 = ch;
                b1 = true;
            }
            if(ch!='0' && !b2){
                changable2 = ch;
                b2 = true;
            }
            if(b1 && b2)break;
        }
        String max = ""; String min = "";
        for(char ch : str.toCharArray()){
            if(ch == changable1){
                max+='9';
            } else {
                max+=ch;
            }
            if(ch == changable2){
                min+='0';
            } else {
                min+=ch;
            }
        }
        return Integer.valueOf(max)-Integer.valueOf(min);
    }
}