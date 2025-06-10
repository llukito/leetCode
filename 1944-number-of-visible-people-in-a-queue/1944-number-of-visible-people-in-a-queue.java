class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        Deque<Integer> stack = new ArrayDeque<>();
        int[] array = new int[heights.length];
        Arrays.fill(array, 0);
        for(int i=heights.length-1; i>=0; i--){
            int count = 0;
            while(stack.size()!=0 && heights[i]>stack.peek()){
                count++;
                stack.pop();
            }   
            if(stack.size()!=0 )count++;
            array[i] = count;
            stack.push(heights[i]);
        }
        return array;
    }
}