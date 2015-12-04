//
//  quick_sort.cpp
//  coursera_week2
//
//  Created by 安田洋介 on 12/3/15.
//  Copyright © 2015 安田洋介. All rights reserved.
//

#include "quick_sort.h"

using namespace std;

int median_of_three(vector<int> vec){
    int mid = (vec.size()-1)/2;
    int mid_value = vec[mid];
    bool first_mid_last = (vec[0] < mid_value && mid_value < vec[vec.size()-1]);
    bool mid_first_last = (mid_value < vec[0] && vec[0] < vec[vec.size()-1]);
    bool last_first_mid = (vec[vec.size()-1] < vec[0] && vec[0] < mid_value);
    bool last_mid_first = (vec[vec.size()-1] < mid_value && mid_value < vec[0]);
    if(first_mid_last || last_mid_first){
        return mid;
    }else if(mid_first_last || last_first_mid){
        return 0;
    }else{
        return vec.size()-1;
    }
}

int quick_sort_swap_count(vector<int> vec, PIVOT_TYPE pivot_type){
    if(vec.size() <= 1) return 0;
    int i=0;
    int pivot_val;
    
    switch (pivot_type) {
        case FIRST:
            pivot_val = vec[0];
            break;
        case LAST:
            iter_swap(vec.begin(), vec.end()-1);
            pivot_val = vec[0];
            break;
        case COMPARE:
            int position = median_of_three(vec);
            iter_swap(vec.begin(), vec.begin()+position);
            pivot_val = vec[0];
            break;
    }
    
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
        swap_count += quick_sort_swap_count(prev_vec, pivot_type);
    }
    if(i<vec.size()-1){
        vector<int> back_vec (vec.begin() + i + 1, vec.end());
        swap_count += quick_sort_swap_count(back_vec, pivot_type);
    }
    return swap_count;
}

int exec_quick_sort_swap_count(string file_name, PIVOT_TYPE pivot_type){
    ifstream inFile(file_name);
    int number;
    vector<int> input_vec;
    while(inFile >> number){
        input_vec.push_back(number);
    }
    return quick_sort_swap_count(input_vec, pivot_type);
}
