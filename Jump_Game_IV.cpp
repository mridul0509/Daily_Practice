#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int> > m;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
        set<int> visited;
        visited.insert(0);
        queue<int> q;
        q.push(0);
        for (int lvl = 0; !q.empty(); lvl++) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1)
                    return lvl;
                int i = curr;
                if (i - 1 >= 0 && !visited.count(i - 1)) {
                    q.push(i - 1);
                    visited.insert(i - 1);
                }
                if (i + 1 < n && !visited.count(i + 1)) {
                    q.push(i + 1);
                    visited.insert(i + 1);
                }
                for (int j = 0; j < m[arr[curr]].size(); j++) {
                    if (!visited.count(m[arr[curr]][j])) {
                        q.push(m[arr[curr]][j]);
                        visited.insert(m[arr[curr]][j]);
                    }
                }
                if (m.count(arr[curr])) {
                    m.erase(arr[curr]);
                }
            }
        }
        return -1;
    }
};

int main() {
	vector<int> v{ 100,-23,-23,404,100,23,23,23,3,404 };
	Solution obj;
	cout<<obj.minJumps(v)<<endl;
	return 0;
}