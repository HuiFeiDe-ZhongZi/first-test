class Solution {
	public:
		/* 确定中间节点 */
		ListNode *split(ListNode *head)
		{
			ListNode *slow = head;
			ListNode *fast = head->next; //区分奇偶所以这样做 （1 2 3 4 5） （1 2 3 4 5 6）
			while(fast != NULL && fast->next != NULL)
			{
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode *second = slow->next;
			slow->next = NULL;
			return second;
		}

		/* 合并排序链表*/
		ListNode* merge(ListNode* head1,ListNode* head2)
		{
			ListNode* dummy = new ListNode;
			ListNode* cur = dummy;

			while(head1 != NULL && head2 != NULL)
			{
				if(head1->val < head2->val)
				{
					cur->next = head1;
					head1 = head1->next;
				}
				else
				{
					cur->next = head2;
					head2 = head2->next;
				}

				cur = cur->next;
			}
			cur->next = (head1 == NULL)?head2:head1;

			ListNode *ret = dummy->next;
			delete dummy;
			dummy = NULL;
			return ret;
		}

		ListNode* sortList(ListNode* head) {
			if(head == NULL || head->next == NULL)
			{
				return head;
			}

			ListNode* head1 = head;
			ListNode* head2 = split(head);

			head1 = sortList(head1);
			head2 = sortList(head2);

			return merge(head1,head2);
		}
};
