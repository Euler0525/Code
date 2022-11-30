/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(nums, target) {
    let h = {};
    for (let i = 0; i < nums.length; i++) {
        if (target - nums[i] in h) {
            return [h[target - nums[i]], i];
        }
        h[nums[i]] = i;
    }
    return [];
};