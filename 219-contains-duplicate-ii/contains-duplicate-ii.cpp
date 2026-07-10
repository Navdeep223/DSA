class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        // unordered_map<int,int> mp;
        // for(int i=0;i<n;i++){
        //     if(mp.count(nums[i])&& i-mp[nums[i]]<=k){
        //         return true;
        //     }
        //     else 
        //     mp[nums[i]]=i;
            unordered_set<int> st;
            int i=0;
            for(int j=0;j<n;j++){
                if(st.count(nums[j]))
                return true;
                st.insert(nums[j]);
                if(st.size()>k){
                    st.erase(nums[i]);
                    i++;
                }
            }
        
        return false;
    }
};