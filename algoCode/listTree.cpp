#include "algoCode.h"
#include <cstddef>



void testListNode(){
	ListNode* head1= new ListNode(1);
	ListNode* temp1 = head1;
	vector<int> nums1 = {3,4,2,1};
	for(int i=0;i<nums1.size();i++){
		ListNode* temp = new ListNode(0);
		temp->val = nums1[i];
		temp->next= NULL;
		temp1->next = temp;
		temp1 = temp;
	}
	print(head1->next);
	ListNode * sort = sortList(head1->next);
	print(sort);
	return;
	ListNode* head2= new ListNode(9);
	ListNode* temp3 = head2;
	vector<int> nums2 = {9};
	for(int i=0;i<nums2.size();i++){
		ListNode* temp = new ListNode(0);
		temp->val = nums2[i];
		temp->next= NULL;
		temp3->next = temp;
		temp3 = temp;
	}
	print(head2);
	ListNode* l = addTwoNumbers(head1->next,head2);
	print(l);
	//reverseList(head1);
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




//两数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* nSum = new ListNode(0);
	ListNode* head = nSum;
	int beforeNum = 0;
	while (l1 || l2) {
		ListNode* temp = new ListNode(0);
		int tempVal = 0;
		if (l1){
			tempVal += l1->val;

		}
		if (l2){
			tempVal += l2->val;

		}

		int val = (tempVal%10+beforeNum/10)%10;
		beforeNum = tempVal+beforeNum/10;
		cout<<beforeNum<<endl;
		temp->val = val;
		temp->next = NULL;
		head->next = temp;
		head = temp;

		if (l1){
			l1 = l1->next;

		}
		if (l2){
			l2 = l2->next;


		}



	}
	if (beforeNum /10 >=1){
		ListNode* temp = new ListNode(0);
		temp->val = beforeNum/10;
		temp->next = NULL;
		head->next = temp;

	}
	return nSum->next;
}

//递归二分链表 之后合并两个有序链表
ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL){
		return head;
	}
	ListNode* leftNode = middleNode(head);
	ListNode* rightNode = leftNode->next;
	leftNode->next = NULL;
	ListNode* left = sortList(head);
	ListNode* right = sortList(rightNode);

	return mergeTwoList(left,right);

}

//二分链表
ListNode* middleNode(ListNode* head){
	if (head == NULL || head->next == NULL){
		return head;
	}
	ListNode * slow = head;
	ListNode * fast = head->next->next;
	while(fast!=NULL && fast->next != NULL ){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//环形链表
ListNode *detectCycle(ListNode *head) {
	ListNode* fast = head;
	ListNode * slow = head;
	while(true){
		if (fast->next == NULL || fast == NULL){
			return NULL;
		}
		fast = fast->next->next;
		slow = slow->next;
		if (slow->val == fast->val){
			break;
		}

	}
	fast = head;
	while(true){
		slow = slow->next;
		fast = fast->next;
		if (slow->val == slow->val){
			break;
		}
	}
	return slow;

}
