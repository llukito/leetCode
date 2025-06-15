class Solution {
    public int maxDiff(int num) {
        String str = ""+num;
        char change1 = '/';
        char change2 = '/';
        char to = '/';
        boolean b1 = true; boolean b2 = true;
        for(int i=0; i<str.length(); i++){
            char ch = str.charAt(i);
            if(ch!='9' && b1){
                b1 = false;
                change1 = ch;
            }
            if(i==0){
                if(ch=='1')continue;
                change2 = ch;
                to = '1';
                b2 = false;
            } else if(b2 && ch!='0' && ch!=str.charAt(0)){
                change2 = ch;
                to = '0';
                b2 = false;
            }
            if(!b1 && !b2)break;
        }
        String str1 = ""; String str2 = "";
        for(char ch : str.toCharArray()){
            if(ch==change1){
                str1+='9';
            } else {
                str1+=ch;
            }
            if(ch==change2){
                str2+=to;
            } else {
                str2+=ch;
            }
        }
        System.out.println(str1);
         System.out.println(str2);
        return Integer.valueOf(str1)-Integer.valueOf(str2);
    }
}