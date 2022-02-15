// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string>& solve(string s, int l, int r, vector<string> &ans) {
	        if (l==r) {
	            ans.push_back(s);
	            return ans;
	        }
	        for(int i = l; i<=r; ++i) {
	            swap(s[i], s[l]);
	            solve(s, l+1, r, ans);
	            swap(s[i], s[l]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> final_ans;
		    solve(S, 0, S.size()-1, final_ans);
		    sort(final_ans.begin(), final_ans.end());
		    return final_ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends