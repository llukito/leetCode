class Solution {
    private static final int MOD = 1000000007;
    public int concatenatedBinary(int n) {
        StringBuilder b = new StringBuilder();
        for(int i = 1; i <= n; i++){
            String curr = Integer.toBinaryString(i);
            b.append(curr);
            Long currLong = Long.parseLong(b.toString(), 2);
            currLong%=MOD;
            b.setLength(0); b.append(Long.toBinaryString(currLong));
        }
        return Integer.parseInt(b.toString(), 2);
    }
}
