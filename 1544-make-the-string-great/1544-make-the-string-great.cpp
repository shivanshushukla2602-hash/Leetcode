class Solution {
public:
    bool isLowerCase(char ch){
        return ch >= 'a' && ch <= 'z';
    }

    bool isUpperCase(char ch){
        return ch >= 'A' && ch <= 'Z';
    }

    string makeGood(string s) {
        stack<char> st;

        for(int i = 0 ; i < s.size() ; ++i){
            if(st.size() != 0 && tolower(st.top()) == tolower(s[i]) && ((isLowerCase(s[i]) && isUpperCase(st.top())) || (isLowerCase(st.top()) && isUpperCase(s[i])))){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string ans = "";
        while(st.size() > 0){
            char ch = st.top();
            ans += ch;

            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};