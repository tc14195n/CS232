#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 
    
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

//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
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
