class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int , int>> v;

        for(int i = 0 ; i < nums.size() ; ++i){
            v.push_back({nums[i] , i});
        }

        sort(v.begin() , v.end());

        int p1 = 0 , p2 = nums.size() - 1;

        while(p1 <= p2){
            if(v[p1].first + v[p2].first > target){
                p2--;
            }
            else if(v[p1].first + v[p2].first < target){
                p1++;
            }
            else{
                return {v[p1].second , v[p2].second};
            }
        }

        return {};
    }
};