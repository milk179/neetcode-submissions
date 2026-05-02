class Solution {
public:

    string encode(vector<string>& strs) {

        string result;
        for (string s : strs) {

            string size = to_string(s.size());
            result += size;
            result += "#";
            result += s;
        }

        return result;
    }

    vector<string> decode(string s) {

        vector<string> result;

        for (int i = 0; i < s.size();) {

            int j = i;
            while (s.at(j) != '#') j++;

            int size = stoi(s.substr(i, j - i));

            j++;
            string tmp = s.substr(j, size);
            result.push_back(tmp);

            i = j + size;
        }
        return result;
    }
};
