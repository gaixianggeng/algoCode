#include "algoCode.h"


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

void testListNode(){
	ListNode* temp1 = new ListNode(0);
	vector<int> nums = {1,2,3,4,5};
	for(int i=0;i<nums.size();i++){
		ListNode* temp2 = new ListNode(0);
		temp2->val = nums[i];
		temp2->next= NULL;
		temp1->next = temp2;
		temp1 = temp2;
	}
	cout<<"test123"<<endl;
}

