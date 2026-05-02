class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> visited;

        for (size_t i = 0; i < nums.size(); i++) {

            if (visited.count(nums[i]) != 0) return true;
            else visited.insert(nums[i]);
        }

        return false;
    }
};