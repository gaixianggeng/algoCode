#include "algoString.h"
#include "unionFind.cpp"

//leetcode 1 两数之和
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> indexList;
	if (nums.size() == 0)
	{
		return indexList;
	}
	map<int, int> sum;
	for (int i = 0; i <= nums.size(); i++)
	{
		if (sum.count(nums[i]) != 0)
		{
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
int engthOfLongestSubstring(string s)
{

	int longest = 0;
	int startIndex = 0;
	int endIndex = 0;

	map<char, int> subMap;

	for (int i = 0; i < s.size(); i++)
	{
		//已经存入数据
		if (subMap.count(s[i]) > 0 && subMap[s[i]] >= startIndex)
		{
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
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0)
	{
		return "";
	}

	string commStr = strs[0];

	int n = commStr.size();
	for (int i = 1; i < strs.size(); i++)
	{
		if (strs[i].substr(0, n) == commStr)
		{
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
int trap(vector<int>& height)
{
	int sum = 0;

	for (int i = 0; i < height.size(); i++)
	{
		int current = height[i];
		int leftHeight = 0;
		int rightHeight = 0;

		//获取当前数字的左右最大值
		for (int n = 0; n < height.size(); n++)
		{
			if (n < i)
			{
				if (height[n] > leftHeight)
				{
					leftHeight = height[n];
				}
			}
			else if (n > i)
			{
				if (height[n] > rightHeight)
				{
					rightHeight = height[n];
				}
			}
		}
		cout << leftHeight << ":" << current << ":" << rightHeight << endl;
		if (leftHeight > current && rightHeight > current)
		{
			sum += leftHeight > rightHeight ? rightHeight - current : leftHeight - current;
		}
		cout << sum << "-----" << endl;
	}

	return sum;
}

//字符串的排列
bool checkInclusion(string s1, string s2)
{

	if (s1.size() > s2.size())
	{
		return false;
	}
	map<char, int> m1;
	map<char, int> m2;
	for (int i = 0; i < s1.size(); i++)
	{
		m1[s1[i]]++;
		m2[s2[i]]++;
	}

	for (int i = s1.size(); i < s2.size(); i++)
	{
		if (m1 == m2)
		{
			return true;
		}
		int n = i - s1.size();
		m2[s2[n]]--;
		if (m2[s2[n]] == 0)
		{
			m2.erase(s2[n]);
		}
		m2[s2[i]]++;
	}

	return m1 == m2 ? true : false;
}

//字符串相乘
string multiply(string num1, string num2)
{
	if (num1 == "0" || num2 == "0")
	{
		return "0";
	}
	int len1 = num1.size();
	int len2 = num2.size();
	int length = len1 + len2;

	vector<int> sumArray(length, 0);

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int n = len2 - 1; n >= 0; n--)
		{
			int temp = (num1[i] - '0') * (num2[n] - '0');
			//cout<<temp<<endl;
			int index = n + i + 1;
			sumArray[index] += temp;
			if (sumArray[index] >= 10)
			{
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
		if (val == 0 && isStart)
		{
			continue;
		}
		if (val != 0)
		{
			isStart = false;
		}
		res += (val + '0');
	}
	return res;
}

//翻转字符串里的单词

string reverseWords(string s)
{
	vector<string> sList;
	string sp = " ";
	int pos2 = s.find(sp);
	int pos1 = 0;
	while (string::npos != pos2)
	{
		int l = pos2 - pos1;
		string c = s.substr(pos1, l);
		if (c != "")
		{
			sList.push_back(c);
		}
		pos1 = pos2 + sp.size();
		pos2 = s.find(sp, pos1);
	}
	if (pos1 != s.length())
	{
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
		if (i == (count - 1))
		{

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
string simplifyPath(string path)
{
	string sub = "/";
	vector<string> pathList;
	int pos1 = path.find(sub);
	int pos2 = 0;
	while (string::npos != pos1)
	{
		int t = pos1 - pos2;
		string c = path.substr(pos2, t);
		if (c == ".." && pathList.size() >= 1)
		{
			pathList.pop_back();
		}
		else if (c != "" && c != "." && c != "..")
		{
			pathList.push_back(c);
		}
		pos2 = pos1 + sub.size();
		pos1 = path.find(sub, pos2);
	}
	if (pos2 != path.size())
	{
		string c = path.substr(pos2);
		if (c == ".." && pathList.size() >= 1)
		{
			pathList.pop_back();
		}
		else if (c != "" && c != "." && c != "..")
		{
			pathList.push_back(c);
		}
	}
	string fPath = "/";
	for (int i = 0; i < pathList.size(); i++)
	{
		if (i == pathList.size() - 1)
		{
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
vector<string> restoreIpAddresses(string s)
{
	s = "010010";
	cout << s << endl;
	vector<string> ipList;
	if (s.size() > 12 || s.size() < 4)
	{
		return ipList;
	}
	for (int i = 1; i <= 3; i++)
	{
		for (int j = i + 1; j <= i + 3; j++)
		{
			for (int m = j + 1; m <= j + 3; m++)
			{
				if (j >= s.size() || m >= s.size())
				{
					continue;
				}
				string a = s.substr(0, i);
				string b = s.substr(i, j - i);
				string c = s.substr(j, m - j);
				string d = s.substr(m);
				if (a.size() <= 3 && b.size() <= 3 && c.size() <= 3 && d.size() <= 3)
				{
					int an = stoi(a);
					int bn = stoi(b);
					int cn = stoi(c);
					int dn = stoi(d);
					if (an <= 255 && bn <= 255 && cn <= 255 && dn <= 255)
					{
						if ((an > 0 && a[0] == '0') || (bn > 0 && b[0] == '0') || (cn > 0 && c[0] == '0') || (dn > 0 && d[0] == '0'))
						{
							continue;
						}
						if ((an == 0 && a.size() > 1) || (bn == 0 && b.size() > 1) || (cn == 0 && c.size() > 1) || (dn == 0 && d.size() > 1))
						{
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
vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> sumList;

	sort(nums.begin(), nums.end());
	for	each (int val in nums)
	{
		cout << val;
	}
	cout << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int target = nums[i];

		if (target > 0)
		{
			break;
		}
		int l = i + 1;
		int r = nums.size() - 1;

		while (l < r)
		{
			int t = target + nums[l] + nums[r];
			if (t > 0)
			{
				--r;
			}
			else if (t < 0)
			{
				++l;
			}
			else
			{
				vector<int> a = { nums[l], nums[r], target };
				sumList.push_back(a);
				--r;
				++l;
				while (l < r && nums[l] == nums[l - 1])
				{
					++l;
				}
				while (l < r && nums[r] == nums[r + 1])
				{
					--r;
				}
			}
		}
	}

	return sumList;
}

//695 岛屿最大面积
int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();
	int maxArea = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1)
			{
				cout << i << j << m << n << endl;
				int count = dfs(grid, m, n, j, i);
				cout << count << endl;
				maxArea = max(count, maxArea);
			}
		}
	}
	return maxArea;
}

int dfs(vector<vector<int>>& grid, int m, int n, int j, int i)
{
	if (j >= n || i >= m || i < 0 || j < 0 || grid[i][j] != 1)
	{
		return 0;
	}
	int count = 1;
	grid[i][j] = 2;
	count += dfs(grid, m, n, j + 1, i);
	count += dfs(grid, m, n, j - 1, i);
	count += dfs(grid, m, n, j, i + 1);
	count += dfs(grid, m, n, j, i - 1);
	return count;
}

int search(vector<int>& nums, int target)
{
	target = 3;
	nums = { 1, 3 };
	if (nums.size() == 0)
	{
		return -1;
	}
	int l = 0;
	int r = nums.size() - 1;
	while (l <= r)
	{
		int m = (r + l) / 2;
		if (target == nums[m])
		{
			return m;
		}
		if (nums[m] < nums[r])
		{
			if (nums[m] <= target && target <= nums[r])
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
		else
		{
			if (target >= nums[l] && target <= nums[m])
			{
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
	}
	return -1;
}

//快排
void quickSoort(vector<int>& nums, int s, int e)
{
	if (s >= e) {
		return;
	}
	int temp = nums[s];
	int i = s;
	int j = e;
	while (i < j)
	{
		//添加i<j 是为了防止出现最后i>j的情况
		if (nums[j] >= temp && i < j)
		{
			j--;
		}
		if (nums[i] <= temp && i < j)
		{
			i++;
		}
		if (i < j && nums[i] > temp && nums[j] < temp)
		{
			cout << nums[i] << ":" << nums[j] << endl;
			swap(nums[i], nums[j]);
		}
	}
	cout << i << j << endl;
	swap(nums[s], nums[i]);
	quickSort(nums, s, i - 1);
	quickSort(nums, i + 1, e);

}
//快排 网上答案
void quickSort(vector<int>& arr, int left, int right)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	cout << i << "--" << j << endl;
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(arr, left, i - 1);//递归左边
	quickSort(arr, i + 1, right);//递归右边
}

//获取第k大数据
int	quickSortK(vector<int>& nums, int k) {

	int s = nums.size() - k;
	position(nums, 0, nums.size() - 1, s);

	return nums[s];
}

//快速排序
void position(vector<int>& arr, int left, int right, int k) {
	if (left >= right) {
		return;
	}
	int s = left;
	int e = right;
	int temp = arr[left];
	while (s < e)
	{
		while (arr[e] >= temp && s < e)
		{
			e--;
		}
		while (arr[s] <= temp && s < e)
		{
			s++;
		}
		if (s < e) {
			swap(arr[s], arr[e]);
		}
	}
	swap(arr[left], arr[s]);
	cout << "s:" << s << "e:" << e << endl;
	for each (int val in arr)
	{
		cout << val << " ";
	}
	cout << endl;
	if (s == k) {
		return;
	}
	if (s > k) {

		position(arr, 0, s - 1, k);

	}
	if (s < k) {

		position(arr, s + 1, right, k);
	}


}


//最长连续序列
//通过map 遍历nums。假定每个item都是第一个 判断+1或-1是否存在map里面，存在的话 更新长度。最后取最大值。
//思路没错 超时 要求时间复杂度为n
int longestConsecutive(vector<int>& nums) {
	map<int, int> nMap;
	int longest = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nMap.find(nums[i]) == nMap.end()) {
			nMap[nums[i]] = 1;
		}
	}

	for (int i = 0; i < nums.size(); i++) {
		int l = 1;
		int temp = nums[i];
		//这个if判断是控制时间复杂度的关键 假设取到的都是最小的
		if (nMap.find(temp - 1) == nMap.end()) {
			while (nMap.find(temp + 1) != nMap.end())
			{
				l++;
				temp++;
			}

		}
		/*	temp = nums[i];
	while (nMap.find(temp + 1) != nMap.end())
	{
		l += nMap[temp + 1];
		temp++;
	}*/
		longest = max(longest, l);

	}
	return longest;
}


//第k个排列
//初步想法 递归 依次确定
//先实现n个数字依次打印 再找对应k的数字
string getPermutation(int n, int k) {
	int* nums = new int[n];
	map<int, int> numMap;
	for (int i = 0; i < n; i++)
	{
		nums[i] = i + 1;
	}
	string s = "";
	permutation(n, k, nums, s);
	return s;

}

void permutation(int n, int k, int* nums, string& s) {
	if (n == 0) {
		return;
	}
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			s += to_string(nums[i]);
		}
		return;
	}
	int sum = 1;
	for (int i = 1; i < n; i++) {
		sum *= i;
	}
	int current = k / sum + 1;
	if (k % sum == 0) {
		current = current - 1;
	}
	s += to_string(nums[current - 1]);
	deleteItem(nums, n - 1, current - 1);
	int beLeft = k - sum * (current - 1);
	permutation(n - 1, beLeft, nums, s);
}


void deleteItem(int* nums, int l, int index) {
	while (index < l) {
		nums[index] = nums[index + 1];
		index++;
	}
}

//朋友圈
int findCircleNum(vector<vector<int>>& M) {
	int m = M.size();
	int n = M[0].size();
	UF* uf = new UF(m);
	for (int i = 0; i < m; i++)
	{
		for (int j =i+1; j < n; j++)
		{
			if (M[i][j] == 1) {
				uf->Union(i, j);
			}

		}

	}
	return uf->Count();
}

//靠靠
vector<vector<int>> merge(vector<vector<int>>& intervals){

	return intervals;
}
