package internal

/*
 * @lc app=leetcode.cn id=23 lang=golang
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

type LoserTree struct {
	tree   []int // 索引表示顺序，0表示最小值，value表示对应的leaves的index
	leaves []*ListNode
}

func NewLoserTreee(leaves []*ListNode) *LoserTree {
	k := len(leaves)
	lt := &LoserTree{
		tree:   make([]int, k),
		leaves: leaves,
	}
	if k > 0 {
		lt.initWinner(0)
	}
	return lt
}

// 整体逻辑 输的留下来，赢的向上比
// 获取最小值的索引
func (lt *LoserTree) initWinner(idx int) int {
	// 根节点有一个父节点，存储最小值。
	if idx == 0 {
		lt.tree[0] = lt.initWinner(1)
		return lt.tree[0]
	}
	if idx >= len(lt.tree) {
		return idx - len(lt.tree)
	}

	left := lt.initWinner(idx * 2)
	right := lt.initWinner(idx*2 + 1)

	// // 为空的添加一个最大值
	if lt.leaves[left] != nil && lt.leaves[right] == nil {
		left, right = right, left

	}
	if lt.leaves[left] != nil && lt.leaves[right] != nil && (lt.leaves[left].Val < lt.leaves[right].Val) {
		left, right = right, left
	}

	// 左边的节点比右边的节点大
	// 记录败者 即 记录较大的节点索引 较小的继续向上比较
	lt.tree[idx] = left
	return right
}

func (lt *LoserTree) Pop() *ListNode {
	if len(lt.tree) == 0 {
		return nil
	}

	// 取出最小的索引
	leafWinIdx := lt.tree[0]
	// 找到对应叶子节点
	winner := lt.leaves[leafWinIdx]

	// 更新对应index里节点的值
	if winner == nil {
		lt.leaves[leafWinIdx] = nil
	} else {
		lt.leaves[leafWinIdx] = winner.Next
	}

	// 获取父节点
	treeIdx := (leafWinIdx + len(lt.tree)) / 2

	for treeIdx != 0 {
		// 如果第二小的节点比新取出的叶子节点的值小，则互换位置
		loserLeafIdx := lt.tree[treeIdx]
		if lt.leaves[loserLeafIdx] == nil {
			lt.tree[treeIdx] = loserLeafIdx
		} else {
			if lt.leaves[leafWinIdx] == nil {
				loserLeafIdx, leafWinIdx = leafWinIdx, loserLeafIdx
			} else if lt.leaves[loserLeafIdx].Val <
				lt.leaves[leafWinIdx].Val {
				loserLeafIdx, leafWinIdx = leafWinIdx, loserLeafIdx
			}
			// 更新
			lt.tree[treeIdx] = loserLeafIdx
		}
		treeIdx /= 2
	}
	lt.tree[0] = leafWinIdx
	return winner
}

func mergeKLists(lists []*ListNode) *ListNode {
	var dummy = &ListNode{}
	pre := dummy

	lt := NewLoserTreee(lists)

	for {
		node := lt.Pop()

		if node == nil {
			break
		}
		pre.Next = node
		pre = node
	}
	return dummy.Next
}
