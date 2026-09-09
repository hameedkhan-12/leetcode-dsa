class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            int freq[26] = {};

            for (char c : s) {
                freq[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(freq[i]);
            }

            mp[key].push_back(s);
        }
        vector<vector<string>> result;

        for (auto& [key, group] : mp) {
            result.push_back(group);
        }
        return result;
    }
};