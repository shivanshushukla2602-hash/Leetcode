class Solution {
public:
    int squareArea(vector<int> v){
        int n = v.size();

        vector<int> ls(n , -1);
        stack<int> s1;

        for(int i = 0 ; i < n ; ++i){
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
        int d;
        for(int i = 0 ; i < n ; ++i){
            int width = rs[i]-ls[i]-1;
            int height = v[i];

            int side = min(height , width);

            area = max(area , side*side);
        }

        return area;
    } 

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int area = 0;
        vector<int> heights(m , 0);

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }

            area = max(area , squareArea(heights));
        }

        return area;
    }
};