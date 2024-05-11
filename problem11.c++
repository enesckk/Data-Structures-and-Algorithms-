#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool isPossible(vector<int>& A, int N, int M, int maxPages) {
   int students = 1;
   int pages = 0;
   for (int i = 0; i < N; ++i) {
       if (A[i] > maxPages) {
           return false;
       }
       if (pages + A[i] > maxPages) {
           students++;
           pages = A[i];
           if (students > M) {
               return false;
           }
       }
       else {
           pages += A[i];
       }
   }
   return true;
}
 
int findPages(int N, int M, vector<int>& A) {
   if (N < M) {
       return -1; // Invalid input
   }
 
   int low = *max_element(A.begin(), A.end()); // Minimum possible maximum pages
   int high = 0;
   for (int pages : A) {
       high += pages; // Sum of all pages
   }
 
   int result = -1;
   while (low <= high) {
       int mid = low + (high - low) / 2;
       if (isPossible(A, N, M, mid)) {
           result = mid;
           high = mid - 1; // Look for smaller values
       }
       else {
           low = mid + 1; // Look for larger values
       }
   }
   return result;
}
 
int main() {
   vector<int> A1 = { 12, 34, 67, 90 };
   int N1 = 4, M1 = 2;
   cout << findPages(N1, M1, A1) << endl; // Output: 113
 
   vector<int> A2 = { 15, 17, 20 };
   int N2 = 3, M2 = 2;
   cout << findPages(N2, M2, A2) << endl; // Output: 32
 
   return 0;
}