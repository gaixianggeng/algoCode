#include "algoCode.h"
#include <cstddef>



void testListNode(){
	ListNode* head1= new ListNode(0);
	ListNode* temp1 = head1;
	vector<int> nums1 = {1,2,3,4,5};
	for(int i=0;i<nums1.size();i++){
		ListNode* temp = new ListNode(0);
		temp->val = nums1[i];
		temp->next= NULL;
		temp1->next = temp;
		temp1 = temp;
	}
	print(head1);
	//	ListNode* head2= new ListNode(0);
	//	ListNode* temp3 = head2;
	//vector<int> nums2 = {1,2,3,4,5};
	//for(int i=0;i<nums2.size();i++){
	//	ListNode* temp = new ListNode(0);
	//	temp->val = nums2[i];
	//	temp->next= NULL;
	//	temp3->next = temp;
	//	temp3 = temp;
	//}
	//print(head2);
	//	ListNode* l = mergeTwoList(head1,head2);
	//	print(l);
	reverseList(head1);
}

//链表排序
ListNode* mergeTwoList(ListNode* l1,ListNode* l2){

	if (l2 == NULL){
		return l1;
	}
	if (l1 ==NULL){
		return l2;
	}
	if (l1->val < l2->val){
		l1->next = mergeTwoList(l1->next, l2);
		return l1;
	}else{
		l2->next = mergeTwoList(l1, l2->next);
		return l2;
	}
}
void print(ListNode* p){
	//	ListNode *p = l;
	while (p->next !=NULL) {
		cout<<p->val;
		p = p->next;
	}
	cout<<p->val;
	cout<<endl;
	cout<<"end"<<endl;
}

//反转链表 数组倒排
ListNode* reverseList1(ListNode* head){

	if (!head){
		return NULL;
	}
	vector<int> temp;
	do {
		temp.push_back(head->val);
		head = head->next;
	}while (head);
	ListNode* reHead = new ListNode(temp[temp.size()-1]);
	ListNode* tempList = reHead;

	for (int i =temp.size()-2 ; i>=0; i--){
		ListNode* t = new ListNode(0);
		t->val = temp[i];
		t->next= NULL;
		tempList->next = t;
		tempList = t;
	}
	return reHead;
}

//链表反转 双指针
ListNode* reverseList(ListNode* head){
	ListNode* temp = new ListNode(0);
	ListNode* cur = head; 
	ListNode* reHead = NULL;

	while(cur){
		temp = cur->next;
		cur->next = reHead;
		reHead = cur;
		cur = temp;
	}
	return reHead;
}
