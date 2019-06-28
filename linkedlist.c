//Riya Baphna
//rb4nk
//04/11/19
//linkedlist.c


#include <stdio.h>
#include <stdlib.h>


struct ListNode{
	struct ListNode *next;
	int data;
};

struct List{
	struct ListNode *head;

};


int main(){
	struct List *l;
	int n;
	printf("Enter number of values to input: ");
	scanf("%d" , &n);
	l = (struct List*) malloc (sizeof (struct List));
	l->head = (struct ListNode*) malloc(sizeof(struct ListNode));
	l->head -> data = 0;
	struct ListNode *begin;
	begin = l->head; // stores the head of list in begin to alter later on

	for (int i = 1; i <=n; i++){
		int value;
		printf("Enter value %d: ", i);
		scanf("%d", &value); //reads in n values 
		begin->next = (struct ListNode*) malloc(sizeof(struct ListNode));
		begin ->next ->data = value;// sets the node after head to the value entered by user
		begin = begin ->next; // sets the head to the next node so can iterate through for loop using new head node

	}

	for (int x = 0; x <n; x++){
		printf("%d\n", l->head->next->data);
		l->head->next = l->head->next->next;
	}
    void free(void* l);
	return 0;

}

