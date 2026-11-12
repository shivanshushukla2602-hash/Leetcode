class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> maxQ(nums.begin() , nums.end());
        priority_queue<int , vector<int> , greater<int>> minQ(nums.begin() , nums.end());

        int a = maxQ.top();
        maxQ.pop();

        int b = maxQ.top();
        maxQ.pop();

        int c = maxQ.top();
        maxQ.pop();

        int x = minQ.top();
        minQ.pop();

        int y = minQ.top();
        minQ.pop();

        int p1 = a*b*c;
        int p2 = x*y*a;

        int ans = max(p1 , p2);

        return ans;
    }
};