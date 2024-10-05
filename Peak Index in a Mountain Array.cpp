Peak Index in a Mountain Array
class Solution {
    public int peakIndexInMountainArray(int[] arr) {
           int left=0; int right=arr.length-1; int mid=0;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid-1]< arr[mid] && arr[mid+1]<arr[mid]){
                return mid;
            }
            if(arr[mid+1]>arr[mid]){
                left=mid+1;

            }
           else{
                right=mid;
            }
           
        }
        return mid;
    }
}
