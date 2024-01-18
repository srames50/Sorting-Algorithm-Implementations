#ifndef SORT_H_
#define SORT_H_
#include <vector>
#include <iostream>
using namespace std;

void Merge(vector<int>& vec, int first, int mid, int last){
    int size = last - first + 1;
    int* tmp_arr;
    tmp_arr = new int[size];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;
    
    while((first1 <= last1) && (first2 <= last2)){
        if(vec[first1] < vec[first2]){
            tmp_arr[index] = vec[first1];
            first1++;

        }else{
            tmp_arr[index] = vec[first2];
            first2++;
        }
        index++;
    }
    while(first1 <= last1){
        tmp_arr[index] = vec[first1];
        first1++;
        index++;
    }
    while(first2 <= last2){
        tmp_arr[index] = vec[first2];
        first2++;
        index++;
    }
    for(index = 0; index < size; index++){
        vec[first] = tmp_arr[index];
        first ++;
    }
    delete[] tmp_arr;
}

void MergeSort(vector<int>& vec, int first, int last){
    // uses merge as helper, breaks down till pieces of 1
    if(first < last){
        int mid = (first + last) / 2;
        MergeSort(vec, first, mid);
        MergeSort(vec, mid + 1, last);
        Merge(vec, first, mid, last);
    }
    
}

void merge(vector<int>& arr, vector<int>& temp, int first, int mid, int last){
    // helper for iterative merge sort, uses pass by reference for copy array
    int i = first;
    int j = mid + 1;
    int k = 0;
    // initial sorting of halves
    while(i <= mid && j <= last){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i]; // Fix: Copy from arr[i]
            k++;
            i++;
        }else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    // if leftover elements in first half
    while(i <= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    // if leftover elements in second half
    while(j <= last){
        temp[k] = arr[j];
        k++;
        j++;
    }

    // copy elements back over to arr
    for (int i = 0; i < k; i++) {
        arr[first + i] = temp[i];
    }
}

void IterativeMergeSort(vector<int>& arr, int first, int last){
    int n = last - first + 1; // calculate size based on the range
    vector<int> temp(n);

    for(int i = 1; i < n; i *= 2){
        for(int j = 0; j < n - 1; j += i * 2){
            int mid = min(j + i - 1, n - 1);
            int end = min(j + 2 * i - 1, n - 1);
            merge(arr, temp, j, mid, end);
        }
    }
}


void BubbleSort(vector<int> &arr, int first, int last) {
    for (int i = first; i < last; i++) {
        for (int j = first; j < last - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void InsertionSort(vector<int> &arr, int first, int last){
    for(int i = first + 1; i < last; i++){
        int key = arr[i];
        int j = i - 1;

        while(i >= first && arr[j] > key){
            arr[j + 1] = j;
            j--;
        }
        arr[j + 1] = key;
    }
}

void QuickSort(vector<int>& vec, int first, int last){
    if(last - first < 5){
        InsertionSort(vec, first, last);
        return;
    }
    int mid = (first + last)/ 2;

    if(vec[first] > vec[last]){
        swap(vec[first], vec[last]);
    }
    if(vec[mid] > vec[last]){
        swap(vec[mid], vec[last]);
    }
    if(vec[first] > vec[mid]){
        swap(vec[first], vec[mid]);
    }

    int pivot = vec[mid];
    swap(vec[mid], vec[last - 1]);
    int left = first + 1;
    int right = last - 2;
    bool done = false;
    while(!done){
        while(vec[left] < pivot){
            left++;
        }
        while(vec[right] > pivot){
            right--;
        }
        if(right > left){
            swap(vec[left], vec[right]);
            left++;
            right--;
        }else{
            done = true;
        }
    }
    
    swap(vec[last - 1], vec[left]);
    QuickSort(vec, first, left  - 1);
    QuickSort(vec, left + 1, last);

}

void ShellSort(vector<int> &arr, int first, int last) {
    int size = last - first + 1;

    for(int gap = size / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2)){
        for(int i = first + gap; i <= last; i++){
            int tmp = arr[i];
            int j = i;
            for (; (j >= gap) && (tmp < arr[j - gap]); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = tmp;
        }
    }
}



#endif