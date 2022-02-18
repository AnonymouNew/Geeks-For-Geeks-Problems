#User function Template for python3

class Solution:
    def closestToZero (self,arr, n):
        # your code here
        arr.sort()
        ans = arr[0]+arr[1]
        start, end = 0, n-1
        while(start < end):
            val = arr[start] + arr[end]
            if abs(val) < abs(ans):
                ans = val
            if abs(val) == abs(ans):
                ans = max(ans, val)
            if abs(arr[start+1]+arr[end]) < abs(arr[start] + arr[end-1]):
                start += 1
            else: end -= 1
            
        return ans

#{ 
#  Driver Code Starts
#Initial Template for Python 3

t = int (input ())
for tc in range(t):
    n = int (input ())
    arr = list(map(int, input().split()))
    ob = Solution()
    print (ob.closestToZero (arr, n))
# } Driver Code Ends