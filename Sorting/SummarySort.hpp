//
//  SummarySort.hpp
//  SortingSummary
//
//  Created by Tao on 21/12/2016.
//  Copyright © 2016 Botao. All rights reserved.
//

#ifndef SummarySort_hpp
#define SummarySort_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> BubbleSort(vector<int> nums);
    vector<int> InsertSort(vector<int> nums);
    vector<int> ShellSort(vector<int> nums);
    vector<int> SelectSort(vector<int> nums);
    void MergeSort(vector<int> & nums);
    void HeapSort(vector<int> & nums);
    void QuickSort(vector<int> & nums);
};


#endif /* SummarySort_hpp */
