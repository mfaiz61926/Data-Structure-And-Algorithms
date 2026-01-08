#include <bits/stdc++.h>
using namespace std;

// compute length of the longest subarray with sum 0
int maxLen(int A[], int n) {
  // map prefix sum -> first index seen
  unordered_map<int, int> mpp;
  // best length so far
  int maxi = 0;
  // running prefix sum
  int sum = 0;

  // iterate over the array
  for (int i = 0; i < n; i++) {
    // update running sum
    sum += A[i];

    // if sum is zero, subarray [0..i] has zero sum
    if (sum == 0) {
      // update best length
      maxi = i + 1;
    }
    // otherwise check if this sum was seen before
    else {
      // when seen, zero-sum segment between previous index + 1 and i
      if (mpp.find(sum) != mpp.end()) {
        // maximize length
        maxi = max(maxi, i - mpp[sum]);
      }
      // first time seeing this sum
      else {
        // record index
        mpp[sum] = i;
      }
    }
  }

  // return best length
  return maxi;
}

// program entry
int main() {
  // sample input
  int A[] = {9, -3, 3, -1, 6, -5};
  // compute size
  int n = sizeof(A) / sizeof(A[0]);
  // print result
  cout << maxLen(A, n) << endl;
  // exit
  return 0;
}
