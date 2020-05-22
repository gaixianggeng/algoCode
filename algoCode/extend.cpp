#include  "algoCode.h"

//x的平方根
//7 1 4,2 4,2 3,
int mySqrt(int x) {
	cout<<x<<endl;
	if (x == 0){
		return 0;
	}
	long left = 1;
	long right = x;
	while (left<right) {
		long mid = (left+right+1)/2;
		cout<<left<<":"<<right<<endl;
		if ((x/mid)<mid){
			right = mid-1;
		}else{
			left = mid;
		}
	}
	return left;
}



