class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> freq;
        for (int i : nums) freq[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& p : freq) {

            pq.push(pair(p.second, p.first));
            if (pq.size() > k) pq.pop();
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {

            auto p = pq.top();
            pq.pop();
            result.push_back(p.second);
        }

        return result;

    }
};
