class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> um;
        priority_queue<pair<int , char>> pq;

        for(int i = 0 ; i < s.size() ; ++i){
            um[s[i]]++;
        }

        for(const auto &p : um){
            pq.push({p.second , p.first});
        }

        string ans = "";
        while(pq.size() > 0){
            pair<int , char> t = pq.top();
            pq.pop();

            int freq = t.first;
            char ch = t.second; 
            for(int i = 1 ; i <= freq ; ++i){
                ans += ch;
            }
        }

        return ans;
    }
};