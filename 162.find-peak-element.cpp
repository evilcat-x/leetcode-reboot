/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (40.76%)
 * Total Accepted:    219.4K
 * Total Submissions: 538.2K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2,
 * or index number 5 where the peak element is 6.
 *
 *
 * Note:
 *
 * Your solution should be in logarithmic complexity.
 *
 */
#include <vector>
using namespace std;

class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return 0;

        int left = 0, right = nums.size();
        while (left < right)
        {
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if (isPeak(nums, mid))
                return mid;
            if (isAscending(nums, mid))
                left = mid + 1;
            else
                right = mid;
        }

        // Post-processing:
        // End Condition: left == right
        if (isPeak(nums, left))
            return left;
        return -1;
    }
    bool isPeak(vector<int> &nums, int mid)
    {
        if (mid == nums.size() - 1)
            return nums[mid - 1] < nums[mid];
        if (mid == 0)
            return nums[mid] > nums[mid + 1];
        return nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1];
    }
    bool isAscending(vector<int> &nums, int index)
    {
        if (index == nums.size() - 1)
            return false;
        if (index == 0)
            return nums[index] < nums[index + 1];
        return nums[index - 1] < nums[index] && nums[index] < nums[index + 1];
    }
};
