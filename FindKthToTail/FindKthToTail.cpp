// ***********************************************************************
// Assembly         : ����һ����������������е�����k����㡣
// Author           : zhang
// Created          : 03-09-2017
//
// Last Modified By : zhang
// Last Modified On : 03-09-2017
// ***********************************************************************
// <copyright file="FindKthToTail.cpp" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		if (pListHead == NULL || k <= 0)
		{
			return NULL;
		}
		//��ListNode�����vector
		vector<ListNode*> vct;
		ListNode* pNode = pListHead;
		while (pNode != NULL)
		{
			vct.push_back(pNode);
			pNode = pNode->next;
		}
		if (vct.size() < k)
		{
			return NULL;
		}
		return vct[vct.size() - k];
	}
};

int main()
{
	//��������
	ListNode* head = new ListNode(0);
	ListNode* second = new ListNode(1);
	ListNode* three = new ListNode(2);
	ListNode* four = new ListNode(3);
	head->next = second;
	second->next = three;
	three->next = four;
	Solution sl;
	if (sl.FindKthToTail(head, 2) != NULL)
	{
		cout << "�����ڶ������Ƕ��� ��" << sl.FindKthToTail(head, 2)->val << endl;
	}
	return 0;
}

