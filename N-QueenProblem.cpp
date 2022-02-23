// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> ans;
    vector<int> v;
    bool solve(vector<vector<int>>& board, int col, int n, int row) {
        int i = row, j = col;
        while(i>=0 && j>=0) {
            if(board[i][j]==1) return false;
            i--; j--;
        }
        
        j=col;
        while(j>=0){
            if(board[row][j]==1) return false;
            j--;
        }
        i = row, j = col;
        while(i<n && j>=0) {
            if(board[i][j]==1) return false;
            i++; j--;
        }
        return true;
    }
    
    void helper(vector<vector<int>>&board, int n, int col) {
        if(col==n){
            ans.push_back(v);
            return;
        }
        for(int row=0; row<n; ++row){
            if(solve(board, col, n, row)){
                v.push_back(row+1);
                board[row][col] = 1;
                helper(board, n, col+1);
                board[row][col] = 0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n,0));
        helper(board, n, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends