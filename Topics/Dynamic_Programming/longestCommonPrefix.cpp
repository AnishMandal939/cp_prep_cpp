Question
// Given multiple strings, find the longest common prefix among all the strings. Each string is made up of lowercase latin letters.
 
// Input: First line of input contains number of testcases T. For each testcase, first line contains an input N, which will represent the number of strings. The next line will have N space separated strings.
 
// Output: Print the longest common prefix each in new line. If no common prefix exists just print blank and new line.
 
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 10000
// 1 <= Length of String <= 30
 
// Example:
// Input:
// 1
// 4
// geeksforgeeks geeks geeky geezer
// Output:
// gee
 
// analyse problem
// 1. find the longest common prefix
// 2. if no common prefix exists, print blank and new line
   
 
// which algorithm to use? brute force or prefix sum or kmp or boyer-moore or rabin-karp or horspool or aho-corasick or trie
// brute force is O(n^2) time complexity and O(1) space complexity
// prefix sum is O(n) time complexity and O(n) space complexity
// kmp is O(n) time complexity and O(n) space complexity
// boyer-moore is O(n) time complexity and O(1) space complexity
// rabin-karp is O(n) time complexity and O(1) space complexity
// horspool is O(n) time complexity and O(1) space complexity
// aho-corasick is O(n) time complexity and O(n) space complexity
// trie is O(n) time complexity and O(n) space complexity
 
 
// brute force
// time complexity: O(n^2)
// space complexity: O(1)
// function: longestCommonPrefix
// input: string array
// output: longest common prefix
// algorithm:
 
 
// apply algorithm
 
// code starts here 
 
// include headers 
#include <bits/stdc++.h>
using namespace std;
 
//  create class 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // if the array is empty, return empty string
        if(strs.size() == 0) return "";
        // if the array has only one element, return that element
        if(strs.size() == 1) return strs[0];
        // sort the array
        sort(strs.begin(), strs.end());
        // get the first element of the array
        string first = strs[0];
        // get the last element of the array
        string last = strs[strs.size() - 1];
        // get the length of the first element
        int first_len = first.length();
        // get the length of the last element
        int last_len = last.length();
        // get the length of the longest common prefix
        int len = 0;
        // loop through the first element
        for(int i = 0; i < first_len; i++) {
            // if the first element and the last element have the same character at the same index, increment the length of the longest common prefix
            if(first[i] == last[i]) len++;
            // else break the loop
            else break;
        }
        // return the longest common prefix
        return first.substr(0, len);
    }
};
 
// main program to print output
int main() {
    // create an object of the class
    Solution s;
    // create an array of strings
    vector<string> strs = {"geeksforgeeks", "geeks", "geeky", "geezer"};
    // print the longest common prefix
    cout << s.longestCommonPrefix(strs) << endl;
    // return 0
    return 0;
}
 
 
 
 

