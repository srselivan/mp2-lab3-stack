#include "gtest.h"

#include "..\TStack.h"

TEST(TStack, can_create)
{
  ASSERT_NO_THROW(TStack<int> s);
}
