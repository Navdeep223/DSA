class Solution {
public:
    int sumofdiv(vector<int>&nums,int div){
        int sum=0;
        for(int num:nums){
            sum+=ceil((double)num / div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=*max_element(nums.begin(),nums.end());
        int low=1;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(sumofdiv(nums,mid)<=threshold){
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return low;
    }
};