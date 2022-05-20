
// questions:
// 63. Unique Paths II
// Medium

// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Example 2:

// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1

 

// Constraints:

//     m == obstacleGrid.length
//     n == obstacleGrid[i].length
//     1 <= m, n <= 100
//     obstacleGrid[i][j] is 0 or 1.


// using recursion with memoization 

// creating class with solution :

// #include<bits/stdc++.h>
// include header bits
#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         if(obstacleGrid[0][0]) return 0;
        int n = obstacleGrid.size(), m=obstacleGrid[0].size();
        for(int i=0; i < n; i++){
            dp.push_back(vector<int>(m, -1));
        }
        return solve(obstacleGrid, n, m, 0, 0);
    }
    private:
    int solve(vector<vector<int>>& grid, int n, int m, int x, int y){
        if(x == n-1 && y == m-1)
            return (grid[x][y] != 1) ? 1 : 0;
        if(dp[x][y]>=0) return dp[x][y];
        int temp=0;
        if(x+1 < n && !grid[x+1][y])
            temp+= solve(grid, n, m, x+1, y);
        if(y+1 < m && !grid[x][y+1])
            temp+= solve(grid, n, m, x, y+1);
        return dp[x][y] = temp;
            }
};

// create main function to test the above class
int main() {
    // create an object of the class
    Solution s;
    // create an array of strings
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    // print the longest common prefix
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    // return 0
    return 0;
}