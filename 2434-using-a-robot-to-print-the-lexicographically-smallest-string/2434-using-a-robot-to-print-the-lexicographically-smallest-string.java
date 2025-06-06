class Solution {
    public String robotWithString(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        StringBuilder result = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        int min = 0;

        for (char c : s.toCharArray()) {
            freq[c - 'a']--;
            stack.push(c);

            // Update min to the smallest remaining character
            while (min < 26 && freq[min] == 0) {
                min++;
            }

            // Greedily pop from stack if possible
            while (!stack.isEmpty() && stack.peek() <= (char)(min + 'a')) {
                result.append(stack.pop());
            }
        }

        // Flush remaining stack
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }

        return result.toString();
    }
}
