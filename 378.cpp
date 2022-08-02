class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // priority_queue<int> q;
        //int n= matrix.size();
        // int flag =0;
        // for(int i=0;i<n;i++){
        //     for(int j =0;j<n;j++){
        //         q.push(matrix[i][j]);
        //         if(q.size() >k){
        //             q.pop();
        //         }
        //     }
        //     if(flag == 1)
        //             break;
        // }
        // return q.top();
      
        int n= matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low < high){
            int count =0;
            int mid = low + (high-low)/2;
            for(int i=0;i<n;i++){
                count += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            }
            if(count < k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};
