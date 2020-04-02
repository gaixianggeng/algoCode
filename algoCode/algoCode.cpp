// algoCode.cpp: 定义应用程序的入口点。
//

#include "algoCode.h"

using namespace std;


int engthOfLongestSubstring(string);

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
