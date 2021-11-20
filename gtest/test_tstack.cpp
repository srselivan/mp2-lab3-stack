#include "gtest.h"

#include "..\TStack.h"

TEST(TStack, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> s(20));
}

TEST(TStack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> s(-1));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> sc;

	ASSERT_NO_THROW(TStack<int> s(sc));
}

TEST(TStack, can_push_and_pop_element)
{
	TStack<int> s;
	s.Push(2);

	EXPECT_EQ(2, s.Pop());
}

TEST(TStack, can_get_top)
{
	TStack<int> s;
	s.Push(2);

	EXPECT_EQ(2, s.Top());
}

TEST(TStack, cant_push_element_in_full_stack)
{
	TStack<int> s(1);
	s.Push(2);

	ASSERT_ANY_THROW(s.Push(2));
}

TEST(TStack, cant_pop_element_from_empty_stack)
{
	TStack<int> s(1);

	ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, can_clear_stack)
{
	TStack<int> s;
	s.Push(2);
	s.Clear();

	EXPECT_TRUE(s.Is_empty());
}

TEST(TStack, compare_equal_stacks_return_true)
{
	TStack<int> s;
	s.Push(2);
	TStack<int> s1;
	s1.Push(2);

	EXPECT_TRUE(s == s1);
}

TEST(TStack, compare_not_equal_stacks_return_false)
{
	TStack<int> s;
	s.Push(2);
	TStack<int> s1;
	s1.Push(2);
	s1.Push(3);

	EXPECT_FALSE(s == s1);
}
