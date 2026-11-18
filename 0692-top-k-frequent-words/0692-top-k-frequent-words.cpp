class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> um;
        for(int i = 0 ; i < words.size() ; ++i){
            um[words[i]]++;
        }

        priority_queue<pair<int,string> , vector<pair<int , string>> ,greater<pair<int , string>>> pq;

        for(const auto &p : um){
            pq.push({-p.second , p.first});
        } 

        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};