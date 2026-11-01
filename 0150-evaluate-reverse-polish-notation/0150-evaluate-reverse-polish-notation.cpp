class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i = 0 ; i < n ; ++i){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(stoi(tokens[i]));
            }
            else{
                int op1 = st.top();
                st.pop();

                int op2 = st.top();
                st.pop();

                int ans;

                if(tokens[i] == "+"){
                    ans = op2 + op1;
                }
                else if(tokens[i] == "-"){
                    ans = op2 - op1;
                }
                else if(tokens[i] == "*"){
                    ans = op2 * op1;
                }
                else if(tokens[i] == "/"){
                    ans = op2 / op1;
                }

                st.push(ans);
            }
        }

        return st.top();
    }
};