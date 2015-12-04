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
    int result1 = exec_quick_sort_swap_count("test1.txt");
    REQUIRE(result1 == 1);
    int result2 = exec_quick_sort_swap_count("test2.txt");
    REQUIRE(result2 == 10);
    int result3 = exec_quick_sort_swap_count("test3.txt");
    REQUIRE(result3 == 4);
    int result4 = exec_quick_sort_swap_count("test4.txt");
    REQUIRE(result4 == 18);
}

TEST_CASE("real question"){
    int result = exec_quick_sort_swap_count("QuickSort.txt");
    REQUIRE(result == 162085);
}
