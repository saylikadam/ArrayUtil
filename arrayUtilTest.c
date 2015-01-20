#include "expr_assert.h"
#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>


void test_returns_1_for_equal_typesize_and_0_for_unequal_typesize(){
	ArrayUtil a,b;
	a.typeSize = sizeof(int);
	b.typeSize = sizeof(char);
	assertEqual(areEqual(a,b),0);
}

void test_returns_1_for_equal_size(){
	int *arr1, *arr2;
	ArrayUtil a,b;
	a.length = 1;
	b.length = 1;
	a.typeSize = sizeof(int);
	b.typeSize = sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*a.length);
	arr2 = (int *)malloc(sizeof(int)*b.length);
	arr1[0] = 7;
	arr2[0] = 7;
	a.base = arr1;
	b.base = arr2;
	assertEqual(areEqual(a,b),1);
}
void test_returns_1_for_equal_size_(){
	int *arr1, *arr2;
	ArrayUtil a,b;
	a.length = 1;
	b.length = 1;
	a.typeSize = sizeof(int);
	b.typeSize = sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*a.length);
	arr2 = (int *)malloc(sizeof(int)*b.length);
	arr1[0] = 'a';
	arr2[0] = 'a';
	a.base = arr1;
	b.base = arr2;
	assertEqual(areEqual(a,b),1);
}

void test_returns_a_array(){
	ArrayUtil result = create(sizeof(int),2);
	int* base = (int*)result.base;
	assertEqual(base[0],0);
	assertEqual(base[1],0);
}

void test_resize_returns_new_incremented_array(){
	int *arr1,*res;
	ArrayUtil util,result;
	util.length = 2;
	util.typeSize = sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*util.length);
	arr1[0] = 1;
	arr1[1] = 2;
	util.base = arr1;
	result = resize(util,3);
	assertEqual(((int* )result.base)[0],0);
	assertEqual(((int* )result.base)[1],0);
	assertEqual(((int* )result.base)[2],0);
	free(util.base);
}
void test_resize_returns_new_shrinked_array(){
	int *arr1,*res;
	ArrayUtil util,result;
	util.length = 4;
	util.typeSize = sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*util.length);
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	arr1[3] = 4;
	util.base = arr1;
	result = resize(util,3);
	assertEqual(((int* )result.base)[0],0);
	assertEqual(((int* )result.base)[1],0);
	assertEqual(((int* )result.base)[2],0);
	free(util.base);
}



void test_findIndex_returns_index_if_element_is_present(){
	int *arr1,element = 3,result;
	ArrayUtil util;
	util.length = 4;
	util.typeSize = sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*util.length);
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	arr1[3] = 4;
	util.base =  arr1;
	result = findIndex(util,&element);
	assertEqual(result,2);
	free(util.base);

}

void test_findIndex_returns_minus_one_if_element_is_present(){
	int *arr1,element = 7,result;
	ArrayUtil util;
	util.length = 4;
	util.typeSize = sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*util.length);
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	arr1[3] = 4;
	util.base =  arr1;
	result = findIndex(util,&element);
	assertEqual(result,-1);
	free(util.base);

}

void test_findIndex_returns_minus_one_if_character_is_not_present(){
	int *arr1,result;
	char element = 'g';
	ArrayUtil util;
	util.length = 4;
	util.typeSize = sizeof(char);
	arr1 = (int *)malloc(sizeof(char)*util.length);
	arr1[0] = 'a';
	arr1[1] = 'b';
	arr1[2] = 'c';
	arr1[3] = 'd';
	util.base =  arr1;
	result = findIndex(util,&element);
	assertEqual(result,-1);
	free(util.base);

}
