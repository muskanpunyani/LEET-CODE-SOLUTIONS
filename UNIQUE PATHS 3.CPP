On a 2-dimensional grid, there are 4 types of squares:

    1 represents the starting square.  There is exactly one starting square.
    2 represents the ending square.  There is exactly one ending square.
    0 represents empty squares we can walk over.
    -1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

 

Note:

    1 <= grid.length * grid[0].length <= 20
**************************************************************************************************************************88


class Solution {
public:
    void finduniquepath(vector<vector<int>>& grid,int& total_zero,int zero_covered,int x,int y,int row,int col,int& path)
    {
        if(x>=row || x<0 || y>=col || y<0)
        {
            return;
        }
        if(grid[x][y]==-1)  // case for -1
        {
            return;
        }
        if(grid[x][y]==2)  // case for 2
        {
            if(total_zero==zero_covered)  // if total zeros are coveredx path will be incremented
            {
                path++;
            }
            return;
        }
        // now only 0s are left
        int temp=grid[x][y];
        grid[x][y]=-1; // make it -1 at start
        // now recurse in all four directions
              finduniquepath(grid,total_zero,zero_covered+1,x+1,y,row,col,path); // row+1
             finduniquepath(grid,total_zero,zero_covered+1,x-1,y,row,col,path); // row-1
             finduniquepath(grid,total_zero,zero_covered+1,x,y+1,row,col,path); // col+1
             finduniquepath(grid,total_zero,zero_covered+1,x,y-1,row,col,path); // col-1
        grid[x][y]=temp;  // make it back to normal
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row=grid.size(); 
        int col=grid[0].size();
        int total_zero=0;
        int x,y;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0)
                {
                    total_zero++;   // finding total no of zero
                }
                if(grid[i][j]==1)
                {
                    x=i;     // finding the start point
                    y=j;
                }
            }
        }
        int zero_covered=-1;  // we are passing his as -1 because the first one will be the entry of value 1 and we dont want that to be counted
        int path=0;
        finduniquepath(grid,total_zero,zero_covered,x,y,row,col,path);
        return path;
        
    }
};
