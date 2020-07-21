/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/


class Solution {
public:
  bool findwhole(int row,int col,vector<vector<char>>& board,string word,int n,int m,int level)
    {
      int l=word.length();
      if(level==l)   //means whole string is covered
      {
          return true;
      }
      if(row<0 || col <0 || row>=n || col>=m)
      {
          return false;
      }
      if(board[row][col]==word[level])
      {
          char temp=board[row][col];
          board[row][col]='#'; //mark it as visited
              //bitwise or (any dirn to be true)
          bool ans=false;
          // dont use (|) single or as this will lead to TLE
     ans= findwhole(row-1,col,board,word,n,m,level+1) || findwhole(row+1,col,board,word,n,m,level+1) || findwhole(row,col-1,board,word,n,m,level+1) || findwhole(row,col+1,board,word,n,m,level+1);
          
          board[row][col]=temp;     //mark that as unvisited again
          return ans;
      }
      else{
      return false;
      }
      
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();  //row
        int m=board[0].size();  //col
        int l=word.length();
        if(l > (n*m))
        {
            return false;
        }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(word[0]==board[i][j])
               {
                  if( findwhole(i,j,board,word,n,m,0))
                  {
                      return true;
                      break;
                      
                  }
               }
           }
       }
        return false;
        
    }
};
