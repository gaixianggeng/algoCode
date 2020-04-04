// algoCode.cpp: 定义应用程序的入口点。
//

#include "algoCode.h"

using namespace std;


int engthOfLongestSubstring(string);
int longestCommonPrefix(vector<string>);

int main()
{
	string s = "ytuwrqjjkljk";
	int 	longest = engthOfLongestSubstring(s);
	cout << "test" << endl;
	cout << longest << endl;
	return 0;
}

//leetcode 3 无重复字符的最长子串
int engthOfLongestSubstring(string s) {

	int longest = 0;
	int startIndex = 0;
	int endIndex = 0;

	map<char, int>subMap;

	for (int i=0;i< s.size();i++)
	{
		//已经存入数据
		if (subMap.count(s[i]) > 0 && subMap[s[i]] >= startIndex) {
			longest = endIndex - startIndex > longest ? endIndex - startIndex : longest;
			startIndex = subMap[s[i]]+1;
		}
		endIndex++;
		subMap[s[i]] = i;
		//cout << index << endl;

	}

	return endIndex - startIndex > longest ? endIndex - startIndex : longest;

}

//最长公共前缀
int longestCommonPreix(vector<string>& strs){

}

ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQC0aLjO7Kz8ZXK5SxcROURbcvTC6awo2/7pncNdUyxwSCi58elGX5faNmExZ4qOmpSaEJw8VGsN4uLJ7QCe8ad24U8XAVdGssHchgN1/c5rhB5nfJrY2t8uh8vlOC9be6gcn+Rij/WL+MNhIDbRm013qpsZUnJwgeIYzvWHiE+vyzRzCASy7geHMzs+I8G/tt8VcD1Q26sddx/8QWYmvKsNmSHoKdGYGjJmbjBts92qOMEfUlJOXVERawglQYcFjl18ZUXfkkDJiErDsiP0yP89YKVE8GZm7BkatrztQrSkAuMaTfMwDpL/Iz0GYDB/aa4A2oMreMn7w82LAleg6va7 gai@linux