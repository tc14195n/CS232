/******************************************************
* File: asciimation.c
*
* This is implementation of asciimation
*
* Change Log:
* 12/02/2006, By Jun Yuan, created for CS101, Huazhong University of Sci. & Tech., Wuhan, China
* 01/05/2016, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 02/11/2017, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 02/18/2017, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 04/16/2019, By Jun Yuan-Murray, modified for CS232, Pace University, NY
* 04/29/2020, By Jun Yuan-Murray, modified for CS232, Pace University, NY
******************************************************/
#include "asciimation.h"
#include "slist.h"
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int get_num_frames(char *path) {
	DIR * dir;
	struct dirent * pdir;
	dir = opendir(path);
	int n = 0;
	while((pdir = readdir(dir))) {
		if(strcmp(pdir->d_name, ".") != 0 && strcmp(pdir->d_name, "..") != 0) {
		//printf("%s", pdir->d_name);
		//debugging printf, you can use this line to print out ascii file names.
		n++;
		}

	}
	closedir(dir);
	return n;

}

asciimation_t * asciimation_new(char * path, int fps){
	asciimation_t * ascm = (asciimation_t *) malloc(sizeof(asciimation_t));
	if(!ascm) {
		perror("failed allocation\n");
		return 0;
	}
	//printf("entered asciimation new");
	//assign fps to frames_per_second in the struct
	ascm->frames_per_second = fps;
	//figure out how many frames are in the dir?
	//printf("here!!");
	int n = get_num_frames(path);
	//create a list of frames
	ascm->frames = slist_create();//TODO: create a new slist;
	// we know the number of frames, we can simply reconstruct the name of each ascii file, and construct a frame obj for 
	// each ascii file. Must implement frame_new first
	for(int i=0; i<n; i++) {
		char asciipath[4096];
		strcpy(asciipath, path);
		int len = strlen(asciipath);
		if(asciipath[len-1] != '/') 
			sprintf(asciipath+len, "/%d", i+1);
		else	
			sprintf(asciipath+len, "%d", i+1);
		//if your path is ./data/a, and i=0, then asciipath = ./data/a/1, exactly what we want to load
		//printf("here");
		struct frame_t * aframe = frame_new(asciipath,i);
		//add aframe to ascm->frames;
		slist_add_back(ascm->frames,aframe);
		//printf("%d",aframe->id);
	}
	
	return ascm;
}

void asciimation_delete(asciimation_t * ascm){
	//TODO:your code here
	//reversed steps of asciimation_new
	// 1. free all the frames, must implement frame_delete first.(why?)
	// 2. free the list
	slist_destroy(ascm->frames);
	// 3. free the ascm itself
	//free(ascm->frames_per_second);
	free(ascm);
}

void asciimation_play(asciimation_t * ascm){
	if(system("clear") == 1){};
	//TODO:your code here
	//loop through the list of frames and print out each frame, ? is also to be done by you
	for(int i=0; i<(ascm->frames->size); i++) {
		frame_t* f = slist_find_at(ascm->frames,i)->data;

		printf("%s",(f->content));
		//sleep for frames_per_second * repetition_counter_of_the_frame
		sleep((ascm->frames_per_second) * (f->rep_counter));
		//clear the screen
		if(system("clear") == 1){};
	}
}
void asciimation_reverse(asciimation_t * ascm){
	//TODO:Your code here
	//same logic as above, only difference is loop through the list backward.
	for(int i=(ascm->frames->size)-1; i>=0; i--) {
		frame_t* f = slist_find_at(ascm->frames,i)->data;

		printf("%s",(f->content));
		//sleep for frames_per_second * repetition_counter_of_the_frame
		sleep((ascm->frames_per_second) * (f->rep_counter));
		//clear the screen
		if(system("clear") == 1){};
	}
}


