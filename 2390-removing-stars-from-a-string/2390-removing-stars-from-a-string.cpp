class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        string ans = "";

        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i] == '*' && st.size() > 0){
                st.pop();
            }

            if(s[i] != '*'){
                st.push(s[i]);
            }
        }

        while(st.size() > 0){
            char ch = st.top();
            ans += ch;
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};