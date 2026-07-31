class Solution {
public:
 void allsubs(int index, vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans){
    if(index==nums.size()){
        ans.push_back(subset);
        return;
    }
    subset.push_back(nums[index]);
    allsubs(index+1,nums,subset,ans);
    subset.pop_back();
    allsubs(index+1,nums,subset,ans);
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        allsubs(0,nums,subset,ans);
        return ans;
    }
};