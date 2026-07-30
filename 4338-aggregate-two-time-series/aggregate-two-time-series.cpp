class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        int i=series1.size()-1;
        int j=series2.size()-1;
        vector<vector<int>> ans;
        int value1=0;
        int value2=0;
        while(i>=0 || j>=0){
            if(j<0 || (i>=0 && series1[i][0] > series2[j][0])){
                ans.push_back({series1[i][0],series1[i][1]+value2});
                value1=series1[i][1];
                i--;
            }
            else if(i<0 || (j>=0 && series2[j][0] > series1[i][0])){
                ans.push_back({series2[j][0], series2[j][1]+value1});
                value2=series2[j][1];
                j--;
            }
            else{
                ans.push_back({series1[i][0],series1[i][1]+series2[j][1]});
                value1=series1[i][1];
                value2=series2[j][1];
                i--;
                j--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};