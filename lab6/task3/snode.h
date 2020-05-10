#ifndef _snode_H
#define _snode_H
#include "frame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct snode {
  //TODO: change str to dynamic allcoation
  struct frame_t* data;
  struct snode * next;
};

//TODO: change prototypes of functions to remove
//length
struct snode *snode_create(frame *f) ; 
char* snode_get_str(struct snode *s);
struct snode *snode_get_next(struct snode *s);
void snode_destroy(struct snode * s) ;
 
#endif