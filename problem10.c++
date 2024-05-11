#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
   int n = arr1.size();
   int m = arr2.size();
 
   // Ensure arr1 is the smaller array
   if (n > m) {
       return kthElement(arr2, arr1, k);
   }
 
   int low = max(0, k - m); // Minimum number of elements to pick from arr1
   int high = min(k, n); // Maximum number of elements to pick from arr1
 
   while (low <= high) {
       int cut1 = low + (high - low) / 2; // Partition in arr1
       int cut2 = k - cut1; // Corresponding partition in arr2
 
       int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
       int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
       int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
       int right2 = (cut2 == m) ? INT_MAX : arr2[cut2];
 
       // If the partition is correct, return the kth element
       if (left1 <= right2 && left2 <= right1) {
           return max(left1, left2);
       }
       // If the cut1 is too much to the right, move towards left
       else if (left1 > right2) {
           high = cut1 - 1;
       }
       // If the cut1 is too much to the left, move towards right
       else {
           low = cut1 + 1;
       }
   }
 
   // Should not reach here
   return -1;
}
 
int main() {
   vector<int> arr1 = { 2, 3, 6, 7, 9 };
   vector<int> arr2 = { 1, 4, 8, 10 };
   int k1 = 5;
   cout << kthElement(arr1, arr2, k1) << endl; // Output: 6
 
   vector<int> arr3 = { 100, 112, 256, 349, 770 };
   vector<int> arr4 = { 72, 86, 113, 119, 265, 445, 892 };
   int k2 = 7;
   cout << kthElement(arr3, arr4, k2) << endl; // Output: 256
 
   return 0;
}