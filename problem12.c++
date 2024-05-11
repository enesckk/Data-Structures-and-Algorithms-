#include <iostream>
#include <vector>
 
using namespace std;
 
int numberSequence(int m, int n) {
   // Initialize dp array
   vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
 
   // Initialize base cases
   for (int i = 1; i <= m; ++i) {
       dp[i][1] = 1;
   }
 
   // Fill dp array
   for (int j = 2; j <= n; ++j) {
       for (int i = 1; i <= m; ++i) {
           for (int k = i / 2; k >= 1; --k) {
               dp[i][j] += dp[k][j - 1];
           }
       }
   }
 
   // Calculate total number of special sequences
   int total = 0;
   for (int i = 1; i <= m; ++i) {
       total += dp[i][n];
   }
 
   return total;
}
 
int main() {
   int m1 = 10, n1 = 4;
   cout << numberSequence(m1, n1) << endl; // Output: 4
 
   int m2 = 5, n2 = 2;
   cout << numberSequence(m2, n2) << endl; // Output: 6
 
   return 0;
}