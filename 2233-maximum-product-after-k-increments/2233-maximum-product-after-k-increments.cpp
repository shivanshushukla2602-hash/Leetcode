class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>> pq(nums.begin() , nums.end());

        for(int i = 1 ; i <= k ; ++i){
            int t = pq.top();
            pq.pop();
            pq.push(t+1);
        }

        long long ans = 1;
        while(pq.size() > 0){
            ans *= pq.top();
            pq.pop();

            ans %= 1000000007;
        }

        return ans;
    }
};