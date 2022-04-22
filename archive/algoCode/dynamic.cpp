#include "algoCode.h"
#include <algorithm>

//动态 贪心


//买卖股票的最佳时机
//

void testDynamic(){
	vector<vector<int>> nums ={
		{7,14},
		{5,10},
		{3,5},
		{3,6},
		{1,2},
		{3,4},
	};
	//int max = maxProfit2(nums);
	//cout<<max<<endl;
	maxEnvelopes(nums);
}


int maxProfit(vector<int>& prices) {
	if (prices.size() == 0){
		return 0;
	}
	int small = prices[0];
	int sum = 0;
	for(int i=0;i<prices.size();i++){
		if (prices[i]<small){
			small = prices[i];
		}else{
			sum = max(prices[i]-small,sum);
		}
	}
	return sum;
}
int maxProfit2(vector<int>& prices) {
	if (prices.size() == 0){
		return 0;
	}
	int small = prices[0];
	int sum = 0;
	for(int i=0;i<prices.size();i++){
		if (prices[i]<small){
			small = prices[i];
		}else{
			sum +=prices[i]-small;
			small = prices[i];
		}
	}
	return sum;
}

//最大正方形
//还有二维降一维的解法 但不太好理解
int maximalSquare(vector<vector<char>>& matrix) {

	if (matrix.size() ==0){
		return 0;
	}
	int length = matrix.size();
	int width= matrix[0].size();
	vector<vector<int>> dp(length+1, vector<int>(width+1));
	int sum = 0;
	for(int i=0;i<length;i++){
		for(int n=0;n<width;n++){
			if(matrix[i][n] == '1'){
				dp[i+1][n+1]= min(min(dp[i][n+1],dp[i+1][n]),dp[i][n])+1;
				sum = max(dp[i+1][n+1],sum);
			}
		}
	}
	return sum * sum;
}

//最大子序和
//主要是判断sum是否为正值，如果>0则表示对下一个求和是有益处的，否则直接赋值下一个值
//同时每次都需判断最大值
int maxSubArray(vector<int>& nums) {
	int temp = nums[0];
	int sum = temp;
	for(int i=1;i<nums.size();i++){
		if (temp>0){
			temp +=nums[i];
		}else{
			temp = nums[i];
		}
		sum = max(sum,temp);
	}
	return sum;
}

//三角形最小路径和
//倒排  每次最小的数组和上一排进行累加
int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size()==0){
		return 0;

	}
	int length = triangle.size()-1;
	for(int i = length;i>0;i--){
		twoLinePlus(triangle,i);
	}
	return triangle[0][0];
}

void twoLinePlus(vector<vector<int>> &triangle ,int length){
	for(int i=0;i<triangle[length-1].size();i++){
		triangle[length-1][i] += triangle[length][i]>triangle[length][i+1]?triangle[length][i+1]:triangle[length][i];
	}
}
//俄罗斯套娃信封问题
int maxEnvelopes(vector<vector<int>>& envelopes) {

	if (envelopes.size() == 0){
		return  0;
	}
	int sum = 1;
	sort(envelopes.begin(),envelopes.end(),[](vector<int>&a,vector<int>&b){
			if (a[0] != b[0]) return a[0] < b[0];
			if (a[1] != b[1]) return a[1] > b[1];
			return true;
			}
	    );
	vector<int> tempNums;
	for (int i=0; i<envelopes.size(); i++) {
		tempNums.push_back(envelopes[i][1]);
	}
	sum = lengthOfLIS(tempNums);
	return sum;
}
//最长上升子序列
//动态规划
int lengthOfLIS(vector<int>& nums) {

	if (nums.size()==0){
		return 0;
	}
	int size = nums.size()-1;
	int* dp = new int[size+1];
	for(int n=0;n<=size;n++){
		dp[n] = 1;
		for(int m=0;m<n;m++){
			if (nums[n]>nums[m]){
				dp[n] = max(dp[n],dp[m]+1);
			}
		}
	}
	int num = 1;
	for(int i=0;i<=size;i++){
		num = max(dp[i],num);
	}
	return num;
}
