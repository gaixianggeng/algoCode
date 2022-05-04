/*
 * @lc app=leetcode.cn id=20 lang=golang
 *
 * [20] 有效的括号
 * o(n) o(n)
 */

// @lc code=start

func isValid(s string) bool {

	sMap := make(map[byte]byte, 3)

	sMap[')'] = '('
	sMap['}'] = '{'
	sMap[']'] = '['

	size := len(s)
	if size%2 != 0 {
		return false
	}

	m := make([]byte, 0)
	for i := 0; i < size; i++ {
		if len(m) > 0 && sMap[s[i]] == m[len(m)-1] {
			m = m[:len(m)-1]
		} else {
			m = append(m, s[i])
		}
	}
	if len(m) == 0 {
		return true
	}

	return false
}

// @lc code=end

