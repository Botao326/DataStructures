//
//  BubbleSort.cpp
//  SortingSummary
//
//  Created by Tao on 21/12/2016.
//  Copyright © 2016 Botao. All rights reserved.
//

#include "SummarySort.hpp"
#include <vector>
#include <algorithm>
using namespace std;

/*
 *  Bubble Sort without improving
 *  Time Complexity O(n^2)
 *  Space Complexity O(1)
 *
 */
vector<int> Solution::BubbleSort(vector<int> nums){
    if (nums.empty()) return nums;
    
    for(int i = 0; i < nums.size(); ++i){
        for(size_t j = nums.size()-1; j > i; --j){
            if (nums[i] > nums[j]) swap(nums[i], nums[j]);
        }
    }

    return nums;
};

/*
 *  Insert Sort without improving
 *  Time Complexity O(n^2)
 *  Space Complexity O(1)
 *
 */
vector<int> Solution::InsertSort(vector<int> nums){
    if (nums.empty()) return nums;
    
    for(int i = 1; i < nums.size(); ++i){
        if (nums[i] < nums[i-1]){
            int tmp = nums[i];
            int j = 0;
            for(j = i - 1; j >= 0 && nums[j] > tmp; --j){
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }
    
    return nums;
};

/*
 *  Shell Sort without improving
 *  Time Complexity O(nlogn)
 *  Space Complexity O(1)
 *
 */
vector<int> Solution::ShellSort(vector<int> nums){
    if (nums.empty()) return nums;
    
    for(size_t gap = nums.size(); gap > 0; gap /= 2){
        for (int i = 0; i < nums.size(); i += gap){
            int temp = nums[i];
            int j;
            for(j = i; j >= gap && temp < nums[j-gap]; j -= gap){
                nums[j] = nums[j-gap];
            }
            nums[j] = temp;
        }
    }
    
    return nums;
};


/*
 *  Selection Sort without improving
 *  Time Complexity O(n^2)
 *  Space Complexity O(1)
 *
 */
vector<int> Solution::SelectSort(vector<int> nums){
    if (nums.empty()) return nums;
    
    for(int i = 0; i < nums.size(); ++i){
        int index = i;
        for(int j = i+1; j < nums.size(); ++j){
            if (nums[j] < nums[index]){
                index = j;
            }
        }
        if (index != i)
            swap(nums[i], nums[index]);
    }
    
    return nums;
};

/*
 *  Merge Sort without improving
 *  Time Complexity O(nlogn)
 *  Space Complexity O(1)
 *
 */

void Merge(vector<int> & nums, size_t left, size_t mid, size_t right){
    vector<int> tmp(right-left+1);
    
    size_t i = left;
    size_t j = mid + 1;
    size_t k = 0;
    
    while(i <= mid && j <= right){
        if (nums[i] <= nums[j]){
            tmp[k++] = nums[i++];
        }
        else
            tmp[k++] = nums[j++];
    }
    
    while(i <= mid){
        tmp[k++] = nums[i++];
    }
    while(j <= right){
        tmp[k++] = nums[j++];
    }
    
    for(int p = 0; p < tmp.size(); ++p){
        nums[left+p] = tmp[p];
    }
}

void Merge_Sort(vector<int> & nums, size_t left, size_t right){
    if (left >= right)
        return;
    
    size_t mid = (left + right) / 2;
    
    Merge_Sort(nums, left, mid);
    Merge_Sort(nums, mid+1, right);
    Merge(nums, left, mid, right);
    
};

void Solution::MergeSort(vector<int> & nums){
    Merge_Sort(nums, 0, nums.size()-1);
};

/*
 *  HeapSort
 *
 *  Time Complexity O(nlogn)
 *  Space Complexity O(1)
 */
void Heap_Adjust(vector<int> &nums, int start, int end){
    int parent = start;
    int child = parent * 2 + 1;
    while(child <= end){
        if (child + 1 <= end && nums[child] < nums[child + 1]){
            child++;
        }
        
        if (nums[parent] < nums[child]){
            swap(nums[parent], nums[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        
        else
            break;
    }
}

void Solution::HeapSort(vector<int> & nums){
    for(int i = (int)(nums.size()-2)/2; i >= 0; i--){
        Heap_Adjust(nums, i, (int)nums.size()-1);
    }
    for(int i = (int)(nums.size()-1); i >= 0; i--){
        swap(nums[i], nums[0]);
        Heap_Adjust(nums, 0, i-1);
    }
};

/*
 *  QuickSort implementation
 *
 *  Time Complexity O(nlogn)
 *  Space Complexity O(1)
 */
int partition(vector<int> &nums, int left, int right){
    int pivot_val = nums[left];
    int pivot = left;
    for (int i = left+1; i <= right; ++i){
        if (nums[i] < pivot_val){
            pivot++;
            if(pivot != i){
                swap(nums[i], nums[pivot]);
            }
        }
    }
    nums[left] = nums[pivot];
    nums[pivot] = pivot_val;
    
    return pivot;
}


void quick_Sort(vector<int> &nums, int left, int right){
    if (left < right){
        int pivot = partition(nums, left, right);
        quick_Sort(nums, left, pivot - 1);
        quick_Sort(nums, pivot + 1, right);
    }
}

void Solution::QuickSort(vector<int> & nums){
    quick_Sort(nums, 0, (int)(nums.size()-1));
}



