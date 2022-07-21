

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

