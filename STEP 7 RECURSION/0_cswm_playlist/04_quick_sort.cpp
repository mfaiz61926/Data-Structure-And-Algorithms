#include <bits/stdc++.h>
using namespace std;
//gfg
class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low >= high) return;
        
        int pivot = partition(arr,low,high);
        
        quickSort(arr,low, pivot - 1);
        quickSort(arr,pivot + 1, high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int pivot = arr[high];
        int pi = low;
        
        for(int i = low; i < high; i++){
            if(arr[i] < pivot){
                swap(arr[i], arr[pi++]);
            }
        }
        swap(arr[high], arr[pi]);
        return pi;
    }
};