/*
 * @lc app=leetcode.cn id=206 lang=golang
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 * o(n) o(1)
 */
func reverseList(head *ListNode) *ListNode {

	var cur *ListNode
	pre := head

	for pre != nil {
		t := pre.Next
		pre.Next = cur

		cur = pre
		pre = t
	}
	return cur
}

// @lc code=end

