class Solution {
public:
    int rectangularArea(vector<int> &v){
        int n = v.size();

        vector<int> ls(n , -1);
        stack<int> s1;

        for(int i = 0 ; i < v.size() ; ++i){
            while(s1.size() > 0 && v[s1.top()] >= v[i]){
                s1.pop();
            }

            if(s1.size() > 0){
                ls[i] = s1.top();
            }

            s1.push(i);
        }

        vector<int> rs(n , n);
        stack<int> s2;

        for(int i = n-1 ; i >= 0 ; --i){
            while(s2.size() > 0 && v[s2.top()] >= v[i]){
                s2.pop();
            }

            if(s2.size() > 0){
                rs[i] = s2.top();
            }

            s2.push(i);
        }

        int area = 0;
        for(int i = 0 ; i < n ; ++i){
            area = max(area , (rs[i]-ls[i]-1)*v[i]);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m , 0);
        int area = 0;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }

            area = max(area , rectangularArea(heights));
        }

        return area;
    }
};