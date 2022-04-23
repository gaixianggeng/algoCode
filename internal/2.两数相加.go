package internal

/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	cur := new(ListNode)
	res := cur

	needPlus := 0
	for l1 != nil || l2 != nil {
		var v1, v2 int
		if l1 != nil {
			v1 = l1.Val
		}
		if l2 != nil {
			v2 = l2.Val
		}

		cur.Val = v1 + v2 + needPlus
		if cur.Val >= 10 {
			cur.Val -= 10
			needPlus = 1
		} else {
			needPlus = 0
		}

		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}
		if l1 == nil && l2 == nil {
			break
		}
		cur.Next = new(ListNode)
		cur = cur.Next
	}
	if needPlus == 1 {
		cur.Next = new(ListNode)
		cur = cur.Next
		cur.Val = 1
	}

	return res

}

// @lc code=end
