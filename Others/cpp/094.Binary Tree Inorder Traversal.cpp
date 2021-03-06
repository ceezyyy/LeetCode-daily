﻿/**
 * Source: LeetCode  094. Binary Tree Inorder Traversal
 * Author: ceezyyy
 * Date: 10-04-2019
 */


 /*
 Medium

 Given a binary tree, return the inorder traversal of its nodes' values.

 Example:

 Input: [1,null,2,3]
	1
	 \
	  2
	 /
	3

 Output: [1,3,2]

 Follow up: Recursive solution is trivial, could you do it iteratively?

 */


#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// inorderTraversal_Recursion
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	vector<int> res;
	vector<int> inorderTraversal(TreeNode* root) {
		inorderTraversal_Recursion(root);
		return res;
	}

	void inorderTraversal_Recursion(TreeNode *node) {
		if (node)
		{
			if (node->left) {
				inorderTraversal_Recursion(node->left);
			}
			res.push_back(node->val);
			if (node->right) {
				inorderTraversal_Recursion(node->right);
			}
		}
	}
};

/**
 * Runtime: 4 ms, faster than 59.48% of C++ online submissions for Binary Tree Inorder Traversal.
 * Memory Usage: 9.5 MB, less than 33.00% of C++ online submissions for Binary Tree Inorder Traversal.
 */


// inorderTraversal_Iteration
class Solution {
public:
	vector<int> res;
	stack<TreeNode*> stk;
	vector<int> inorderTraversal(TreeNode *root) {
		// empty tree
		if (!root)
			return res;
		TreeNode *node = root;
		// from the left side
		while (!stk.empty() || node) {
			// from the left side
			while (node) {
				stk.push(node);
				node = node->left;
			}
			if (!stk.empty()) {
				node = stk.top();
				stk.pop();
				res.push_back(node->val);
				node = node->right;
			}
		}
		return res;
	}
};


/**
 * Runtime: 4 ms, faster than 59.31% of C++ online submissions for Binary Tree Inorder Traversal.
 * Memory Usage: 9 MB, less than 98.00% of C++ online submissions for Binary Tree Inorder Traversal.
 */
