#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Structure to represent a pair
struct Pair {
   int first;
   int second;
};
 
// Comparator function to sort pairs based on the second number in ascending order
bool comparePairs(const Pair& a, const Pair& b) {
   return a.second < b.second;
}
 
int maxChainLen(vector<Pair>& pairs) {
   // Sort pairs based on the second number in ascending order
   sort(pairs.begin(), pairs.end(), comparePairs);
 
   // Initialize a dp array to store the length of the longest chain ending at each pair
   vector<int> dp(pairs.size(), 1);
 
   // Iterate through each pair
   for (int i = 1; i < pairs.size(); ++i) {
       // Consider all pairs before the current pair
       for (int j = 0; j < i; ++j) {
           // If the current pair can be added to the chain ending at pairs[j]
           if (pairs[i].first > pairs[j].second && dp[i] < dp[j] + 1) {
               dp[i] = dp[j] + 1;
           }
       }
   }
 
   // Return the maximum length of the longest chain
   return *max_element(dp.begin(), dp.end());
}
 
int main() {
   vector<Pair> pairs1 = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
   cout << maxChainLen(pairs1) << endl;  // Output: 3
 
   vector<Pair> pairs2 = { {5, 10}, {1, 11} };
   cout << maxChainLen(pairs2) << endl;  // Output: 1
 
   return 0;
}