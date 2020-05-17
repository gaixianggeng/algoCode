#include "algoCode.h"


//动态 贪心


//买卖股票的最佳时机
//

void testDynamic(){
	vector<int> nums = {7,1,5,3,6,4};
	int max = maxProfit2(nums);
	cout<<max<<endl;
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
