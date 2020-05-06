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
	ListNode* head2= new ListNode(0);
	ListNode* temp3 = head2;
	vector<int> nums2 = {1,2,3,4,5};
	for(int i=0;i<nums2.size();i++){
		ListNode* temp = new ListNode(0);
		temp->val = nums2[i];
		temp->next= NULL;
		temp3->next = temp;
		temp3 = temp;
	}
	print(head2);
	ListNode* l = mergeTwoList(head1,head2);
	print(l);

}

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
void print(ListNode* l){
	ListNode *p = l;
	while (p->next !=NULL) {
	cout<<p->val;	
	p = p->next;
		}
	cout<<p->val;
cout<<endl;	
cout<<"end"<<endl;
}
