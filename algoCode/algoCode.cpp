// algoCode.cpp: 定义应用程序的入口点。
//

#include "algoCode.h"
#include <vector>
using namespace std;


int engthOfLongestSubstring(string);
string longestCommonPrefix(vector<string>&);
vector<int> twoSum(vector<int>&, int);
//int trap(vector<int>&);
bool checkInclusion(string,string);

int main()
{
	/*string s = "ytuwrqjjkljk";
	int 	longest = engthOfLongestSubstring(s);
	cout << longest << endl;
	*/
//	vector<string> strs = { "test","tes01","t" };
//	string commomStr = longestCommonPrefix(strs);
//	cout << commomStr << endl;

//	vector<int> nums = { 2,3,7,0 };
//	vector<int> res = twoSum(nums, 9);
//	for (int i = res.size() - 1; i >= 0; i--)
//	{
//		cout << res[i] << endl;
//	}

	string s1 = "ab";
	string s2 = "yubsebaoj";
	checkInclusion(s1,s2);


	return 0;
}
//leetcode 1 两数之和
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> indexList;
	if (nums.size() == 0) {
		return indexList;
	}
	map<int, int> sum;
	for (int i = 0; i <= nums.size(); i++)
	{
		if (sum.count(nums[i]) != 0) {
			indexList.push_back(i);
			indexList.push_back(sum[nums[i]]);
			break;
		}

		sum[target - nums[i]] = i;
	}
	return indexList;
}


//leetcode 3 无重复字符的最长子串
//建一个map存储每个字符，endIndex累加
//如key存在的话 跟新longest startIndex同时加一
int engthOfLongestSubstring(string s) {

	int longest = 0;
	int startIndex = 0;
	int endIndex = 0;

	map<char, int>subMap;

	for (int i = 0; i < s.size(); i++)
	{
		//已经存入数据
		if (subMap.count(s[i]) > 0 && subMap[s[i]] >= startIndex) {
			longest = endIndex - startIndex > longest ? endIndex - startIndex : longest;
			startIndex = subMap[s[i]] + 1;
		}
		endIndex++;
		subMap[s[i]] = i;
		//cout << index << endl;

	}

	return endIndex - startIndex > longest ? endIndex - startIndex : longest;

}

//最长公共前缀
//取前两个的最长公共前缀 之后将取得的前缀依次跟后面的比较
string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0) {
		return "";
	}

	string commStr = strs[0];

	int n = commStr.size();
	for (int i = 1; i < strs.size(); i++) {
		if (strs[i].substr(0, n) == commStr) {
			continue;
		}
		else
		{
			while (strs[i].substr(0, n) != commStr.substr(0, n))
			{
				n--;

			}
		}

	}


	return commStr.substr(0, n);
}


////接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
//int trap(vector<int>& height) {
//	return 0;
//
//
//}


//字符串的排列
bool checkInclusion(string s1,string s2){
	cout<<s1<<endl;
	cout<<s2<<endl;

} 
