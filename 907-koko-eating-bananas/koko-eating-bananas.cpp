class Solution {
public:
int fmax(vector<int> &piles){
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
long long hour(vector<int>&piles, int speed){
    long long counth=0;
    for(int pile:piles){
        counth+=(pile+speed-1)/speed;
    }
    return counth;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int mx=fmax(piles);
        int high=mx;
        int ans=mx;
        while(low<=high){
            int mid=(low+high)/2;
            long long thour=hour(piles,mid);
            if(thour<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};