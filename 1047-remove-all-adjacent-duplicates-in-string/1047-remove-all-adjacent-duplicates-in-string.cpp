class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        st.push(s[0]);
        for(int i = 1 ; i < s.size() ; ++i){
            if(st.size() > 0 && s[i] == st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        } 

        string ns = "";
        while(st.size() > 0){
            ns = ns + st.top();
            st.pop();
        }

        reverse(ns.begin() , ns.end());

        return ns;
    }
};