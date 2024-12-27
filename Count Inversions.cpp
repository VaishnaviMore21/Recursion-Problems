//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int mergesort(vector<int>&arr,int st,int end)
  {
      if(st<end)
      {
          int mid=st+(end-st)/2;
          int leftInvCount=mergesort(arr,st,mid);
          
          int rightInvCount=mergesort(arr,mid+1,end);
          
          int invcount=merge(arr,st,mid,end);
          return leftInvCount+rightInvCount+invcount;
          
      }
      return 0;
  }
  int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}
  
  
  
  
  
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        // Your Code Here
        return mergesort(arr, 0, n - 1);
    }
};
