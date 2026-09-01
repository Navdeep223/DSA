class Solution {
public:
    int daysreq(vector<int> &weights,int capacity){
        int day=1;
        int currentweight=0;
        for(int w:weights){
            if(currentweight+w > capacity){
                day++;
                currentweight=w;
            }
            else{
                currentweight+=w;
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=*max_element(weights.begin(),weights.end());
        int sum=accumulate(weights.begin(),weights.end(),0);
        while(maxi<=sum){
            int mid=(maxi+sum)/2;
            if(daysreq(weights,mid)<=days)
            sum=mid-1;
            else
            maxi=mid+1;
        }
        return maxi;
    }
};