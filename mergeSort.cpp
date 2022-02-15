// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         auto const len1 = m-l+1;
         auto const len2 = r-m;
         
         auto *leftArray = new int[len1], *rightArray = new int[len2];
         
         for(auto i=0; i<len1; ++i) 
            leftArray[i] = arr[l+i];
        for(auto j=0; j<len2; ++j)
            rightArray[j] = arr[m+1+j];
            
        auto idx1 = 0, idx2 = 0;
        int idx3 = l;
        
        while(idx1 < len1 && idx2 < len2) {
            if(leftArray[idx1] <= rightArray[idx2]) {
                arr[idx3] = leftArray[idx1];
                idx1++;
            }
            else {
                arr[idx3] = rightArray[idx2];
                idx2++;
            }
            idx3++;
        }
        
        while(idx1 < len1) {
            arr[idx3] = leftArray[idx1];
            idx1++; idx3++;
        }
        
        while(idx2 < len2) {
            arr[idx3] = rightArray[idx2];
            idx2++; idx3++;
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code  here
        if(l>=r) return;
        auto m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends