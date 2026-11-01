class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char , int>> st;

        for(int i = 0 ; i < s.size() ; ++i){
            if(st.size() == 0 || st.top().first != s[i]){
                st.push({s[i] , 1});
            }
            else{
                st.top().second++;

                if(st.top().second == k){
                    st.pop();
                }
            }
        }

        string ans = "";
        while(st.size() > 0){
            char ch = st.top().first;
            int freq = st.top().second;

            ans.append(freq , ch);

            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};