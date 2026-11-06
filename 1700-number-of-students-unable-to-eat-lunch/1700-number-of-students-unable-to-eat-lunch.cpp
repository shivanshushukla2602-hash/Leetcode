class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        queue<int> q;

        int n = students.size();
        int count = 0;

        for(int i = 0 ; i < n ; ++i){
            q.push(students[i]);
        }

        for(int i = n-1 ; i >= 0 ; --i){
            st.push(sandwiches[i]);
        }

        while(q.size() > 0 && count < q.size()){
            if(st.top() == q.front()){
                q.pop();
                st.pop();
                count = 0;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }

        return q.size();
    }
};