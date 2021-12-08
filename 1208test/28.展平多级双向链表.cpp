Node* flatten(Node* head) {
	Node *iter = head;

	while(iter != NULL)
	{
		if(iter->child == NULL)  
		{
			iter = iter->next;
		}
		else
		{
			Node *temp = iter->child;
			while(temp->next != NULL) temp = temp->next;
			if(iter->next != NULL)
			{
				temp->next = iter->next;
				temp->next->prev = temp;
				iter->next = iter->child;
				iter->next->prev = iter;
				iter->child = NULL;
			} 
			else
			{
				iter->next = iter->child;
				iter->next->prev = iter;
				iter->child = NULL; 
			}
		}
	}
	return head;      
}

