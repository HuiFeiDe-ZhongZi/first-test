class Solution {
	public:
		/* 合并排序链表*/
		ListNode* merge(ListNode* head1, ListNode* head2) {
			ListNode* dummy = new ListNode();
			ListNode* cur = dummy;
			while (head1 != nullptr && head2 != nullptr) {
				if (head1->val < head2->val) {
					cur->next = head1;
					head1 = head1->next;
				}
				else {
					cur->next = head2;
					head2 = head2->next;
				}

				cur = cur->next;
			}
			cur->next = (head1 == nullptr) ? head2 : head1;

			ListNode* ret = dummy->next;
			delete dummy;
			dummy = nullptr;
			return ret;
		}

		/* 归并链表 */
		ListNode* mergeLists(vector<ListNode*>& lists, int start, int end) 
		{
			if(start == end)
			{
				return lists[start];
			}

			int mid = start + (end - start)/2;
			ListNode* head1 = mergeLists(lists,start,mid);
			ListNode* head2 = mergeLists(lists,mid + 1,end);
			return merge(head1,head2);
		}

		ListNode* mergeKLists(vector<ListNode*>& lists) {
			if(lists.size() == 0)
			{
				return NULL;
			}
			return mergeLists(lists,0,lists.size() - 1);
		}
};
