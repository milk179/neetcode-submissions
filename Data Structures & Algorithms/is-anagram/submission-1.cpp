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
};
