/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.01%)
 * Total Accepted:    270.9K
 * Total Submissions: 820.3K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */
class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result;
        int mid = searchMid(nums, target);
        if (mid == -1)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int left = searchLeft(nums, target, 0, mid);
        int right = searchRight(nums, target, mid, nums.size() - 1);
        cout << left << " " << right << endl;
        result.push_back(left);
        result.push_back(right);
        return result;
    }
    int searchRight(vector<int> &nums, int target, int left, int right)
    {
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        if (nums[right] == target)
            return right;
        if (nums[left] == target)
            return left;
        return -1;
    }
    int searchLeft(vector<int> &nums, int target, int left, int right)
    {
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        if (nums[left] == target)
            return left;
        if (nums[right] == target)
            return right;
        return -1;
    }
    int searchMid(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right)
        {
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        // Post-processing:
        // End Condition: left + 1 == right
        if (nums[left] == target)
            return left;
        if (nums[right] == target)
            return right;
        return -1;
    }
};
