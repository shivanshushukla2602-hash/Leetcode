class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> v(n1 , -1);
        unordered_map<int , int> um;
        stack<int> st;

        for(int i = n2-1 ; i >= 0 ; --i){
            while(st.size() > 0 && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.size() > 0){
                um[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for(int i = 0 ; i < n1 ; ++i){
            if(um.find(nums1[i]) != um.end()){
                v[i] = um[nums1[i]];
            }
        }

        return v;
    }
};