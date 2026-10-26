class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int>> pq(nums.begin() , nums.end());
        int kMax = INT_MIN;

        for(int i = 1 ; i <= k ; ++i){
            if(i == k){
                kMax = pq.top();
            }
            pq.pop();
        }

        return kMax;
    }
};