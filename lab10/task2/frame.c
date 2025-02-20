/******************************************************
* File: frame.c
*
* This is the frame struct implementation
*
* Change Log:
* 12/02/2006, By Jun Yuan, created for CS101, Huazhong University of Sci. & Tech., Wuhan, China
* 01/05/2016, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 02/11/2017, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 02/18/2017, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 04/16/2019, By Jun Yuan-Murray, modified for CS232, Pace University, NY
* 04/29/2020, By Jun Yuan-Murray, modified for CS232, Pace University, NY
******************************************************/
#include "frame.h"
#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
static void load_frame(frame_t *f, char *path){
	// TODO:your code here
	// path is the pathname to an ascii file, we have to open the ascii file, and read the content
	// in line by line and store it in the frame->content
	// here is an example of reading line-by-line from path
		FILE * fp;
    	char line[4096]; 
    	//char* read = NULL;
    	int len = 300;
		fp = fopen(path, "r");
    	if (fp == NULL)
        	exit(EXIT_FAILURE);
        f->rep_counter = atoi(fgets(line,len,fp));
        //printf("%d",f->rep_counter);
        //f->content;
        //fgets(line,len,fp);
        f->content = (char*)malloc(sizeof(char)*strlen(line)+1);
        //f->content = line;
        strcpy(f->content,line);
        
    	while (fgets(line, len, fp) != NULL) {
    		char* temp = f->content;
    		f->content = (char*)malloc(sizeof(char)*(strlen(temp) + strlen(line)) +1);
    		strcpy(f->content,temp);
    		strcat(f->content,line);
    		free(temp);	
    	}
    	
    	//printf("%s",f->content);
	fclose(fp);

	//also keep in mind, the first line is the repetition counter.
	//f->rep_counter = ...
	return;
}

frame_t * frame_new(char *pathname, int id) {
	//TODO: frame_new is not complete until load_frame is done
	frame_t * f = (frame_t *) malloc(sizeof(frame_t));
	if(!f) {
		perror("OOM, alloc failed\n");
		return 0;
	}
	//f->content = NULL;
	f->id = id;
	f->rep_counter = 0;
	load_frame(f, pathname);
	return f;
}

void frame_delete(frame_t * f) {
	//TODO: before we free f what inside f must be free-ed first?
	//free(f->rep_counter);
	//free(f->id);
	free(f->content);
	free(f);
}

char* frame_get_content (frame_t *f){
	return f-> content;
}
int frame_get_rep_counter(frame_t * f){
	return f-> rep_counter;
}
int frame_get_id(frame_t *f){
	return f-> id;
}

