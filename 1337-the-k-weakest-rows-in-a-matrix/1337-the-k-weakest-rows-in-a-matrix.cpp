class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<pair<int , int>> p;

        for(int i = 0 ; i < n ; ++i){
            int s = 0;
            for(int j = 0 ; j < m ; ++j){
                s += mat[i][j];
            }

            p.push_back({s , i});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int , int>>> pq(p.begin() , p.end());

        vector<int> v;

        while(k--){
            v.push_back(pq.top().second);
            pq.pop();
        }

        return v;
    }
};