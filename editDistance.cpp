// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        if(s==t) return 0;
        int s_len = s.length();
        int t_len = t.length();
        int** dp = new int*[s_len+1];
        for(int i=0; i<=s_len; ++i) dp[i] = new int[t_len+1];
        for(int i=s_len; i>=0; i--){
            dp[i][t_len] = s_len-i;
        }
        for(int j=t_len; j>=0; j--){
            dp[s_len][j] = t_len-j;
        }
        for(int i=s_len-1; i>=0; i--){
            for(int j=t_len-1; j>=0; j--){
                if(s[i]==t[j]) dp[i][j] = dp[i+1][j+1];
                else{
                    int val1 = dp[i+1][j];
                    int val2 = dp[i][j+1];
                    dp[i][j] = 1+ min(dp[i+1][j+1], min(val1, val2));
                }
            }
        }
        return dp[0][0];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends