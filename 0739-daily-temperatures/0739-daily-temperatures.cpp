class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v(n , 0);
        stack<int> st;

        for(int i = n-1 ; i >= 0 ; --i){
            while(st.size() > 0 && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }

            if(st.size() > 0){
                v[i] = abs(i - st.top());
            }

            st.push(i);
        }

        return v;
    }
};