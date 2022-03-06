// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        string temp;
        int ans=-1;
        temp.push_back(str[0]);
        bool flag=0;
        if(temp.compare("-")==0) flag=1;
        if(!flag){
            if(!(temp.compare("9")<=0 && temp.compare("9")>=-9)) return -1;
        }

        for(int i=1; i<str.length(); ++i) {
            temp = "";
            temp.push_back(str[i]);
            if(!(temp.compare("9")<=0 && temp.compare("9")>=-9)) return -1;
        }
        if(flag) str = str.substr(1,str.length());
        stringstream ss(str);
        ss >> ans;
        if(flag) ans*=-1;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends