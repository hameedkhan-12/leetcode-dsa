class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int num: nums){
            freq[num]++;
        }
        vector<pair<int,int>> arr;
        for(auto &[key,value] : freq){
            arr.push_back({value, key});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};