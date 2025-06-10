class Solution {
    public int maxDifference(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        for(char ch : s.toCharArray()){
            if(!mp.containsKey(ch)){
                mp.put(ch, 1);
            } else {
                mp.put(ch, mp.get(ch)+1);
            }
        }
        int a = 0; int b = Integer.MAX_VALUE;
        for(Integer n :mp.values()){
            if(n%2==1){
                a = Math.max(a, n);
            } else {
                b = Math.min(b, n);
            }
        }
        return a-b;
    }
}