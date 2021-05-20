#include <gtest/gtest.h>
#include <list>
#include "Sort.h"

std::list<int> list1 = {20, 15, 12, 9, 16, 22, 8, 3, 9, 2, 16};
std::list<int> list2 = {1, 4, -20, 14, 22, 7, -8, 66, -22, -1, 4};
std::list<char> list3 = {'c', 'd', 'z', 'h', 'z', 'w', 'q', 'l', 'b', 'a'};

std::list<int> result1 = {2, 3, 8, 9, 9, 12, 15, 16, 16, 20, 22};
std::list<int> result2 = {-22, -20, -8, -1, 1, 4, 4, 7, 14, 22, 66};
std::list<char> result3 = {'a', 'b', 'c', 'd', 'h', 'l', 'q', 'w', 'z', 'z'};

TEST(SortTest, Unsigned)
{
    bubbleSort(list1);

    std::list<int>::iterator it1, it2;
    for (it1 = result1.begin(), it2 = list1.begin(); it1 != result1.end(); ++it1, ++it2)
        EXPECT_EQ(*it1, *it2);
}

TEST(SortTest2, Int)
{
    bubbleSort(list2);

    std::list<int>::iterator it1, it2;
    for (it1 = result2.begin(), it2 = list2.begin(); it1 != result2.end(); ++it1, ++it2)
        EXPECT_EQ(*it1, *it2);
}

TEST(SortTest3, Char)
{
    bubbleSort(list3);

    std::list<char>::iterator it1, it2;
    for (it1 = result3.begin(), it2 = list3.begin(); it1 != result3.end(); ++it1, ++it2)
        EXPECT_EQ(*it1, *it2);
}