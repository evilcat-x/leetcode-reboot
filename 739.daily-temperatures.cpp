/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (59.00%)
 * Total Accepted:    51.2K
 * Total Submissions: 86.8K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 *
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 *
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 *
 *
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 *
 */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> temp;
        stack<int> index;
        vector<int> result;
        result.resize(T.size(), 0);
        for(int i = 0, e = T.size(); i < e; i++) {
            while (!temp.empty() && temp.top() < T[i]) {
                int val = temp.top();
                int valIndex = index.top();
                temp.pop();
                index.pop();
                result[valIndex] = i - valIndex;
            }
            temp.push(T[i]);
            index.push(i);
        }
        return result;
    }
};

