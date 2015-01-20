#include <stdio.h>
#include <stdlib.h>
#include "arrayUtil.h"


int areEqual(ArrayUtil a,ArrayUtil b){
	int i,*b1,*b2;
	if((a.length == b.length) && (a.typeSize == b.typeSize)){
		for(i=0;i<a.length;i++){
			if(((char*)a.base)[i] != ((char*)b.base)[i]){
				return 0;
			}
		}
		return 1;
	}
	return 0;
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
	int * base_p = ((int *)util.base);
	util.length = (int )realloc(util.base,size);
	if(util.length > length){
		for(i=0;i< size;i++){
			base_p[i] = 0;
		}
	}	
	return util;
}

int findIndex(ArrayUtil util,void *element){
	int i,index = -1;
	int *ele;
	int * base_p = ((int *)util.base);
	ele = (int *)element;
	for(i=0;i<util.length;i++){
		if(base_p[i] == *ele)
			index = i;
	}
	return index;
}