/**
 * @param {number[]} heights
 * @return {number}
 */
var trap = function(heights) {
    let n = heights.length;
    let preMax = [];
    let sufMax = [];
    preMax[0] = heights[0];
    for (let i = 1; i < n; i++) preMax[i] = Math.max(preMax[i - 1], heights[i]);
    sufMax[n - 1] = heights[n - 1];
    for (let i = n - 2; i >= 0; i--) sufMax[i] = Math.max(sufMax[i + 1], heights[i]);
    let ans = 0;
    for (let i = 1; i < n - 1; i++) {
        let up = Math.min(preMax[i - 1], sufMax[i + 1]);
        let bottom = heights[i];
        if (up > bottom) ans += up - bottom;
    }        
    return ans;
};