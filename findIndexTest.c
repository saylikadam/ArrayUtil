#include "expr_assert.h"
#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>

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

// void test_findIndex_returns_minus_one_if_character_is_not_present(){
// 	int arr1[] = {'a','b','c','d'},result;
// 	char element = 'g';
// 	ArrayUtil util;
// 	util.length = 4;
// 	util.typeSize = sizeof(char);
// 	util.base =  arr1;
// 	result = findIndex(util,&element);
// 	assertEqual(result,-1);
// }

// void test_findIndex_returns_index_if_character_is_present(){
// 	int arr1[] = {'a','b','c','d'},result;
// 	char element = 'c';
// 	ArrayUtil util;
// 	util.length = 4;
// 	util.typeSize = sizeof(char);
// 	util.base =  arr1;
// 	result = findIndex(util,&element);
// 	assertEqual(result,2);
// }

// void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
// int isEven(void *item ,void *hint){
// 	int *number = (int*)item;
// 	if( *number % 2 == 0 )
// 		return 1;
// 	return 0;
// }

// void test_findFirst_returns_first_element_for_match_for_int_value(){
// 	int arr1[] = {1,2,3,4}; 
// 	ArrayUtil util = { (void *)arr1 , 4, sizeof(int)};
// 	int *result;
// 	result = (int *)findFirst(util,isEven,0);
// 	assertEqual(result,2);

// }


