class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int , int> um;

        for(int i = 0 ; i < nums.size() ; ++i){
            um[nums[i]]++;
        }

        int sum = 0;
        for(auto x : um){
            if(x.second == 1){
                sum += x.first;
            }
        }

        return sum;
    }
};