#include "expr_assert.h"
#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>

void test_resize_returns_new_incremented_array(){
	int* arr1 = (int*)malloc(sizeof(int)*2);
	int array[] = {1,200,0};
	void *array_ptr = (void*)array;
	ArrayUtil result;
	ArrayUtil util = {arr1,2, sizeof(int)};
	ArrayUtil expected = {array_ptr, 3, sizeof(int)};
	arr1[0] = 1;
	arr1[1] = 200;
	result = resize(util,3);
	assertEqual(areEqual(result,expected),1);
	free(util.base);
}

void test_resize_returns_new_shrinked_array(){
	int *arr = (int*)malloc(sizeof(int)*4);
	int array[] = {1,2};
	void * array_ptr = (void*)array;
	ArrayUtil result;
	ArrayUtil util = {arr,4, sizeof(int)};
	ArrayUtil expected = {array_ptr, 2, sizeof(int)};
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	result = resize(util,2);
	assertEqual(areEqual(result,expected),1);
	free(util.base);
}

