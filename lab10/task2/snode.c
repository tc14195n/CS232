#include <stdio.h>
#include "snode.h"
#include "slist.h"
#include "frame.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(frame_t *s) 
{
	struct snode *node_t = (struct snode*)malloc(sizeof(struct snode));
	//struct frame_t *data = (struct frame_t*)malloc(sizeof(struct frame_t));
	node_t->data = s;
	node_t->next = NULL;

 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
	return node_t;

  
}
frame_t* snode_get_str(struct snode *s){
	return s->data;
}
struct snode *snode_get_next(struct snode *s){
	return s->next;
}
void snode_destroy(struct snode * s) 
{
	frame_delete(s->data);
	//free(s->data);
	free(s);

};
