class Solution {
    public int findCenter(int[][] edges) {
        HashSet set = new HashSet<>();
        set.add(edges[0][0]);
        set.add(edges[0][1]);
        for(int i=1; i<edges.length; i++){
            if(set.contains(edges[i][1])){
                return edges[i][1];
            } else {
                return edges[i][0];
            }
        }
        return -1;
    }
}