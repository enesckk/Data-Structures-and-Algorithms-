#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
 
using namespace std;
 
// Trie Node
struct TrieNode {
   TrieNode* children[26];
   bool isEndOfWord;
 
   TrieNode() {
       for (int i = 0; i < 26; ++i) {
           children[i] = nullptr;
       }
       isEndOfWord = false;
   }
};
 
// Trie class
class Trie {
private:
   TrieNode* root;
 
public:
   Trie() {
       root = new TrieNode();
   }
 
   void insert(string word) {
       TrieNode* current = root;
       for (char c : word) {
           int index = c - 'A'; // Assuming uppercase letters only
           if (!current->children[index]) {
               current->children[index] = new TrieNode();
           }
           current = current->children[index];
       }
       current->isEndOfWord = true;
   }
 
   TrieNode* getRoot() {
       return root;
   }
};
 
void findWords(vector<vector<char>>& board, TrieNode* root, int i, int j, string& currentWord, unordered_set<string>& result, vector<vector<bool>>& visited) {
   // Base case: If we reached a cell that is out of bounds or already visited
   if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j]) {
       return;
   }
 
   // Get the index of the current character
   int index = board[i][j] - 'A'; // Assuming uppercase letters only
 
   // Check if there is a child node in the trie corresponding to the current character
   if (root->children[index]) {
       // Append the current character to the current word
       currentWord.push_back(board[i][j]);
 
       // Mark the current cell as visited
       visited[i][j] = true;
 
       // If the current word is in the dictionary, add it to the result set
       if (root->children[index]->isEndOfWord) {
           result.insert(currentWord);
       }
 
       // Recursively explore all adjacent cells
       for (int dx = -1; dx <= 1; ++dx) {
           for (int dy = -1; dy <= 1; ++dy) {
               if (dx != 0 || dy != 0) { // Exclude the current cell itself
                   findWords(board, root->children[index], i + dx, j + dy, currentWord, result, visited);
               }
           }
       }
 
       // Backtrack: Remove the last character from the current word and mark the cell as unvisited
       currentWord.pop_back();
       visited[i][j] = false;
   }
}
 
vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
   // Construct trie from dictionary words
   Trie trie;
   for (string word : dictionary) {
       trie.insert(word);
   }
 
   // Initialize variables
   unordered_set<string> result;
   vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
   string currentWord = "";
 
   // Traverse the board and find words
   for (int i = 0; i < board.size(); ++i) {
       for (int j = 0; j < board[0].size(); ++j) {
           findWords(board, trie.getRoot(), i, j, currentWord, result, visited);
       }
   }
 
   // Convert result set to vector and return
   vector<string> resultVector(result.begin(), result.end());
   return resultVector;
}
 
int main() {
   vector<vector<char>> board1 = { {'C', 'A', 'P'},
                                   {'A', 'N', 'D'},
                                   {'T', 'I', 'E'} };
   vector<string> dictionary1 = { "CAT" };
   vector<string> result1 = wordBoggle(board1, dictionary1);
   for (const string& word : result1) {
       cout << word << " ";
   }
   cout << endl;  // Output: CAT
 
   vector<vector<char>> board2 = { {'G', 'I', 'Z'},
                                   {'U', 'E', 'K'},
                                   {'Q', 'S', 'E'} };
   vector<string> dictionary2 = { "GEEKS", "FOR", "QUIZ", "GO" };
   vector<string> result2 = wordBoggle(board2, dictionary2);
   for (const string& word : result2) {
       cout << word << " ";
   }
   cout << endl;  // Output: GEEKS QUIZ
 
   return 0;
}