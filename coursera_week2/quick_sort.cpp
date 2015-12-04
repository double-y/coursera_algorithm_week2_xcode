//
//  quick_sort.cpp
//  coursera_week2
//
//  Created by 安田洋介 on 12/3/15.
//  Copyright © 2015 安田洋介. All rights reserved.
//

#include "quick_sort.h"

using namespace std;

int quick_sort_swap_count(vector<int> vec){
    if(vec.size() <= 1) return 0;
    int i=0;
    int pivot_val = vec[0];
    for (int j=1; j<vec.size(); j++){
        if(vec[j] < pivot_val){
            iter_swap(vec.begin()+i+1, vec.begin()+j);
            i++;
        }
    }
    
    iter_swap(vec.begin(), vec.begin()+i);
    
    int swap_count = vec.size() - 1;
    
    if(i > 0){
        vector<int> prev_vec (vec.begin(), vec.begin() + i);
        swap_count += quick_sort_swap_count(prev_vec);
    }
    if(i<vec.size()-1){
        vector<int> back_vec (vec.begin() + i + 1, vec.end());
        swap_count += quick_sort_swap_count(back_vec);
    }
    return swap_count;
}

int exec_quick_sort_swap_count(string file_name){
    ifstream inFile(file_name);
    int number;
    vector<int> input_vec;
    while(inFile >> number){
        input_vec.push_back(number);
    }
    return quick_sort_swap_count(input_vec);
}
