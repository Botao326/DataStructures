//
//  main.cpp
//  SortingSummary
//
//  Created by Tao on 21/12/2016.
//  Copyright © 2016 Botao. All rights reserved.
//

#include <iostream>
#include <vector>
#include "SummarySort.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> nums = {10,6,7,4,2,1,5,8,3,9};
    Solution solution;
    
    solution.QuickSort(nums);

    for(auto i: nums){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
