class Solution {
public:

    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) return false;

        unordered_map<char, int> letters;
        for (int i = 0; i < s.size(); i++) {

            letters[s.at(i)] += 1;
        }

        for (int i = 0; i < t.size(); i++) {

            if (letters[t.at(i)] == 0) return false;
            else letters[t.at(i)] -= 1;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        vector<string> miniResult;
        set<int> indicesTaken;

        for (int i = 0; i < strs.size(); i++) {

            if (indicesTaken.count(i) != 0) continue;

            miniResult.push_back(strs[i]);
            for (int j = i; j < strs.size(); j++) {

                if (isAnagram(strs[i], strs[j]) && i != j && indicesTaken.count(j) == 0) {
                    miniResult.push_back(strs[j]);
                    indicesTaken.insert(j);
                }
            }
            result.push_back(miniResult);
            miniResult.clear();
        }

        return result;
    }
};
