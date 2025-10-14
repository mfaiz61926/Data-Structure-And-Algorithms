#include <bits/stdc++.h>

using namespace std;

//gfg merge sort
class Solution {
  public:
    void merge(vector<int>&arr, int l, int mid, int r){
        int n1 = mid - l + 1;
        int n2 = r - mid;
        
        vector<int>a(n1);
        vector<int>b(n2);
        
        int k = l;
        for(int i = 0; i < n1; i++) a[i] = arr[k++];
        for(int i = 0; i < n2; i++) b[i] = arr[k++];
        
        int i = 0, j = 0;
        k = l;
        
        while(i <n1 && j < n2){
            if(a[i] <= b[j]){
                arr[k++] = a[i++];
            }
            else arr[k++] = b[j++];
        }
        
        while(i < n1){
            arr[k++] = a[i++];
        }
        
        while(j < n2){
            arr[k++] = b[j++];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l == r) return;
        int mid = (l+r) / 2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    }
};