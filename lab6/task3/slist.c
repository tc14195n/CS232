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

/*
struct list_t {
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
	new_list->size = 0;
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
	l->size++;
	
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
	l->size++;
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

struct snode *slist_find_at(struct slist *list, int index)
{

	struct snode *temp;
	temp = list->front;
	int num = 0;
	int length = list->size;
	if(index < 0){
		if(index*(-1) > length){
			return NULL;
		}
		num = length + index;
	} else {
		if(index > length){
			return NULL;
		}
		num = index;
	}
	//int num1 = 0;
	for(int i = 0; i < num; i++){
		temp = temp->next;
		/*
		if(num == index)
		{
			return temp;
		}
		else if(num < index)
		{
			temp = temp->next;
			num++;
		}
		else if(num > index)
		{
			num1 = (length) + index;
			while(num != num1)
			{
				temp = temp->next;
				num++;
			}
			//return temp;
		}
		*/
	
	}
	
	return temp;
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
 	/*
	struct snode *temp;
	temp=l->front;
	
	unsigned int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
	*/
	return l->size;

	
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
			l->size--;
			if(last == NULL){
				if(l->size == 0){
					l->back = NULL;
				}
				l->front = tbd->next;
				snode_destroy(tbd);
				return NULL;
			} else if(tbd->next == NULL){
				l->back = last;
				//snode_destroy(tbd);
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

void slist_delete_at(struct slist *list, int index)
{
	//struct snode * temp;
	//temp = slist_find_at(list, index);
	//snode_destroy(temp);
	//free(list);

	struct snode *temp;
	//snode *last;
	temp = list->front;
	int num = 0;
	int length = list->size;
	if(index < 0)
	{
        	if(index*(-1) > length)
		{
		return;
		}
        num = length + index;
	} else
	{
        if(index > length)
	{
            return;
        }
        num = index;
}
    //int num1 = 0;
	for(int i = 0; i < num; i++)
	{
	//last = temp;
        temp = temp->next;
	}

        list->size--;
        if(temp->next == NULL)
	{
            //l->back = last;
            //last->next = NULL;
            snode_destroy(temp);
        }
	else
	{
            //last->next = temp->next;
            snode_destroy(temp);
            return;
        }
}

struct snode * slist_get_front(struct slist *a)
{
	struct snode *temp;
	temp = a->front;
	return temp;
};


struct snode * slist_get_back(struct slist *a)
{
	struct snode *temp;
	temp = a->back;
	return temp;

};