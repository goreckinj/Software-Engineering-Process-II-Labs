#include "BinarySearch.h"
#include <gtest/gtest.h>

//Normal Searching Whole Numbers
TEST (binarySearch, wholeNumbers)
{
  double wholeNumbers[9] = {8, 12, 67, 112, 456, 567, 890, 1001, 2011};
  EXPECT_EQ(true, contains(12, wholeNumbers, 9));
}

//Normal Searching NonWhole Numbers
TEST (binarySearch, nonWholeNumbers)
{
  double nonWholeNumbers[11] = {2.8, 4.6, 6, 8, 10, 12, 16, 18, 22.1, 78.3, 111.6};
  EXPECT_EQ(true, contains(78.3, nonWholeNumbers, 11));
}

//Boundary Checking End Of Array Element
TEST (binarySearch, endArrayCheck)
{
  double nonWholeNumbers[11] = {2.8, 4.6, 6, 8, 10, 12, 16, 18, 22.1, 78.3, 111.6};
  EXPECT_EQ(true, contains(111.6, nonWholeNumbers, 11));
}

//Boundary Checking Front Of Array Element
TEST (binarySearch, frontArrayCheck)
{
  double nonWholeNumbers[11] = {2.8, 4.6, 6, 8, 10, 12, 16, 18, 22.1, 78.3, 111.6};
  EXPECT_EQ(true, contains(2.8, nonWholeNumbers, 11));
}

//Checking If An Array Doesn't Contain A Value Inside Boundary
TEST (binarySearch, arrayDoesntContainInside)
{
  double nonWholeNumbers[11] = {2.8, 4.6, 6, 8, 10, 12, 16, 18, 22.1, 78.3, 111.6};
  EXPECT_EQ(false, contains(8.7, nonWholeNumbers, 11));
}

//Checking If An Array Doesn't Contain A Value Outside Boundary
TEST (binarySearch, arrayDoesntContainOutside)
{
  double nonWholeNumbers[11] = {2.8, 4.6, 6, 8, 10, 12, 16, 18, 22.1, 78.3, 111.6};
  //Lower End
  EXPECT_EQ(false, contains(-3.1, nonWholeNumbers, 11));
  //Upper End
  EXPECT_EQ(false, contains(556.2, nonWholeNumbers, 11));
}

//Checking If Search Can Handle One Element Array
TEST (binarySearch, oneElement)
{
  double number[1] = {5.4};
  EXPECT_EQ(true, contains(5.4, number, 1));
}

//Checking if Search Can Handle No Element Array
TEST (binarySearch, noLengthArray)
{
  double emptyArray[0] = {};
  EXPECT_EQ(false, contains(1.2, emptyArray, 0));
}

//Checking If Search Can Handle Length Greater Than Actual Array Size
TEST (binarySearch, smallerThanExpectedDoesntContain)
{
  double smallArray[3] = {2.1, 3.4, 5.6};
  EXPECT_EQ(false, contains(9.7, smallArray, 6));
}

//Checking If Search Can Handle An Array With A Max Size, But Not All
//Elements Are Filled In
TEST (binarySearch, unfinishedSize)
{
  double numbers[7] = {2.3, 5.6, 4.9};
  EXPECT_EQ(false, contains(5.6, numbers, 7));
}

/******************************************************************************/
//Main Method
int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
