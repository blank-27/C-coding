/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i = 0;i < n;i++) {
            int x = nums[i];
            if(target == x) return i;
        }
    }
};
// @lc code=end

