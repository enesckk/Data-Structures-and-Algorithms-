#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
void backtrack(vector<vector<int>>& maze, int i, int j, int n, string path, vector<string>& paths) {
   // Base case: If the rat reaches the destination
   if (i == n - 1 && j == n - 1) {
       paths.push_back(path);
       return;
   }
 
   // Explore down
   if (i + 1 < n && maze[i + 1][j] == 1) {
       maze[i][j] = 0; // Mark current cell as visited
       backtrack(maze, i + 1, j, n, path + "D", paths);
       maze[i][j] = 1; // Backtrack
   }
   // Explore right
   if (j + 1 < n && maze[i][j + 1] == 1) {
       maze[i][j] = 0; // Mark current cell as visited
       backtrack(maze, i, j + 1, n, path + "R", paths);
       maze[i][j] = 1; // Backtrack
   }
   // Explore up
   if (i - 1 >= 0 && maze[i - 1][j] == 1) {
       maze[i][j] = 0; // Mark current cell as visited
       backtrack(maze, i - 1, j, n, path + "U", paths);
       maze[i][j] = 1; // Backtrack
   }
   // Explore left
   if (j - 1 >= 0 && maze[i][j - 1] == 1) {
       maze[i][j] = 0; // Mark current cell as visited
       backtrack(maze, i, j - 1, n, path + "L", paths);
       maze[i][j] = 1; // Backtrack
   }
}
 
vector<string> printPath(int n, vector<vector<int>>& m) {
   vector<string> paths;
   // Check if source or destination is blocked
   if (m[0][0] == 0 || m[n - 1][n - 1] == 0) {
       return paths;
   }
   backtrack(m, 0, 0, n, "", paths);
   // Sort the paths lexicographically
   sort(paths.begin(), paths.end());
   return paths;
}
 
int main() {
   vector<vector<int>> maze1 = { {1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1} };
   int n1 = 4;
   vector<string> paths1 = printPath(n1, maze1);
   for (const auto& path : paths1) {
       cout << path << " ";
   }
   cout << endl;  // Output: DDRDRR DRDDRR
 
   vector<vector<int>> maze2 = { {1, 0},
                                 {1, 0} };
   int n2 = 2;
   vector<string> paths2 = printPath(n2, maze2);
   if (paths2.empty()) {
       cout << -1 << endl;  // Output: -1
   }
 
   return 0;
}