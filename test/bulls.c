#include "bulls.h"
#include "ctest.h"

CTEST(Menu_true, test_level1)
{
    // Given
    int exp1 = 3;
    int exp2 = 7;
    // When
    int real = Menu('5');

    // Then
    ASSERT_INTERVAL(exp1, exp2, real);
}

CTEST(Menu_false, test_level2)
{
    // Given
    int exp1 = -2;
    int exp2 = 2;
    // When
    int real = Menu('0');

    // Then
    ASSERT_INTERVAL(exp1, exp2, real);
}

CTEST(Menu_boarder, test_level3)
{
    // Given
    int exp1 = 4;
    int exp2 = 10;
    // When
    int real = Menu('4');

    // Then
    ASSERT_INTERVAL(exp1, exp2, real);
}

CTEST(TestLVL_false, test_level4)
{
    // Given
    const int exp1 = -2;
    const int exp2 = 2;
    const int lvl = 2;
    // When
    const int real = TestLVL(lvl);

    // Then
    ASSERT_INTERVAL(exp1, exp2, real);
}

CTEST(TestLVL_border, test_level5)
{
    // Given
    const int exp1 = 4;
    const int exp2 = 6;
    const int lvl = 6;
    // When
    const int real = TestLVL(lvl);

    // Then
    ASSERT_INTERVAL(exp1, exp2, real);
}

CTEST(TestLVL_true, test_level6)
{
    // Given
    const int exp1 = 3;
    const int exp2 = 7;
    const int lvl = 5;
    // When
    const int real = TestLVL(lvl);

    // Then
    ASSERT_INTERVAL(exp1, exp2, real);
}

CTEST(Equal_true, test_level7)
{
    // When
    int result = Menu('5');

    // Then
    const int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(Equal_false, test_level8)
{
    // When
    int result = Menu('7');

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(Equal_true_test, test_level9)
{
    // When
    int result = TestLVL(4);

    // Then
    const int expected = 4;
    ASSERT_EQUAL(expected, result);
}


CTEST(Equal_true_test, test_level10)
{
    // When
    int result = TestLVL(7);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}



