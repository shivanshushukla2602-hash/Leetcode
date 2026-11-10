class Solution {
public:
    class prio{
        public:
           bool operator()(pair<int , int> a , pair<int , int> b){
               return a.second < b.second;
           }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int , int> , vector<pair<int , int>> , prio> pq;

        unordered_map<int , int> um;
        vector<int> v;

        for(int i = 0 ; i < nums.size() ; ++i){
            um[nums[i]]++;
        }

        for(auto p : um){
            pq.push({p.first , p.second});
        }

        for(int i = 0 ; i < k ; ++i){
            v.push_back(pq.top().first);
            pq.pop();
        }

        return v;
    }
};