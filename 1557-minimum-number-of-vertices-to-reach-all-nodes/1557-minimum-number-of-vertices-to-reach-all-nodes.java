class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        List<Integer> list = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        for(List<Integer> l : edges){
            set.add(l.get(1));
        }
        for(int i=0; i<n; i++){
            if(!set.contains(i)){
                list.add(i);
            }
        }
        return list;
    }
}