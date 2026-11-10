class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int , int>> pq;

        int n = arr.size();

        unordered_map<int , int> um;
        for(int i = 0 ; i < n ; ++i){
            um[arr[i]]++;
        }

        for(auto p : um){
            pq.push({p.second , p.first});
        }

        int freqSum = 0;
        int count = 0;
        while(freqSum < n/2){
            freqSum += pq.top().first;
            count++;
            pq.pop();
        }

        return count;
    }
};