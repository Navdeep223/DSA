class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        vector<int> ans(n);
        int index=n-1;
        while(left<=right){
         int leftsquare=nums[left]*nums[left];
         int rightsquare=nums[right]*nums[right];

         if(leftsquare>rightsquare){
            ans[index]=leftsquare;
            left++;
         }
         else{
            ans[index]=rightsquare;
            right--;
         }
         index--;
        }
        return ans;
    }
};