class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
            string comb=s+s;
            return comb.find(goal)!=string::npos;
    }
};