package internal

/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
func lengthOfLongestSubstring(s string) int {

	m := make(map[rune]int)
	max := 0

	left := 0
	right := 0

	for i, c := range s {
		if j, ok := m[c]; ok && j >= left {
			size := right - left
			if max < size {
				max = size
			}
			left = j + 1
		}
		m[c] = i
		right++
	}
	if right-left > max {
		max = right - left
	}
	return max
}

// @lc code=end
