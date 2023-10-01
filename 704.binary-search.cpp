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
        for(int l = 0;i < n, i > 0;) {
            int i = (l+n)/2;
            int x = nums[i];
            if(target == x) return i;
            if( x > target) n = l;
            else i = l
        }
    }
};
// @lc code=end

