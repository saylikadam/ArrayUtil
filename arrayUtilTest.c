#include "expr_assert.h"
#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>

void test_areEqual_returns_0_for_unequal_typesize(){
	ArrayUtil a,b;
	a.typeSize = sizeof(int);
	b.typeSize = sizeof(char);
	assertEqual(areEqual(a,b),0);
}

void test_areEqual_returns_1_for_same_element_on_same_position(){
	int arr1[] = {7},arr2[] = {7};
	ArrayUtil a = { arr1, sizeof(int), 1};
	ArrayUtil b = { arr2, sizeof(int), 1}; 
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_1_for_two_same_array_with_integer_value(){
	int arr1[] = {1,2,3},arr2[] = {1,2,3};
	ArrayUtil a = { arr1, sizeof(int), 3};
	ArrayUtil b = { arr2, sizeof(int), 3}; 
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_1_for_two_same_array_with_float_value(){
	float arr1[] = {1.1,2.2,3.3},arr2[] = {1.1,2.2,3.3};
	ArrayUtil a = { arr1, sizeof(float), 3};
	ArrayUtil b = { arr2, sizeof(float), 3}; 
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_1_for_two_same_array_of_character_value(){
	int arr1[] = {'a'},arr2[] = {'a'};
	ArrayUtil a = { arr1, sizeof(int), 1};
	ArrayUtil b = { arr2, sizeof(int), 1}; 
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_0_for_two_arrays_with_float_value(){
	float arr1[] = {1.1,2.2,3.3},arr2[] = {1.3,2.7,3.3};
	ArrayUtil a = { arr1, sizeof(float), 3};
	ArrayUtil b = { arr2, sizeof(float), 3}; 
	assertEqual(areEqual(a,b),0);
}


void test_areEqual_returns_0_for_two_arrays_of_character_value(){
	int arr1[] = {'a'},arr2[] = {'c'};
	ArrayUtil a = { arr1, sizeof(int), 1};
	ArrayUtil b = { arr2, sizeof(int), 1}; 
	assertEqual(areEqual(a,b),0);
}


void test_areEqual_returns_0_for_two_arrays_with_integer_value(){
	int arr1[] = {7},arr2[] = {56};
	ArrayUtil a = { arr1, sizeof(int), 1};
	ArrayUtil b = { arr2, sizeof(int), 1}; 
	assertEqual(areEqual(a,b),0);
}

void test_create_returns_a_array(){
	ArrayUtil result = create(sizeof(int),2);
	int* base = (int*)result.base;
	assertEqual(base[0],0);
	assertEqual(base[1],0);
	free(result.base);
}

void test_dispose_will_destroy_the_allocated_space(){
	int *arr1;
	ArrayUtil util;
	util.length = 4;
	util.typeSize = sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*util.length);
	util.base = arr1;
	dispose(util);
}

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

void test_findIndex_returns_index_if_element_is_present(){
	int arr1[] = {1,2,3,4},element = 3,result;
	ArrayUtil util = {(void *)arr1 ,4, sizeof(int)};
	result = findIndex(util,&element);
	assertEqual(result,2);
}

void test_findIndex_returns_minus_one_if_element_is_present(){
	int arr1[] = {1,2,3,4},element = 7,result;
	ArrayUtil util;
	util.length = 4;
	util.typeSize = sizeof(int);
	util.base =  arr1;
	result = findIndex(util,&element);
	assertEqual(result,-1);
}

void test_findIndex_returns_index_if_element_is_present_for_float(){
	float arr1[] = {1.1,2.2,3.3,4.4},element = 4.4;
	int result;
	ArrayUtil util;
	util.length = 4;
	util.typeSize = sizeof(float);
	util.base =  arr1;
	result = findIndex(util,&element);
	assertEqual(result,3);
}

void test_findIndex_returns_minus_one_if_element_is_present_for_float(){
	float arr1[] = {1.1,2.2,3.3,4.4},element = 7.7,result;
	ArrayUtil util;
	util.length = 4;
	util.typeSize = sizeof(float);
	util.base =  arr1;
	result = findIndex(util,&element);
	assertEqual(result,-1);
}