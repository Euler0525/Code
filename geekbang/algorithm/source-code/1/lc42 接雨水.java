class Solution {
    public int trap(int[] heights) {
        int n = heights.length;
        int[] preMax = new int[n];
        int[] sufMax = new int[n];
        preMax[0] = heights[0];
        for (int i = 1; i < n; i++) preMax[i] = Math.max(preMax[i - 1], heights[i]);
        sufMax[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--) sufMax[i] = Math.max(sufMax[i + 1], heights[i]);
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int up = Math.min(preMax[i - 1], sufMax[i + 1]);
            int bottom = heights[i];
            if (up > bottom) ans += up - bottom;
        }        
        return ans;
    }
}