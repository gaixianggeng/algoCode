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
vector<string> restoreIpAddresses(string);
vector<vector<int>> threeSum(vector<int>&);
int maxAreaOfIsland(vector<vector<int>>&);
int dfs(vector<vector<int>>&, int, int, int, int);



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

	vector<vector<int>> grid = { {1, 0, 1}, { 1, 1, 0 } };
	int maxArea = maxAreaOfIsland(grid);
	cout << maxArea << endl;
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

//简化路径 直接字符串分割 拼接字符串
string simplifyPath(string path) {
	string sub = "/";
	vector<string> pathList;
	int pos1 = path.find(sub);
	int pos2 = 0;
	while (string::npos != pos1) {
		int t = pos1 - pos2;
		string c = path.substr(pos2, t);
		if (c == ".." && pathList.size() >= 1) {
			pathList.pop_back();
		}
		else if (c != "" && c != "." && c != "..") {
			pathList.push_back(c);
		}
		pos2 = pos1 + sub.size();
		pos1 = path.find(sub, pos2);
	}
	if (pos2 != path.size()) {
		string c = path.substr(pos2);
		if (c == ".." && pathList.size() >= 1) {
			pathList.pop_back();
		}
		else if (c != "" && c != "." && c != "..") {
			pathList.push_back(c);
		}

	}
	string fPath = "/";
	for (int i = 0; i < pathList.size(); i++)
	{
		if (i == pathList.size() - 1) {
			fPath += pathList[i];
		}
		else
		{
			fPath += pathList[i] + "/";
		}
	}
	return fPath;

}

//93 复原ip地址
vector<string> restoreIpAddresses(string s) {
	s = "010010";
	cout << s << endl;
	vector<string> ipList;
	if (s.size() > 12 || s.size() < 4) {
		return ipList;
	}
	for (int i = 1; i <= 3; i++)
	{
		for (int j = i + 1; j <= i + 3; j++)
		{
			for (int m = j + 1; m <= j + 3; m++)
			{
				if (j >= s.size() || m >= s.size()) {
					continue;
				}
				string a = s.substr(0, i);
				string b = s.substr(i, j - i);
				string c = s.substr(j, m - j);
				string d = s.substr(m);
				if (a.size() <= 3 && b.size() <= 3 && c.size() <= 3 && d.size() <= 3) {
					int an = stoi(a);
					int bn = stoi(b);
					int cn = stoi(c);
					int dn = stoi(d);
					if (an <= 255 && bn <= 255 && cn <= 255 && dn <= 255) {
						if ((an > 0 && a[0] == '0') || (bn > 0 && b[0] == '0') || (cn > 0 && c[0] == '0') || (dn > 0 && d[0] == '0')) {
							continue;
						}
						if ((an == 0 && a.size() > 1) || (bn == 0 && b.size() > 1) || (cn == 0 && c.size() > 1) || (dn == 0 && d.size() > 1)) {
							continue;
						}
						string ip = a + "." + b + "." + c + "." + d;
						ipList.push_back(ip);

					}

				}
			}

		}
	}
	return ipList;
}


//15三数之和
//两数之和的思路套在这里 需要去重  所以采用左右标尺方式
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> sumList;

	sort(nums.begin(), nums.end());
	for each (int val in nums)
	{
		cout << val;

	}
	cout << endl;
	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		int target = nums[i];

		if (target > 0) {
			break;
		}
		int l = i + 1;
		int r = nums.size() - 1;

		while (l < r) {
			int t = target + nums[l] + nums[r];
			if (t > 0) {
				--r;
			}
			else if (t < 0) {
				++l;
			}
			else {
				vector<int> a = { nums[l],nums[r],target };
				sumList.push_back(a);
				--r;
				++l;
				while (l < r && nums[l] == nums[l - 1]) {
					++l;
				}
				while (l < r && nums[r] == nums[r + 1]) {
					--r;
				}
			}

		}
	}

	return sumList;
}

//695 岛屿最大面积

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	int maxArea = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				cout << i << j <<m<<n<< endl;
				int count = dfs(grid, m, n, j, i);
				cout << count << endl;
				maxArea = max(count, maxArea);

			}
		}
	}
	return maxArea;
}

int dfs(vector<vector<int>>& grid, int m, int n, int j, int i) {
	if (j >= n || i >= m || i < 0 || j < 0 || grid[i][j] != 1 ) {
		return 0;
	}
	int count = 1;
	grid[i][j] = 2;
	count += dfs(grid, m, n, j + 1, i);
	count += dfs(grid, m, n, j - 1, i);
	count += dfs(grid, m, n, j, i + 1);
	count += dfs(grid, m, n, j , i - 1);
	return count;
}


