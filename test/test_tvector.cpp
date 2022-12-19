#include "Matrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(10);
}



TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-3);
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(8);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  TDynamicVector<int> a(3);
  TDynamicVector<int> b(a);
  EXPECT_TRUE(a == b);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(a);
  EXPECT_FALSE(&a[0] == &b[0]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(6);
  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
  TDynamicVector<int> a(1);
  ASSERT_ANY_THROW(a.at(-1) = 2);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
  TDynamicVector<int> a(1);
  ASSERT_ANY_THROW(a.at(3) = 2);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
  TDynamicVector<int> a(1);
  ASSERT_NO_THROW(a = a);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(5);
  ASSERT_NO_THROW(a = b);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(6);
  size_t s = a.size();
  a = b;
  EXPECT_TRUE(s != a.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
  TDynamicVector<int> a(5);
  TDynamicVector<int> b(6);
  ASSERT_NO_THROW(a = b);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{

  TDynamicVector<int> a(1);
  TDynamicVector<int> b(1);
  a = b;
  EXPECT_TRUE(a == b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
  TDynamicVector<int> a(1);
  EXPECT_TRUE(a == a);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
  TDynamicVector<int> a(1);
  TDynamicVector<int> b(2);

  EXPECT_FALSE(a == b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
  TDynamicVector<int> a(1);
  int sc = 3;
  
  ASSERT_NO_THROW(a + sc);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  TDynamicVector<int> a(1);
  int sc = 3;
  
  ASSERT_NO_THROW(a - sc);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
  TDynamicVector<int> a(1);
  int sc = 3;
  
  ASSERT_NO_THROW(a * sc);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
  TDynamicVector<int> a(1);
  TDynamicVector<int> b(1);

  ASSERT_NO_THROW(a + b);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  TDynamicVector<int> a(1);
  TDynamicVector<int> b(2);

  ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  TDynamicVector<int> a(1);
  TDynamicVector<int> b(1);

  ASSERT_NO_THROW(a - b);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  TDynamicVector<int> a(1);
  TDynamicVector<int> b(2);

  ASSERT_ANY_THROW(a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
  TDynamicVector<int> a(1);
  TDynamicVector<int> b(1);

  ASSERT_NO_THROW(a * b);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  

  TDynamicVector<int> a(1);
  TDynamicVector<int> b(2);

  ASSERT_ANY_THROW(a * b);
}

