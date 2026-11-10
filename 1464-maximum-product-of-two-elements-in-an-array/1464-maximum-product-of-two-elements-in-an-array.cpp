class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq(nums.begin() , nums.end());

        int maxProd = 1;

        int m1 = pq.top();
        pq.pop();

        int m2 = pq.top();
        pq.pop();

        maxProd = (m1 - 1) * (m2 - 1);

        return maxProd;
    }
};