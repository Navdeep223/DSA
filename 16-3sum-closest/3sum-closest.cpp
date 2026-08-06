class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int closestsum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int currentsum=nums[i]+nums[left]+nums[right];
                if(abs(currentsum-target)<abs(closestsum-target)){
                    closestsum=currentsum;
                }
                if(currentsum==target) return currentsum;
                else if(currentsum<target) left++;
                else right--;
            }
        }
        return closestsum;
    }
};