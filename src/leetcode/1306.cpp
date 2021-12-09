#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int temp, sz = arr.size();
        vector<int> visited(sz, 0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            start = q.front();
            visited[start] = 1;
            q.pop();
            if(arr[start] == 0)
                return true;
            temp = start - arr[start];
            if(temp >= 0 && !visited[temp])
                q.push(temp);
            temp = start + arr[start];
            if(temp < sz && !visited[temp])
                q.push(temp);
        }
        return false;
    }
};

class SolutionDFS{
    bool dfs(vector<int>& arr, int start, vector<int>& visited){
        if(start < 0 || start >= arr.size() || visited[start]) return false;
        if(arr[start] == 0) return true;
        visited[start] = 1;
        return dfs(arr, start + arr[start], visited)
               || dfs(arr, start - arr[start], visited);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        return dfs(arr, start, visited);
    }
};