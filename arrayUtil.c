#include <stdio.h>
#include <stdlib.h>
#include "arrayUtil.h"
#include <string.h>


int areEqual(ArrayUtil a,ArrayUtil b){
	int i;
	if((a.length != b.length) || (a.typeSize != b.typeSize))
		return 0;
	for(i=0;i<a.length*a.typeSize;i++){
		if(((char*)a.base)[i] != ((char*)b.base)[i])
			return 0;
	}
	return 1;	
}

ArrayUtil create(int typeSize,int length){
	int *arr1;
	ArrayUtil result;
	result.typeSize = typeSize;
	result.length = length;
	arr1 = (int *)calloc(typeSize,length);
	result.base = ((void *)arr1);
	return result;
}

ArrayUtil resize(ArrayUtil util , int length){
	int i,size = util.typeSize*length;
	util.base = realloc(util.base,size);
	if(length>util.length){
		for(i = util.length*util.typeSize;i<size;i++){
			((char *)util.base)[i] = 0;
		}	
	}
	util.length = length;
	return util;
}

int findIndex(ArrayUtil util,void *element){
	int i,index = -1;
	int *ele;
	ele = (int *)element;
	for( i= 0; i <util.length; i++){
		if(((int *)util.base)[i] == *ele)
			index = i;
	}
	return index;
}

void dispose(ArrayUtil util){
	free(util.base);
	// util.length = 0;
	// util.typeSize = 0;
	util.base = NULL;
}

// void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
// 	int i;
// 	void *item = malloc(util.typeSize);
// 	char *base = (char *)util.base;
// 	for(i = 0; i<util.length; i++){
// 		memcpy( item,base[i*util.typeSize],util.typeSize);
// 	printf("%d\n",base[0]);
// 		if(match(item,hint)){
// 			return item;
// 		}
// 	}
// 	return NULL;
// }
