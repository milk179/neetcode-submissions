class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> result; 

        for (int i = 0; i < nums.size(); i++) {
            
            int tmp = 1;

            for (int j = 0; j < nums.size(); j++) {

                if (j == i) continue;

                tmp *= nums[j];
            }

            result.push_back(tmp);
        }

        return result;
    }
};
