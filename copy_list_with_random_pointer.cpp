#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
	if(head == NULL) return NULL;
    	head = insert_copy_node(head);
	head = set_random_point(head);
	RandomListNode *c_head = split_list(head);
	return c_head;
    }
private:
    RandomListNode* insert_copy_node(RandomListNode *head)
    {
    	RandomListNode *h_next, *h_now;
	h_now = head;
	while(h_now != NULL)
	{
		h_next = h_now->next;
		RandomListNode *node_t = new RandomListNode(h_now->label);
		node_t->next = h_next;
		node_t->random = NULL;
		h_now->next = node_t;
		h_now = h_next;
	}
 	return head;
    }

    RandomListNode* set_random_point(RandomListNode* head)
    {
    	RandomListNode *h_now, *h_random;
	h_now = head;
	while(h_now != NULL)
	{
		if(h_now->random != NULL)
		{
			h_now->next->random = h_now->random->next;
		}
		h_now = h_now->next->next;
	}
	return head;
    }
    RandomListNode* split_list(RandomListNode *head)
    {
    	RandomListNode  *c_head=NULL, *c_now, *h_now, *h_node;
	h_node = head;
	while(h_node != NULL)
	{
		if(c_head == NULL) c_head = h_node->next;
		else c_now->next = h_node->next;
		c_now = h_node->next;
		h_node->next = h_node->next->next;
		h_node = h_node->next;
	}
	return c_head;
    }

};
int main()
{
}
