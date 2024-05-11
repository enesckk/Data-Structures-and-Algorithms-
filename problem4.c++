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
 
   // Initialize variables to store count of pairs and the last selected pair's second number
   int countPairs = 0;
   int lastSecond = INT_MIN;
 
   // Iterate through each pair
   for (const auto& pair : pairs) {
       // If the first number of the current pair is greater than the second number of the last selected pair
       if (pair.first > lastSecond) {
           // Update the last selected pair's second number
           lastSecond = pair.second;
           // Increment the count of pairs in the chain
           countPairs++;
       }
   }
 
   // Return the count of pairs in the longest chain
   return countPairs;
}
 
int main() {
   vector<Pair> pairs1 = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
   cout << maxChainLen(pairs1) << endl;  // Output: 3
 
   vector<Pair> pairs2 = { {5, 10}, {1, 11} };
   cout << maxChainLen(pairs2) << endl;  // Output: 1
 
   return 0;
}