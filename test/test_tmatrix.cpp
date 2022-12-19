#include "Matrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(3));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-3));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(3);
  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
  TDynamicMatrix<int> m(4);
  TDynamicMatrix<int> n(m);

  EXPECT_TRUE(m == n);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
  TDynamicMatrix<int> m(3);
  TDynamicMatrix<int> n(m);

  EXPECT_NE(&m[0], &n[0]);
}

TEST(TDynamicMatrix, can_get_size)
{
  TDynamicMatrix<int> m(2);

  EXPECT_EQ(m.size(), 2);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
  TDynamicMatrix<int> m(3);
  m[0][0] = 2;
  EXPECT_EQ(2, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
  TDynamicMatrix<int> m(2);
  ASSERT_ANY_THROW(m.at(-1).at(0) = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
  TDynamicMatrix<int> m(2);
  ASSERT_ANY_THROW(m.at(3).at(0) = 2);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
  TDynamicMatrix<int> m(2);
  ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> n(2);
  ASSERT_NO_THROW(m = n);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> n(3);
  m = n;
  EXPECT_EQ(m.size(), 3);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> n(3);
  ASSERT_NO_THROW(m = n);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> n(m);
  EXPECT_TRUE(m == n);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
  TDynamicMatrix<int> m(2);
  EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> n(3);
  EXPECT_FALSE(m == n);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> n(2);
  ASSERT_NO_THROW(m + n);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> n(3);
  ASSERT_ANY_THROW(m + n);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> n(2);
  ASSERT_NO_THROW(m - n);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> n(3);
  ASSERT_ANY_THROW(m - n);
}

