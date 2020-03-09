#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>



struct snode *snode_create(void *s) 
{
	struct snode *node_t = (struct snode*)malloc(sizeof(struct snode));

	node_t->data = s;
	node_t->next = NULL;

	return node_t;

  
}
void snode_destroy(struct snode * s) 
{
	//free(s->data);
	free(s);

};
