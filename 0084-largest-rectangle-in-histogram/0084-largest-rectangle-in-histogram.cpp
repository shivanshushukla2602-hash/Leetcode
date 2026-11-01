class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ls(n , -1);
        stack<int> st1;

        for(int i = 0 ; i < n ; ++i){
            while(st1.size() > 0 && heights[st1.top()] >= heights[i]){
                st1.pop();
            }

            if(st1.size() > 0){
                ls[i] = st1.top();
            }

            st1.push(i);
        }

        vector<int> rs(n , n);
        stack<int> st2;

        for(int i = n-1 ; i >= 0 ; --i){
            while(st2.size() > 0 && heights[st2.top()] >= heights[i]){
                st2.pop();
            }

            if(st2.size() > 0){
                rs[i] = st2.top();
            }

            st2.push(i);
        }

        int area;
        for(int i = 0 ; i < n ; ++i){
            area = max(area , (rs[i] - ls[i] - 1)*heights[i]);
        }

        return area;
    }
};