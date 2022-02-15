class Solution
{
    public:
    void swap(int arr[], int val1, int val2) {
        int t = arr[val1];
        arr[val1] = arr[val2];
        arr[val2] = t;
    }
    
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>=high) return;
        int val = partition(arr, low, high);
        quickSort(arr, low, val-1);
        quickSort(arr, val+1, high);        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot = arr[high];
       int i = low-1;
       for(int j=low; j<high; ++j) {
           if(arr[j]<pivot){
               i++;
               swap(arr,i,j);
           }
       }
       swap(arr,i+1,high);
       return i+1;
    }
};