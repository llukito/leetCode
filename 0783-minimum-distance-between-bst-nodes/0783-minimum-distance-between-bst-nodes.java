/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int minDiffInBST(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();
        fill(list, root);
        Collections.sort(list);
        int res = Integer.MAX_VALUE;
        for(int i=0; i<list.size()-1; i++){
            res = Math.min(res, list.get(i+1)-list.get(i));
        }
        return res;
    }

    private void fill(ArrayList<Integer> list, TreeNode root){
        if(root == null)return;
        list.add(root.val);
        fill(list, root.left);
        fill(list, root.right);
    }
}