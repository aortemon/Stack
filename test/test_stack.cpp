#include "../gtest/gtest.h"
#include "../include/stack.h"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(Stack, default_ctor_creates_object) {
	ASSERT_NO_THROW(Stack<int> st());
}

TEST(Stack, size_ctor_creates_object) {
	ASSERT_NO_THROW(Stack<int> st(15));
}

TEST(Stack, size_ctor_throw_when_negative_length) {
	ASSERT_ANY_THROW(Stack<int> st(-5));
}

TEST(Stack, push_method_adds_element) {
	Stack<int> st;
	ASSERT_NO_THROW(st.push(15));
}

TEST(Stack, copy_ctor_creates_new_object) {
	Stack<int> st;
	st.push(15);
	st.push(25);

	Stack<int> exp(st);

	st.pop();

	EXPECT_NE(exp.top(), st.top());
}

TEST(Stack, get_size_returns_correct_length) {
	Stack<int> st(8);
	st.push(1); st.push(2);
	EXPECT_EQ(2, st.getSize());
}

TEST(Stack, overflowing_stack_is_expanding) {
	Stack<int> st(3);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	EXPECT_NE(3, st.getSize());
}

TEST(Stack, is_empty_returns_true_on_empty_stack) {
	Stack<int> st;
	EXPECT_EQ(st.isEmpty(), true);
}

TEST(Stack, is_empty_returns_false_on_non_empty_stack) {
	Stack<int>st(2);
	st.push(2);
	EXPECT_EQ(st.isEmpty(), false);
}

TEST(Stack, throws_when_call_top_on_empty_stack) {
	Stack<int> st;
	ASSERT_ANY_THROW(st.top());
}

TEST(Stack, throws_when_call_pop_on_empty_stack) {
	Stack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(Stack, top_returns_last_pushed_elem) {
	Stack<int> st(2);
	st.push(1); st.push(2);
	EXPECT_EQ(st.top(), 2);
}

TEST(Stack, pop_deletes_last_pushed_element) {
	Stack<int> st(2);
	st.push(1); st.push(2);
	st.pop();
	EXPECT_EQ(st.top(), 1);
}

TEST(Stack, equality_operator_returns_true_on_same_stacks_of_same_length) {
	Stack<int> st1(3), st2(3);
	st1.push(3);
	st2.push(3);
	EXPECT_TRUE(st1 == st2);
}

TEST(Stack, equality_operator_returns_true_on_same_stacks_of_different_length) {
	Stack<int> st1(3), st2(5);
	st1.push(3);
	st2.push(3);
	EXPECT_TRUE(st1 == st2);
}

TEST(Stack, equality_operator_returns_true_on_copied_stacks) {
	Stack<int> st1(3);
	st1.push(1); st1.push(2);

	Stack<int> st2(st1);
	EXPECT_TRUE(st1 == st2);

}