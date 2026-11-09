class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>> pq(nums.begin() , nums.end());
        int n = pq.size();
        
        for(int i = 1 ; i <= n-k ; ++i){
            pq.pop();
        }

        return pq.top();
    }
};