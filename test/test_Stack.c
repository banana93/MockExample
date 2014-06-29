#include "unity.h"
#include "Stack.h"
#include "ErrorCode.h"
#include "CException.h"

#define STACK_LENGTH 4
#define STACK_GUARD_SPACES 16

Stack stacks;
int buffer[sizeof(int) * (STACK_LENGTH + STACK_GUARD_SPACES)];

void setUp(void){
	stacks.buffer = buffer;
	stacks.length = STACK_LENGTH;
	stacks.size = 0;
}

void tearDown(void){}

void test_stackIsEmpty_should_return_0_if_the_stack_is_empty()
{
	int result;
	
	result = stackIsEmpty(&stacks);
	TEST_ASSERT_EQUAL(0, result);
}

void test_stackPush_after_1_is_pushed_should_into_buffer_0()
{
	stackPush(&stacks, 1);
	TEST_ASSERT_EQUAL(1, stacks.buffer[0]);
	TEST_ASSERT_EQUAL(1, stacks.size);
	TEST_ASSERT_EQUAL(STACK_LENGTH, stacks.length);
}

void test_stackPush_after_5_and_6_is_pushed_should_place_in_buffer_0_and_1()
{
	stackPush(&stacks, 5);
	stackPush(&stacks, 6);
	TEST_ASSERT_EQUAL(5, stacks.buffer[0]);
	TEST_ASSERT_EQUAL(6, stacks.buffer[1]);
	TEST_ASSERT_EQUAL(2, stacks.size);
	TEST_ASSERT_EQUAL(STACK_LENGTH, stacks.length);
	
}

void test_stackPush_10_11_12_13_14_should_throw_exception()
{
	CEXCEPTION_T err;
	stackNew(STACK_LENGTH);
	Try
	{
		stackPush(&stacks, 10);
		stackPush(&stacks, 11);
		stackPush(&stacks, 12);
		stackPush(&stacks, 13);
		stackPush(&stacks, 14);

	}
	Catch(err)
	{
		
		TEST_ASSERT_EQUAL_MESSAGE(ERR_STACK_FULL, err, "Expect ERR_STACK_FULL_exception.");
		TEST_ASSERT_EQUAL(5, stacks.size);
			
	}
}

void test_stackPop_after_1_is_pushed_it_will_be_pop_out_from_buffer_1_and_inside_the_buffer_1_will_become_value_0()
{
	
	stackPush(&stacks, 1);
	stackPush(&stacks, 2);
	stackPop(&stacks);
	stackPop(&stacks);
	TEST_ASSERT_EQUAL(0, stacks.size);
	TEST_ASSERT_EQUAL(STACK_LENGTH, stacks.length);

}

void test_stackPop_after_pushed_once_pop_twice_should_encounter_ERR_STACK_EMPTY()
{
	CEXCEPTION_T err;
	
	stackNew(STACK_LENGTH);
	stackPush(&stacks,2);
	TEST_ASSERT_EQUAL(2, stackPop(&stacks));
	Try
	{
		stackPop(&stacks);
		TEST_FAIL_MESSAGE("Should have thrown ERR_STACK_EMPTY exception.");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_STACK_EMPTY, err, "Expect ERR_STACK_EMPTY exception.");
		TEST_ASSERT_EQUAL(0, stacks.size);
		
	}

}

	
	