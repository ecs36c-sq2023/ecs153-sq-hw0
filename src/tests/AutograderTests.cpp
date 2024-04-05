extern "C" {
#include "calculator.h"
}
#include <gtest/gtest.h>

char result_str[30];  // Used to store the float as a string

TEST(AutograderTests, TestBasic) {
  Calculator *cal = init_calculator();
  strcpy(cal->expression, "1-3-5-6");
  float result = parseExpression(*cal);
  sprintf(result_str, "%.3f", result);
  EXPECT_STREQ(result_str, "-13.000");
  free_Calculator(cal);
}

TEST(AutograderTests, TestBasic2) {
  Calculator *cal = init_calculator();
  strcpy(cal->expression, "1+7-8*4");
  float result = parseExpression(*cal);
  sprintf(result_str, "%.3f", result);
  EXPECT_STREQ(result_str, "-24.000");
  free_Calculator(cal);
  
  // Add more tests here
}