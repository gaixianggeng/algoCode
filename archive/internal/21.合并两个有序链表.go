/*
 * @lc app=leetcode.cn id=21 lang=golang
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	res := new(ListNode)
	cur := res

	for list1 != nil || list2 != nil {

		if list2 == nil || (list1 != nil && list1.Val <= list2.Val) {
			cur.Next = list1
			list1 = list1.Next
		} else if list1 == nil || (list2 != nil && list2.Val <= list1.Val) {
			cur.Next = list2
			list2 = list2.Next
		}
		cur = cur.Next
	}
	return res.Next
}

// @lc code=end

