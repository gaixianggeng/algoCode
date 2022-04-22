#include "algoCode.h"
#include "unionFind.cpp"

//15三数之和
//两数之和的思路套在这里 需要去重  所以采用左右标尺方式
vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> sumList;

	sort(nums.begin(), nums.end());
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
		for (int j = i + 1; j < n; j++)
		{
			if (M[i][j] == 1) {
				uf->Union(i, j);
			}

		}

	}
	return uf->Count();
}

//合并区间
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> merged;

	sort(intervals.begin(),intervals.end());

	for (int i = 0; i < intervals.size(); i++)
	{
		if (!merged.size()|| merged.back()[1] < intervals[i][0]) {
			merged.push_back({intervals[i][0],intervals[i][1]});
		}
		else {
			merged.back()[1] = max(intervals[i][1], merged.back()[1]);
		}
	}

	return merged;
}
//接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
//按列求
//接雨水02
int trap(vector<int>& height){
	stack<int> mStack;
	int current = 0;
	int sum = 0;
	while(current < height.size()){
		while(!mStack.empty() && height[current]>height[mStack.top()]){
			int c = height[mStack.top()];
			mStack.pop();
			if (mStack.empty()){
				break;

			}
			int lenght = current - mStack.top()-1;
			int h = min(height[current],height[mStack.top()]);
			sum+= (h-c)*lenght;	
		}

		mStack.push(current);
		current++;
	}
	return sum;
}
//接雨水01
int trap01(vector<int>& height)
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

