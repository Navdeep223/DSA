class Solution {
public:
    bool ispossible(int day, vector<int>& bloomDay, int m, int k) {
        int count = 0;
        int bouquet = 0;
        for(int bloom : bloomDay) {
            if(bloom <= day) {
                count++;
                if(count == k) {
                    bouquet++;
                    count = 0;
                }
            }
            else {
                count = 0;
            }
        }
        return bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalflowers = 1LL * m * k;
        if(totalflowers > bloomDay.size())
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(ispossible(mid, bloomDay, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};