#include "algoCode.h"
#include <cstddef>

void testListNode()
{
	ListNode *head1 = new ListNode(1);
	ListNode *temp1 = head1;
	vector<int> nums1 = {1, 4, 5, 8};
	for (int i = 0; i < nums1.size(); i++)
	{
		ListNode *temp = new ListNode(0);
		temp->val = nums1[i];
		temp->next = NULL;
		temp1->next = temp;
		temp1 = temp;
	}
	print(head1->next);
	//ListNode * sort = sortList(head1->next);
	//print(sort);
	//return;
	ListNode *head2 = new ListNode(2);
	ListNode *temp3 = head2;
	vector<int> nums2 = {5, 6};
	for (int i = 0; i < nums2.size(); i++)
	{
		ListNode *temp = new ListNode(0);
		temp->val = nums2[i];
		temp->next = NULL;
		temp3->next = temp;
		temp3 = temp;
	}
	print(head2->next);
	ListNode *head = merge2Lists(head1, head2);
	print(head);
	//reverseList(head1);
}

//二叉树
void testTreeNode()
{

	TreeNode *treeN = new TreeNode(1);

	TreeNode *tree = treeN;
	TreeNode *temp = new TreeNode(2);
	tree->right = temp;
	tree = temp;
	temp = new TreeNode(3);
	tree->left = temp;
	vector<int> nums = preorderTraversal(treeN);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i];
	}
	cout << endl;
}

//链表排序
ListNode *mergeTwoList(ListNode *l1, ListNode *l2)
{

	if (l2 == NULL)
	{
		return l1;
	}
	if (l1 == NULL)
	{
		return l2;
	}
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoList(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoList(l1, l2->next);
		return l2;
	}
}
void print(ListNode *p)
{
	//	ListNode *p = l;
	while (p->next != NULL)
	{
		cout << p->val;
		p = p->next;
	}
	cout << p->val;
	cout << endl;
	cout << "end" << endl;
}

//反转链表 数组倒排
ListNode *reverseList1(ListNode *head)
{

	if (!head)
	{
		return NULL;
	}
	vector<int> temp;
	do
	{
		temp.push_back(head->val);
		head = head->next;
	} while (head);
	ListNode *reHead = new ListNode(temp[temp.size() - 1]);
	ListNode *tempList = reHead;

	for (int i = temp.size() - 2; i >= 0; i--)
	{
		ListNode *t = new ListNode(0);
		t->val = temp[i];
		t->next = NULL;
		tempList->next = t;
		tempList = t;
	}
	return reHead;
}

//链表反转 双指针
ListNode *reverseList(ListNode *head)
{
	ListNode *temp = new ListNode(0);
	ListNode *cur = head;
	ListNode *reHead = NULL;

	while (cur)
	{
		temp = cur->next;
		cur->next = reHead;
		reHead = cur;
		cur = temp;
	}
	return reHead;
}

//两数相加
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode *nSum = new ListNode(0);
	ListNode *head = nSum;
	int beforeNum = 0;
	while (l1 || l2)
	{
		ListNode *temp = new ListNode(0);
		int tempVal = 0;
		if (l1)
		{
			tempVal += l1->val;
		}
		if (l2)
		{
			tempVal += l2->val;
		}

		int val = (tempVal % 10 + beforeNum / 10) % 10;
		beforeNum = tempVal + beforeNum / 10;
		cout << beforeNum << endl;
		temp->val = val;
		temp->next = NULL;
		head->next = temp;
		head = temp;

		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}
	if (beforeNum / 10 >= 1)
	{
		ListNode *temp = new ListNode(0);
		temp->val = beforeNum / 10;
		temp->next = NULL;
		head->next = temp;
	}
	return nSum->next;
}

//递归二分链表 之后合并两个有序链表
ListNode *sortList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *leftNode = middleNode(head);
	ListNode *rightNode = leftNode->next;
	leftNode->next = NULL;
	ListNode *left = sortList(head);
	ListNode *right = sortList(rightNode);

	return mergeTwoList(left, right);
}

//二分链表
ListNode *middleNode(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *slow = head;
	ListNode *fast = head->next->next;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//环形链表
//画图理解
ListNode *detectCycle(ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != NULL && fast->next != NULL)
	{

		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			fast = head;
			while (fast != slow)
			{
				slow = slow->next;
				fast = fast->next;
				if (slow == fast)
				{
					break;
				}
			}
			return fast;
		}
	}
	return NULL;
}
//相交链表
//画图  a长 b短的情况下 b->next = null时 b指向a 此时 ab距离为b的长度 则a==null的时候 b（此时在a上）到null的距离和原始b距离一样
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

	ListNode *a = headA;
	ListNode *b = headB;
	while (a != b)
	{
		if (a == NULL)
		{
			a = headB;
		}
		else
		{
			a = a->next;
		}
		if (b == NULL)
		{
			b = headA;
		}
		else
		{
			b = b->next;
		}
	}
	return a;
}

//合并k个排序链表
ListNode *mergeKLists(vector<ListNode *> &lists)
{

	if (lists.empty())
	{
		return NULL;
	}
	if (lists.size() == 1)
	{
		return lists[0];
	}
	ListNode *head = lists[0];
	for (int i = 1; i <= lists.size() - 1; i++)
	{
		head = merge2Lists(head, lists[i]);
	}
	return head;
}
//合并两个链表
ListNode *merge2Lists(ListNode *h1, ListNode *h2)
{
	if (h1 == NULL)
	{
		return h2;
	}
	if (h2 == NULL)
	{
		return h1;
	}
	if (h1->val < h2->val)
	{
		h1->next = merge2Lists(h1->next, h2);
		return h1;
	}
	else
	{
		h2->next = merge2Lists(h1, h2->next);
		return h2;
	}
}
//二叉树最近公共祖先
//递归问题
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root == p || root == q)
	{
		return root;
	}
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left == NULL)
	{
		return right;
	}
	if (right == NULL)
	{
		return left;
	}
	return root;
}

//二叉树前序遍历
vector<int> preorderTraversal(TreeNode *root)
{
	cout << "test" << endl;
	vector<int> nums;
	if (root == NULL)
	{
		return nums;
	}
	nums.push_back(root->val);
	vector<int> nums1 = (preorderTraversal(root->left));
	vector<int> nums2 = (preorderTraversal(root->right));
	if (nums1.size() > 0)
	{
		nums.insert(nums.end(), nums1.begin(), nums1.end());
	}
	if (nums2.size() > 0)
	{
		nums.insert(nums.end(), nums2.begin(), nums2.end());
	}
	return nums;
}

//二叉树的锯齿形层次遍历
//bfs宽度优先
vector<vector<int>> zigzagLevelOrderBFS(TreeNode *root)
{
	vector<vector<int>> nums;
	queue<TreeNode *> q;
	q.push(root);
	int level = 0;
	while (!q.empty())
	{
		vector<int> temp;
		int count = q.size();
		while (count--)
		{
			TreeNode *tn = q.front();
			q.pop();
			if (level % 2 == 0)
			{
				temp.push_back(tn->val);
			}
			else
			{
				temp.insert(temp.begin(), tn->val);
			}
			if (tn->left)
			{
				q.push(tn->left);
			}
			if (tn->right)
			{
				q.push(tn->right);
			}
		}
		nums.push_back(temp);

		level++;
	}
	return nums;
}
//二叉树的锯齿形层次遍历 dfs 深度优先
vector<vector<int>> zigzagLevelOrderDFS(TreeNode *root){

}
