/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (37.27%)
 * Total Accepted:    46.8K
 * Total Submissions: 125.4K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 *
 * Given a sorted array, two integers k and x, find the k closest elements to x
 * in the array.  The result should also be sorted in ascending order.
 * If there is a tie,  the smaller elements are always preferred.
 *
 *
 * Example 1:
 *
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 *
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 *
 *
 *
 * Note:
 *
 * The value k is positive and will always be smaller than the length of the
 * sorted array.
 * ⁠Length of the given array is positive and will not exceed 10^4
 * ⁠Absolute value of elements in the array and x will not exceed 10^4
 *
 *
 *
 *
 *
 *
 * UPDATE (2017/9/19):
 * The arr parameter had been changed to an array of integers (instead of a
 * list of integers). Please reload the code definition to get the latest
 * changes.
 *
 */
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> res;
        int left = 0, right = arr.size() - 1;
        if (arr.size() == 0)
            return res;
        if (x < arr.front())
        {
            res.insert(res.end(), arr.begin(), arr.begin() + k);
            return res;
        }
        if (x > arr.back())
        {
            res.insert(res.end(), arr.end() - k - 1, arr.end() - 1);
            return res;
        }
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[left] <= x && x <= arr[mid])
                right = mid;
            else
                left = mid + 1;
        }
    }
};
