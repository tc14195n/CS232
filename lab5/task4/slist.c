#include <stdio.h>
#include "slist.h"
#include "snode.h"
#include <string.h>
#include <stdlib.h>
/*
struct slist {
  struct snode *front; // front node
  struct snode *back;  // back node
};*/


struct slist *slist_create(){
	/**
 	* Allocates new slist dynamically.
 	* 
 	* @return pointer to the list
 	*/
	struct slist *new_list = (struct slist*)malloc(sizeof(struct slist));
	new_list->front = NULL;
	new_list->back = NULL;
	return new_list;

};


struct snode* slist_add_back(struct slist *l, char *str){
	/** 
 	* Inserts new node in slist after the last node.
 	*
 	* @param l pointer to the list (non-NULL)
 	* @param str pointer to a C string to store in new list node
 	* returns a pointer to the newly added node
 	*/
	struct snode *s1, *old_back;
	s1 = snode_create(str);
	if(l->back == NULL){
		l->back = s1;
		l->front = s1;
	} else {
		old_back = l->back;
		old_back->next = s1;
		l->back = s1;
	}
	
	return s1;
};


struct snode* slist_add_front(struct slist *l, char *str){
	/** 
 	* Inserts new node in slist before the first node.
 	*
 	* @param l pointer to the list (non-NULL)
 	* @param str pointer to a C string to store in new list node
 	* returns a pointer to the newly added node
 	*/
	struct snode *s1, *old_front;
	s1 = snode_create(str);
	if(l->front == NULL){
		l->back = s1;
		l->front = s1;
	} else {
		old_front = l->front;
		s1->next = old_front;
		l->front = s1;
	}
	return s1;
};


struct snode* slist_find(struct slist *l, char *str)
{
	/**
 	* Returns the first snode with the given string.
 	*  
 	* @param l pointer to the list (non-NULL)
 	* @parap str pointer to a string
 	* @return struct snode* or NULL if no match
 	*/
	struct snode *temp;
	temp = l->front;
	while(temp != NULL){
		if(strcmp(temp->str,str) == 0){
			return temp;
		} else {
			temp = temp->next;
		}
	}
	return NULL;
};


void slist_destroy(struct slist *l)
{
	/**
 	* Deallocate a list and all snodes
 	*
 	* @param l pointer tot he list
 	*/
	struct snode *tbd, *next; //tbd -- snode TO BE DESTROYED
	tbd = l->front;
	next = tbd->next;

	while(next != NULL){
		snode_destroy(tbd);
		tbd = next;
		next = tbd->next;
	}
	snode_destroy(tbd);
	free(l);
};

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l)
{
	/**
 	* Traverse the list and print the content of each node.
 	*
 	* @param l pointer to the list (non-NULL)
 	*/
	struct snode *temp;
	temp = l->front;
	
	while(temp != NULL){
		printf("%s\n",temp->str);
		temp = temp->next;
	}
};


uint32_t slist_length(struct slist *l)
{
	/**
 	* Returns the number of elements in the list (nodes).
 	*
 	* @param l pointer to the list (non-NULL)
 	*/
	struct snode *temp;
	temp=l->front;
	
	unsigned int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
};

//struct snode* slist_delete(struct slist *l, char *str){
struct snode* slist_delete(struct slist *l, char *str)
{

	/**
 	* Deletes the first snode with the given string.
 	*  
 	* @param l pointer to the list (non-NULL)
 	* @parap str pointer to a string
 	* @return struct snode* or NULL if no match
 	*/
 	//relink prior node to new after node
 	//if deleting first node, redefine "l->front"
 	//if deleting last ndoe, redefine "l->back"
	struct snode *tbd = l->front, *last = NULL;
	while(tbd != NULL){
		if(strcmp(tbd->str,str) == 0){
			//delete
			if(last == NULL){
				l->front = tbd->next;
				snode_destroy(tbd);
				return NULL;
			} else if(tbd->next == NULL){
				l->back = last;
				return NULL;
			} else {
				last->next = tbd->next;
				snode_destroy(tbd);
				return NULL;
			}
		}
		last = tbd;
		tbd = tbd->next;
	}
	return NULL;

};

