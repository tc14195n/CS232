#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {

    node_t * head ;
    node_t *y,*z;

    head=(node_t *)malloc(sizeof(node_t));
    y=(node_t *)malloc(sizeof(node_t));
    z=(node_t *)malloc(sizeof(node_t));

    strcpy(head->str,"hello");
    head->length = 5;
    head->next = y;

    strcpy(y->str,"there");
    y->length = 5;
    y->next = z;

    strcpy(z->str, "prof");
    z->length = 4;
    z->next = NULL;
    return head;
}

void teardown(node_t* head) {
    node_t* cur = head;
    node_t* next = cur->next;
    while(next != NULL){
        free(cur);
        cur = next;
        next = cur->next;
    }
    free(cur);
}

void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head

    node_t *temp = NULL;
    temp = (node_t *)malloc(sizeof(node_t));
    temp->length = length;
    strcpy(temp->str, str);
    temp->next = *head;
    *head = temp;

}
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.

	if(*head == NULL)
	{
		return;
	}

	node_t *temp = NULL;
	temp = *head;

	if(idx == 0)
	{
	*head = temp->next;
	free(temp);
	return;
	}

	for(int i=0; temp!=NULL && i<idx-1; i++)
	{
		temp = temp->next;
	}

	if(temp == NULL || temp->next == NULL)
	{
		return;
	}
	
	node_t *next = temp->next->next;
	free(temp->next);
	temp->next = next;
		
} 
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete. 


	node_t *temp = *head, *prev;
	
	while(temp != NULL && temp->str == key)
	{
		*head = temp->next;
		free(temp);
		temp = *head;
	}

	while(temp != NULL)
	{
		while(temp != NULL && temp->str != key)
		{
			prev = temp;
			temp = temp->next;
		}

		if(temp == NULL)
		{
			return;
		}

		prev->next = temp->next;
		free(temp);
		temp = prev->next;
	}
}
//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
