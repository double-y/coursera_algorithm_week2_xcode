//
//  main.cpp
//  test_project
//
//  Created by 安田洋介 on 12/3/15.
//  Copyright © 2015 安田洋介. All rights reserved.
//
#define CATCH_CONFIG_MAIN 
#include "catch.hpp"

#include "quick_sort.h"

using namespace std;

TEST_CASE("quick_sort_swap_count test"){
    int result1 = exec_quick_sort_swap_count("test1.txt", FIRST);
    REQUIRE(result1 == 1);
    int result2 = exec_quick_sort_swap_count("test2.txt", FIRST);
    REQUIRE(result2 == 10);
    int result3 = exec_quick_sort_swap_count("test3.txt", FIRST);
    REQUIRE(result3 == 4);
    int result4 = exec_quick_sort_swap_count("test4.txt", FIRST);
    REQUIRE(result4 == 18);
}

TEST_CASE("real question1"){
    int result = exec_quick_sort_swap_count("QuickSort.txt", FIRST);
    REQUIRE(result == 162085);
}

TEST_CASE("real question2"){
    int result = exec_quick_sort_swap_count("QuickSort.txt", LAST);
    REQUIRE(result == 164123);
}

TEST_CASE("real question3"){
    int result = exec_quick_sort_swap_count("QuickSort.txt", COMPARE);
    REQUIRE(result == 138382);
}