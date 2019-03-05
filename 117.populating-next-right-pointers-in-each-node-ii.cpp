/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (33.49%)
 * Total Accepted:    170.4K
 * Total Submissions: 508.5K
 * Testcase Example:  '{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}'
 *
 * Given a binary tree
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 *
 *
 * Example:
 *
 *
 *
 *
 * Input:
 * {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
 *
 * Output:
 * {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}
 *
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B.
 *
 *
 *
 *
 * Note:
 *
 *
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 *
 */

// Definition for a Node.
#include <queue>
using namespace std;

class Node
{
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution
{
  public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Node *c = q.front();
                q.pop();
                c->next = size ? q.front() : nullptr;
                if (c->left)
                    q.push(c->left);
                if (c->right)
                    q.push(c->right);
            }
        }
        return root;
    }
};
