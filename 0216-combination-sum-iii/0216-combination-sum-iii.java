class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        check(result, curr, k, n, 0);
        return result;
    }

    private void check(List<List<Integer>> result,List<Integer> curr, int k, int n, int sum){
        if(sum == n && curr.size()==k){
            Collections.sort(curr);
            if(result.contains(curr))return;
            result.add(new ArrayList<>(curr));
            return;
        }
        for(int i=1; i<=9; i++){
            if(sum+i <= n && curr.size()<k && !curr.contains(i)){
                curr.add(i);
                check(result, curr, k, n, sum+i);
                curr.remove(Integer.valueOf(i));
            }
        }
    }
}