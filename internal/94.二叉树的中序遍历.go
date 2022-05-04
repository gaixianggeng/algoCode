/*
 * @lc app=leetcode.cn id=94 lang=golang
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	res := make([]int, 0)
	left := inorderTraversal(root.Left)
	if left != nil {
		res = append(res, left...)
	}
	res = append(res, root.Val)
	right := inorderTraversal(root.Right)
	if right != nil {
		res = append(res, right...)
	}
	return res
}

// @lc code=end

