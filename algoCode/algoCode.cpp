// algoCode.cpp: 定义应用程序的入口点。
//

#include "algoCode.h"
#include "algoString.h"

using namespace std;



int main()
{
	/*string s = "ytuwrqjjkljk";
	  int	longest = engthOfLongestSubstring(s);
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

	  //string str = "we are the    world!";
	  //string s = reverseWords(str);
	  //cout << s << endl;


	  //string	path = "/home/a//../";
	  //string sPath = simplifyPath(path);
	  //cout << sPath << endl;


	  //string ipStr = "1234";
	  //vector<string> ipList = restoreIpAddresses(ipStr);
	  //for each (string ip in ipList)
	  //{
	  //	cout << ip << endl;
	  //}

	  //vector<int> nums = { -1,0,1,2,-1,-4};
	//vector<int> nums = { -2,0,1,1,1,1,2 };
	//vector<vector<int>> sumList = threeSum(nums);
	//for each (vector<int> value in sumList)
	//{
	//	for each (int val in value)
	//	{
	//		cout << val;
	//	}
	//	cout << endl;
	//}

	//vector<vector<int>> grid = { {1, 0, 1}, { 1, 1, 0 } };
	//int maxArea = maxAreaOfIsland(grid);
	//cout << maxArea << endl;
	//
	//vector<int> nums = { 4,5,6,7,0,1,2 };
	//int index = search(nums, 0);
	//cout << index << endl;


	//快排
	//vector<int> nums = {3,2,3,1,2,4,5,5,6 };
	//for each (int val in nums)
	//{
	//	cout << val <<" ";
	//}
	//cout << endl;
	//int i = 4;
	//cout << i << endl;
	////quickSort(nums,0,nums.size()-1);
	//int n = quickSortK(nums,i);
	//cout << n << endl;
	//for each (int val in nums)
	//{
	//	cout << val <<" ";
	//}
	//cout << endl;

	vector<int> nums = { 2,3,5,8,34,56,4,90,7,6 };
	int length = longestConsecutive(nums);
	cout << length << endl;
	return 0;

}

