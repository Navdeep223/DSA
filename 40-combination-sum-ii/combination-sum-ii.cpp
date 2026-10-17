class Solution {
public:
    void solve(int index,int sum, vector<int>&current,vector<int>&candidates,vector<vector<int>>&ans,int target){
        if(sum==target){
            ans.push_back(current);
            return;
        }
        if(index==candidates.size() || sum>target) return;
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
                }
                current.push_back(candidates[i]);
                solve(i+1,sum+candidates[i],current,candidates,ans,target);
                current.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        vector<vector<int>> ans;
        solve(0,0,current,candidates,ans,target);
        return ans;
    }
};