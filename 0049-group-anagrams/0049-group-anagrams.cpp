class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string str : strs) {
            int freq[26] = {};

            for (char c : str) {
                freq[c - 'a']++;
            }

            string key;
            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(freq[i]);
            }
            mp[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto &[key,value] : mp){
            result.push_back(value);
        }
        return result;
    }
};