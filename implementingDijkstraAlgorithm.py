import collections
class Solution:

    #Function to find the shortest distance of all the vertices
    #from the source vertex S.
    def dijkstra(self, V, adj, S):
        #code here
        dist = [float("inf")]*V
        dist[S] = 0
        
        q = collections.deque()
        q.append(S)
        while q:
            node = q.pop()
            for ni, ni_dist in adj[node]:
                if dist[node] + ni_dist < dist[ni]:
                    dist[ni] = dist[node] + ni_dist
                    q.append(ni)
        return dist

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        V,E = map(int,input().strip().split())
        adj = [[] for i in range(V)]
        for i in range(E):
            u,v,w = map(int,input().strip().split())
            adj[u].append([v,w])
            adj[v].append([u,w])
        S=int(input())
        ob = Solution()
        
        res = ob.dijkstra(V,adj,S)
        for i in res:
            print(i,end=" ")
        print()
# } Driver Code Ends