#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Custom struct to store meeting details
struct Meeting {
   int start;
   int end;
   int index;
};
 
// Custom comparator function to sort meetings based on end times
bool compare(Meeting a, Meeting b) {
   return a.end < b.end;
}
 
int maxMeetings(int start[], int end[], int N) {
   // Create a vector of Meeting structs to store meeting details
   vector<Meeting> meetings;
   for (int i = 0; i < N; ++i) {
       meetings.push_back({ start[i], end[i], i });
   }
 
   // Sort meetings based on end times
   sort(meetings.begin(), meetings.end(), compare);
 
   // Initialize variables
   int count = 0;
   int prevEnd = 0;
 
   // Iterate through sorted meetings
   for (auto meeting : meetings) {
       // If the current meeting doesn't overlap with the previous one, select it
       if (meeting.start > prevEnd) {
           count++;
           prevEnd = meeting.end;
       }
   }
 
   return count;
}
 
int main() {
   int N = 6;
   int start[] = { 1, 3, 0, 5, 8, 5 };
   int end[] = { 2, 4, 6, 7, 9, 9 };
   cout << maxMeetings(start, end, N) << endl;  // Output: 4
 
   N = 3;
   int start2[] = { 10, 12, 20 };
   int end2[] = { 20, 25, 30 };
   cout << maxMeetings(start2, end2, N) << endl;  // Output: 1
 
   return 0;
}