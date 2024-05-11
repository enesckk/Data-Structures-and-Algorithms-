#include <iostream>
#include <vector>
 
using namespace std;
 
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
   // Check if any adjacent vertex has the same color
   for (int i = 0; i < graph.size(); ++i) {
       if (graph[v][i] && color[i] == c) {
           return false;
       }
   }
   return true;
}
 
bool graphColoringUtil(int v, int M, vector<vector<int>>& graph, vector<int>& color) {
   // Base case: If all vertices are assigned a color
   if (v == graph.size()) {
       return true;
   }
 
   // Try assigning colors to current vertex v
   for (int c = 1; c <= M; ++c) {
       // Check if color c can be assigned to vertex v
       if (isSafe(v, graph, color, c)) {
           color[v] = c;
 
           // Recur for next vertex
           if (graphColoringUtil(v + 1, M, graph, color)) {
               return true;
           }
 
           // If assigning color c doesn't lead to a solution, backtrack
           color[v] = 0;
       }
   }
 
   // If no color can be assigned to vertex v, return false
   return false;
}
 
bool graphColoring(int N, int M, vector<vector<int>>& graph) {
   vector<int> color(N, 0); // Initialize color array to store colors assigned to vertices
 
   // Call the recursive utility function to color the graph
   if (graphColoringUtil(0, M, graph, color)) {
       return true;
   }
 
   return false;
}
 
int main() {
   int N1 = 4, M1 = 3;
   vector<vector<int>> graph1 = { {0, 1, 0, 1},
                                  {1, 0, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0} };
   cout << graphColoring(N1, M1, graph1) << endl;  // Output: 1
 
   int N2 = 3, M2 = 2;
   vector<vector<int>> graph2 = { {0, 1, 1},
                                  {1, 0, 1},
                                  {1, 1, 0} };
   cout << graphColoring(N2, M2, graph2) << endl;  // Output: 0
 
   return 0;
}