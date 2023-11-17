class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s = "";
        for(int i = 0 ;i<nums.size();i++){
            if(nums[i][i] == '1') s.push_back('0');
            else s.push_back('1');
        }
        return s;
    }
};