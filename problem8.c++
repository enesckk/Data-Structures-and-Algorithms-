#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
bool isValidPart(string s) {
   // Check if the part is a valid number between 0 and 255
   if (s.empty() || (s.size() > 1 && s[0] == '0')) {
       return false; // Leading zeros are not allowed
   }
   int num = stoi(s);
   return num >= 0 && num <= 255;
}
 
void generateIP(string s, int pos, int parts, string current, vector<string>& result) {
   // Base case: If we have used all four parts and reached the end of the string
   if (parts == 4 && pos == s.size()) {
       result.push_back(current);
       return;
   }
   // If we have used all four parts but haven't reached the end of the string, return
   if (parts == 4 || pos == s.size()) {
       return;
   }
 
   // Try different combinations of substrings for the current part of the IP address
   for (int len = 1; len <= 3 && pos + len <= s.size(); ++len) {
       string part = s.substr(pos, len);
       if (isValidPart(part)) {
           string newCurrent = current.empty() ? part : current + "." + part;
           generateIP(s, pos + len, parts + 1, newCurrent, result);
       }
   }
}
 
vector<string> genIp(string S) {
   vector<string> result;
   if (S.size() < 4 || S.size() > 12) {
       return { "-1" };
   }
   generateIP(S, 0, 0, "", result);
   return result;
}
 
int main() {
   string S1 = "1111";
   vector<string> result1 = genIp(S1);
   for (const string& ip : result1) {
       cout << ip << " ";
   }
   cout << endl;  // Output: 1.1.1.1
 
   string S2 = "55";
   vector<string> result2 = genIp(S2);
   for (const string& ip : result2) {
       cout << ip << " ";
   }
   cout << endl;  // Output: -1
 
   return 0;
}