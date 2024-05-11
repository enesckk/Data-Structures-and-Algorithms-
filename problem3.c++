    #include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Structure to represent a job
struct Job {
   int id;
   int deadline;
   int profit;
};
 
// Comparator function to sort jobs based on profits in descending order
bool compareJobs(const Job& a, const Job& b) {
   return a.profit > b.profit;
}
 
int JobScheduling(int N, vector<Job>& Jobs) {
   // Sort jobs based on profits in descending order
   sort(Jobs.begin(), Jobs.end(), compareJobs);
 
   // Initialize a boolean array to mark whether a slot is occupied or not
   vector<bool> slots(N, false);
 
   // Initialize variables to store count of jobs done and maximum profit
   int count_jobs = 0;
   int max_profit = 0;
 
   // Iterate through each job
   for (auto& job : Jobs) {
       // Find the latest possible slot for the job
       for (int i = min(N, job.deadline) - 1; i >= 0; i--) {
           if (!slots[i]) {
               // Assign job to this slot
               slots[i] = true;
               count_jobs++;
               max_profit += job.profit;
               break;
           }
       }
   }
 
   return max_profit;
}
 
int main() {
   int N1 = 4;
   vector<Job> Jobs1 = { {1,4,20},{2,1,10},{3,1,40},{4,1,30} };
   cout << JobScheduling(N1, Jobs1) << endl;  // Output: 60
 
   int N2 = 5;
   vector<Job> Jobs2 = { {1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,1,15} };
   cout << JobScheduling(N2, Jobs2) << endl;  // Output: 127
 
   return 0;
}