#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
 
using namespace std;
 
bool compareJobs(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
   return get<2>(a) > get<2>(b);
}
 
vector<int> JobScheduling(int N, vector<tuple<int, int, int>>& Jobs) {
   // Sort jobs based on profit in descending order
   sort(Jobs.begin(), Jobs.end(), compareJobs);
 
   // Initialize an array to keep track of slot availability
   vector<bool> slots(N, false);
 
   // Initialize variables to store count of jobs done and maximum profit
   int count_jobs = 0;
   int max_profit = 0;
 
   // Iterate through each job
   for (auto& job : Jobs) {
       int deadline = get<1>(job);
       // Find the latest possible slot for the job
       for (int i = min(N, deadline) - 1; i >= 0; i--) {
           if (!slots[i]) {
               // Assign job to this slot
               slots[i] = true;
               count_jobs++;
               max_profit += get<2>(job);
               break;
           }
       }
   }
 
   return { count_jobs, max_profit };
}
 
int main() {
   int N1 = 4;
   vector<tuple<int, int, int>> Jobs1 = { {1,4,20},{2,1,10},{3,1,40},{4,1,30} };
   vector<int> result1 = JobScheduling(N1, Jobs1);
   cout << result1[0] << " " << result1[1] << endl;  // Output: 2 60
 
   int N2 = 5;
   vector<tuple<int, int, int>> Jobs2 = { {1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,1,15} };
   vector<int> result2 = JobScheduling(N2, Jobs2);
   cout << result2[0] << " " << result2[1] << endl;  // Output: 2 127
 
   return 0;
}