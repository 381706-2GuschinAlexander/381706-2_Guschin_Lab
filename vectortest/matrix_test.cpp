#include "Matrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_n)
{
	ASSERT_NO_THROW(TMatrix<int> A(3));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_n)
{
	ASSERT_ANY_THROW(TMatrix<int> A(-3));
}

TEST(TMatrix, can_get_value_in_range)
{
	TMatrix<int> A(3);
	A[0][2] = 10;
	A[1][2] = 5;
	EXPECT_EQ(A[0][2] - A[1][2], 5);
}

TEST(TMatrix, throws_when_get_value_out_of_range)
{
	TMatrix<int> A(3);
	ASSERT_ANY_THROW(A[0][3]);
}

TEST(TMatrix, can_create_matrix_with_matrix)
{
	TMatrix<int> B(1);
	B[0][0] = 12;
	TMatrix<int> A(B);
	EXPECT_EQ(B[0][0],A[0][0]);
}

TEST(TMatrix, can_create_matrix_with_double_vectors)
{
	TVector <TVector<int> > A(1, 0);
	TVector<int> C(1, 0);
	A[0] = C;
	A[0][0] = 1;
	TMatrix<int> B(A);
	EXPECT_EQ(B[0][0] , 1);
}

TEST(TMatrix, matrix_eq_with_diff_lenght)
{
	TMatrix<int> A(2);
	TMatrix<int> B(3);

	EXPECT_EQ(A == B, false);
}

TEST(TMatrix, matrix_eq_with_diff_matrix)
{
  TMatrix<int> A(2);
  TMatrix<int> B(2);
  A[0][0] = 0;
  A[0][1] = 1;
  A[1][1] = 1;
  B[0][0] = 0;
  B[0][1] = 2;
  B[1][1] = 2;

	EXPECT_EQ(A == B, false);
}

TEST(TMatrix, matrix_eq_with_same_matrix)
{
  TMatrix<int> A(2);
  TMatrix<int> B(2);
  A[0][0] = 0;
  A[0][1] = 1;
  A[1][1] = 1;
  B[0][0] = 0;
  B[0][1] = 1;
  B[1][1] = 1;
	EXPECT_EQ(A == B, true);
}

TEST(TMatrix, matrix_neq_with_diff_lenght)
{
  TMatrix<int> A(2);
  TMatrix<int> B(3);

  EXPECT_EQ(A != B, true);
}

TEST(TMatrix, matrix_neq_with_diff_matrix)
{
  TMatrix<int> A(2);
  TMatrix<int> B(2);
  A[0][0] = 0;
  A[0][1] = 1;
  A[1][1] = 1;
  B[0][0] = 0;
  B[0][1] = 2;
  B[1][1] = 2;

  EXPECT_EQ(A != B, true);
}

TEST(TMatrix, matrix_neq_with_same_matrix)
{
  TMatrix<int> A(2);
  TMatrix<int> B(2);
  A[0][0] = 0;
  A[0][1] = 1;
  A[1][1] = 1;
  B[0][0] = 0;
  B[0][1] = 1;
  B[1][1] = 1;
  EXPECT_EQ(A != B, false);
}

TEST(TMatrix, can_eq_matrix)
{
	TMatrix<int> C(1);
	C[0][0] = 1;
	
	TMatrix<int> B(3);
	B = C;

	EXPECT_EQ(B[0][0], 1);
}

TEST(TMatrix, throws_when_plus_with_invalid_matrix)
{
	TMatrix<int> A(3);
	TMatrix<int> B(2);

	ASSERT_ANY_THROW(A + B);
}

TEST(TMatrix, plus_with_matrix)
{
	TMatrix<int> A(2);
	TMatrix<int> B(2);
	A[0][0] = 0;
  A[0][1] = 1;
  A[1][1] = 1;
  B[0][0] = 0;
  B[0][1] = 2;
  B[1][1] = 2;
	EXPECT_EQ((A + A) == B, 1);
}

TEST(TMatrix, throws_when_minus_with_invalid_matrix)
{
	TMatrix<int> A(3);
	TMatrix<int> B(2);

	ASSERT_ANY_THROW(A - B);
}

TEST(TMatrix, minus_with_matrix)
{
	TMatrix<int> A(1);
	TMatrix<int> B(1);

	A[0][0] = 4;
	B[0][0] = 3;
	EXPECT_EQ((A - B)[0][0], 1);
}

TEST(TMatrix, throws_when_multiply_with_invalid_matrix)
{
	TMatrix<int> A(2);
	TMatrix<int> B(1);

	ASSERT_ANY_THROW(A * B);
}

TEST(TMatrix, multiply_with_matrix)
{
	TMatrix<int> A(2);
	TMatrix<int> B(2);
	TMatrix<int> C(2);
  A[0][0] = 1;
  A[0][1] = 1;
  A[1][1] = 1;
  B[0][0] = 1;
  B[0][1] = 2;
  B[1][1] = 1;
  C = A;
  bool d = (A * C == B ? 1 : 0);
  EXPECT_EQ(d, 1);
}



TEST(TMatrix, invert)
{
  TMatrix<int> A(3);
  TMatrix<int> B(3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][1] = 1;
  A[1][2] = 2;
  A[2][2] = 1;
  

  B[0][0] = 1;
  B[0][1] = 0;
  B[0][2] = 0;
  B[1][1] = 1;
  B[1][2] = 0;
  B[2][2] = 1;

  EXPECT_EQ(A/A == B , 1);
}