// algoCode.cpp: 定义应用程序的入口点。
//

#include "algoCode.h"

using namespace std;


int engthOfLongestSubstring(string);
string longestCommonPrefix(vector<string>&);
int trap(vector<int>&);

int main()
{
	/*string s = "ytuwrqjjkljk";
	int 	longest = engthOfLongestSubstring(s);
	cout << longest << endl;
	*/
	//vector<string> strs = { "test","tes01","test02" };
	//
	//string commomStr = longestCommonPrefix(strs);
	//cout << commomStr << endl;


	
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
string longestCommonPreix(vector<string>& strs){

	string commStr = "";
	for (int i = 0; i < strs[0].size(); i++)
	{
		if (strs[0][i] == strs[1][i]){
			commStr += strs[0][i];
		}
	}

	return commStr;
}


//接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
int trap(vector<int>& height) {

}
