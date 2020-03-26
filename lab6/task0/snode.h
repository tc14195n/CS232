#ifndef _snode_H
#define _snode_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct snode {
  //TODO: change str to dynamic allcoation
  char *str;
  struct snode * next;
};

//TODO: change prototypes of functions to remove
//length
struct snode *snode_create(char *s) ; 
char* snode_get_str(struct snode *s);
struct snode *snode_get_next(struct snode *s);
void snode_destroy(struct snode * s) ;
 
#endif