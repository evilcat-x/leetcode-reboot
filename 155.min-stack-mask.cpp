/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (35.62%)
 * Total Accepted:    269.2K
 * Total Submissions: 755.6K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 *
 *
 * pop() -- Removes the element on top of the stack.
 *
 *
 * top() -- Get the top element.
 *
 *
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 */
#include <stack>
#include <climits>
using namespace std;

class MinStack {
private:
    stack<int> s;
	int minVal;
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if(s.empty()) {
			minVal = x;
        } else if (x <= minVal) {
			s.push(minVal);
			minVal = x;
		}
		s.push(x);
    }

    void pop() {
        if (s.top() == minVal) {
			s.pop();
			if (s.empty())
				return;
			minVal = s.top();
		}
		s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

