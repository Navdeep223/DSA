class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        int i = series1.size() - 1;
        int j = series2.size() - 1;

        int nextValue1 = 0;
        int nextValue2 = 0;

        vector<vector<int>> ans;

        while (i >= 0 || j >= 0) {

            if (j < 0 || (i >= 0 && series1[i][0] > series2[j][0])) {

                // Timestamp exists only in series1
                ans.push_back({series1[i][0], series1[i][1] + nextValue2});

                nextValue1 = series1[i][1];
                i--;
            }
            else if (i < 0 || (j >= 0 && series2[j][0] > series1[i][0])) {

                // Timestamp exists only in series2
                ans.push_back({series2[j][0], nextValue1 + series2[j][1]});

                nextValue2 = series2[j][1];
                j--;
            }
            else {

                // Same timestamp in both series
                ans.push_back(
                    {series1[i][0], series1[i][1] + series2[j][1]});

                nextValue1 = series1[i][1];
                nextValue2 = series2[j][1];

                i--;
                j--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};