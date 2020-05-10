// algoCode.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once
#include <vector>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>

#include <cstddef>

using namespace std;
// TODO: 在此处引用程序需要的其他标头。

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};



int trap(vector<int>&);
int trap01(vector<int>&);
int engthOfLongestSubstring(string);
bool checkInclusion(string, string);
string longestCommonPrefix(vector<string>&);
vector<int> twoSum(vector<int>&, int);
string multiply(string, string);
string reverseWords(string);
string simplifyPath(string);
vector<string> restoreIpAddresses(string);
vector<vector<int>> threeSum(vector<int>&);
int maxAreaOfIsland(vector<vector<int>>&);
int dfs(vector<vector<int>>&, int, int, int, int);
int search(vector<int>&, int);
void quickSort(vector<int>&, int, int);
int	quickSortK(vector<int>&, int);
void position(vector<int>&, int, int,int);
int longestConsecutive(vector<int>&);
string getPermutation(int n, int k);
void permutation(int n, int k,int*,string&);
void deleteItem(int*,int, int);
int findCircleNum(vector<vector<int>>&);
vector<vector<int>> merge(vector<vector<int>>&);
void testListNode();
ListNode* mergeTwoList(ListNode*,ListNode*);
void print(ListNode*);
ListNode* reverseList(ListNode* head);
ListNode* reverseList1(ListNode* head);
ListNode* addTwoNumbers(ListNode*, ListNode*);
ListNode* sortList(ListNode* );
