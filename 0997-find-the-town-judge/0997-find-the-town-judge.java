class Solution {
    public int findJudge(int n, int[][] trust) {
        HashMap<Integer, Set<Integer>> map = new HashMap<>();
        for(int i=0; i<trust.length; i++){
            if(map.containsKey(trust[i][0])){
                Set<Integer> st = map.get(trust[i][0]);
                st.add(trust[i][1]);
                map.put(trust[i][0], st);
            } else {
                Set<Integer> st = new HashSet<>(); st.add(trust[i][1]);
                map.put(trust[i][0], st);
            }
        }
        for(int i=1; i<=n; i++){
            if(!map.containsKey(i)){
                Set<Integer> st = new HashSet<>();
                map.put(i, st);
            }
        }
        // if(map.size()==0 && n!=1)return -1;
        for(int i=1; i<=n; i++){
            if(map.get(i).size()==0 && trusted(i, map)){
                return i;
            }
        }
        return -1;
    }

    private boolean trusted(int i, HashMap<Integer, Set<Integer>> map){
        for(Integer n : map.keySet()){
            if(n==i)continue;
            if(!map.get(n).contains(i)){
                return false;
            }
        }
        return true;
    }
}