// *************************************** string version **********************************************

#include<bits/stdc++.h>
bool isSafe (int newx, int newy, vector <vector <bool >>&vis, vector < vector < int >> & arr, int n ){
    
    if ((newx >= 0 && newx < n ) && (newy >= 0 && newy < n) && vis[newx][newy] != 1  && arr[newx][newy] != 0)  {
        return true;
    }
    
    else return false;
}

void solve (int x, int y,vector < vector < int >> & arr, int n,  vector <string> &ans, vector <vector <bool >>&vis
                            , string path)
{
    //base case 
    if (x == n - 1 && y == n-1){
        ans.push_back(path);
        return;
    }
    
    //4Movement
    
    
    //Down 
    if(isSafe (x+1, y, vis, arr, n)){
        vis[x][y] = 1;
        solve (x+1,y,arr,n,ans, vis, path + 'D');
    }
    
    //left
    if(isSafe (x, y-1, vis, arr, n)){
        vis[x][y] = 1;
        solve (x,y-1,arr,n,ans, vis, path + 'L');
    }
    
    //right
    if(isSafe (x, y+1, vis, arr, n)){
        vis[x][y] = 1;
        solve (x,y+1,arr,n,ans, vis, path + 'R');
    }
    
    //Up
    if(isSafe (x-1, y, vis, arr, n)){
        vis[x][y] = 1;
        solve (x-1,y,arr,n,ans, vis, path + 'U');
    }
    
       vis[x][y] = 0;
}


vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector <string> ans;
    if (arr[0][0] == 0)
        return ans;
    
    vector <vector <bool >> visited (n, vector <bool> (n, 0));
    string path = "";
    solve (0,0,arr, n, ans, visited,path );
    return ans;
    
}

//Time Complexity - (4 ^ n^2)
// Space Complexity = O(N * M)



// ***************************************************** integer version ***********************************************



void putData (vector <vector <int>> &rat, vector <vector <int>> &ans)
{
    int n= rat.size();
    vector <int> temp;
    for (int i = 0; i  < n; i++){
        for (int j = 0; j < n; j++){
            temp.push_back(rat[i][j]);
        }
    }
    ans.push_back(temp);
}


void solve (int row, int col, vector<vector<int> > &maze, vector<vector<int> > &rat, vector<vector<int> > &ans, vector<vector<bool> > &visited, int n)
{
    if (row >= n or row <0 or col >= n or col < 0 or visited[row][col] or maze[row][col] == 0)
        return;
    
    if (row == n-1 and col == n-1){
        rat[row][col] = 1;
        putData(rat, ans);
        rat[row][col] = 0;
        return;
    }
    
    visited[row][col] = 1;
    rat[row][col] = 1;
    
    //DOWN
    solve (row+1, col, maze, rat, ans, visited, n);
    
    //RIGHT
    solve (row, col+1, maze, rat, ans, visited, n);
    
    //Up
    solve (row-1, col, maze, rat, ans, visited, n);
    
    
   //LEFT
    solve (row, col-1, maze, rat, ans, visited, n);
    
    visited[row][col] = false;
    rat[row][col] = 0;
       
}


vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  
    vector <vector <int >> rat (n,vector <int> (n, 0));
    vector <vector <int>> ans;
    vector <vector <bool> > visited (n, vector <bool>(n, false));
    solve (0, 0, maze, rat, ans, visited, n);
    return ans;
    
}
