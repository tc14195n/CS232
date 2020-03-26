#include <stdio.h>
#include "snode.h"
#include "slist.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(char *s) 
{
	struct snode *node_t = (struct snode*)malloc(sizeof(struct snode));
	node_t->str = (char*)malloc(strlen(s)*sizeof(char)+1);
	strcpy(node_t->str,s);
	node_t->next = NULL;

 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
	return node_t;

  
}
void snode_destroy(struct snode * s) 
{
	free(s->str);
	free(s);

};
