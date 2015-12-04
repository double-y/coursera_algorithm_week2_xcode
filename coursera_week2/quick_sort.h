//
//  quick_sort.h
//  coursera_week2
//
//  Created by 安田洋介 on 12/3/15.
//  Copyright © 2015 安田洋介. All rights reserved.
//

#ifndef quick_sort_h
#define quick_sort_h

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

enum PIVOT_TYPE{FIRST, LAST, COMPARE};

int quick_sort_swap_count(std::vector<int> vec, PIVOT_TYPE pivot_type);
int exec_quick_sort_swap_count(std::string file_name, PIVOT_TYPE pivot_type);

#endif /* quick_sort_h */
