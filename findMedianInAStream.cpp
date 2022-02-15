// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int, vector<int>, greater<int>> pqmin;
    priority_queue<int, vector<int>> pqmax;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(pqmin.size() == pqmax.size()) {
            if(pqmax.size() == 0) {
                pqmax.push(x);
                return;
            } 
            
            if(x < pqmax.top()) {
                pqmax.push(x);
            }
            else {
                pqmin.push(x);
            }
        } else {
            if(pqmax.size() > pqmin.size()) {
                if(x >= pqmax.top()) {
                    pqmin.push(x);
                } else {
                    int temp = pqmax.top();
                    pqmax.pop();
                    pqmin.push(temp);
                    pqmax.push(x);
                }
            } else {
                if(x <= pqmin.top()) {
                    pqmax.push(x);
                } else {
                    int temp = pqmin.top();
                    pqmin.pop();
                    pqmax.push(temp);
                    pqmin.push(x);
                }
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        return;        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(pqmax.size() == pqmin.size()) {
            return (pqmin.top() + pqmax.top())/2.0;;
        } else if (pqmin.size() > pqmax.size()) {
            return pqmin.top();
        } else {
            return pqmax.top();
        }
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends