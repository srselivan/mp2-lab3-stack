#include "gtest.h"

#include "..\TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator c);
}

TEST(TCalculator, can_set_and_get_expression)
{
	TCalculator c;
	c.SetExpr("2 + ((2)");

	EXPECT_EQ(c.GetExpr(), "2 + ((2)");
}

TEST(TCalculator, cant_calculate_incorrect_expression)
{
	TCalculator c;
	c.SetExpr("2 + ((2)");

	ASSERT_ANY_THROW(c.calc());
}

TEST(TCalculator, can_calculate_correct_expression)
{
	TCalculator c;
	c.SetExpr("2 + (2)");

	EXPECT_EQ(c.calc(), 4);
}

TEST(TCalculator, can_calculate_correct_expression_with_trigonometric_functions)
{
	TCalculator c;
	c.SetExpr("2 + cos(2) + sin(2^6) + tan(7*8 + (2 - 3))");
	double res_expr = 2 + cos(2) + sin(pow(2, 6)) + tan(7 * 8 + (2 - 3));

	EXPECT_EQ(c.calc(), res_expr);
}

TEST(TCalculator, cant_devide_by_zero)
{
	TCalculator c;
	c.SetExpr("2 / 0");

	ASSERT_ANY_THROW(c.calc());
}