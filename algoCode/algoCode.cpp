// algoCode.cpp: 定义应用程序的入口点。
//

#include "algoCode.h"
using namespace std;


int trap(vector<int>&);
int engthOfLongestSubstring(string);
bool checkInclusion(string, string);
string longestCommonPrefix(vector<string>&);
vector<int> twoSum(vector<int>&, int);
string multiply(string, string);
string reverseWords(string);
string simplifyPath(string);


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

	//string s1 = "acb";
	//string s2 = "dcda";

	//bool isExists = checkInclusion(s1, s2);
	//cout << boolalpha << isExists << endl;


	//vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3,  2, 1, 2, 1 };
	//int sum = trap(height);
	//cout << sum << endl;

	//string num1 = "100";
	//string num2 = "100";
	//string sum =multiply(num1, num2);
	//cout << sum << endl;

	string str = "we are the    world!";
	string s = reverseWords(str);
	cout << s << endl;


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


//接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
//按列求
int trap(vector<int>& height) {
	int sum = 0;

	for (int i = 0; i < height.size(); i++)
	{
		int current = height[i];
		int leftHeight = 0;
		int rightHeight = 0;


		//获取当前数字的左右最大值
		for (int n = 0; n < height.size(); n++)
		{
			if (n < i) {
				if (height[n] > leftHeight) {
					leftHeight = height[n];
				}

			}
			else if (n > i) {
				if (height[n] > rightHeight) {
					rightHeight = height[n];
				}
			}

		}
		cout << leftHeight << ":" << current << ":" << rightHeight << endl;
		if (leftHeight > current && rightHeight > current) {
			sum += leftHeight > rightHeight ? rightHeight - current : leftHeight - current;
		}
		cout << sum << "-----" << endl;
	}

	return sum;


}


//字符串的排列
bool checkInclusion(string s1, string s2) {

	if (s1.size() > s2.size()) {
		return false;
	}
	map<char, int>m1;
	map<char, int>m2;
	for (int i = 0; i < s1.size(); i++)
	{
		m1[s1[i]]++;
		m2[s2[i]]++;
	}

	for (int i = s1.size(); i < s2.size(); i++) {
		if (m1 == m2) {
			return true;
		}
		int n = i - s1.size();
		m2[s2[n]]--;
		if (m2[s2[n]] == 0) {
			m2.erase(s2[n]);
		}
		m2[s2[i]]++;
	}

	return m1 == m2 ? true : false;
}


//字符串相乘
string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0") {
		return "0";
	}
	int len1 = num1.size();
	int len2 = num2.size();
	int length = len1 + len2;

	vector<int> sumArray(length, 0);

	for (int i = len1 - 1; i >= 0; i--) {
		for (int n = len2 - 1; n >= 0; n--) {
			int temp = (num1[i] - '0') * (num2[n] - '0');
			//cout<<temp<<endl;
			int index = n + i + 1;
			sumArray[index] += temp;
			if (sumArray[index] >= 10) {
				int b = index - 1;
				sumArray[b] += sumArray[index] / 10;
				sumArray[index] = sumArray[index] % 10;
			}
		}
	}

	string res = "";
	bool isStart = true;
	for (int val : sumArray)
	{
		if (val == 0 && isStart) {
			continue;
		}
		if (val != 0) {
			isStart = false;
		}
		res += (val + '0');

	}
	return res;
}


//翻转字符串里的单词

string reverseWords(string s) {
	vector<string> sList;
	string sp = " ";
	int pos2 = s.find(sp);
	int pos1 = 0;
	while (string::npos != pos2)
	{
		int l = pos2 - pos1;
		string c = s.substr(pos1, l);
		if (c != "") {
			sList.push_back(c);
		}
		pos1 = pos2 + sp.size();
		pos2 = s.find(sp, pos1);
	}
	if (pos1 != s.length()) {
		sList.push_back(s.substr(pos1));
	}
	int num = sList.size() / 2;
	int m = sList.size() - 1;
	for (int i = 0; i < num; i++)
	{
		string temp = sList[i];
		sList[i] = sList[m - i];
		sList[m - i] = temp;
	}

	string res = "";
	int count = sList.size();
	for (int i = 0; i < count; i++)
	{
		if (i == (count - 1)) {

			res += sList[i];
		}
		else
		{

			res += sList[i] + " ";
		}

	}

	return res;

}

//jianhualujing
string simplifyPath(string path) {

	return "";

}


