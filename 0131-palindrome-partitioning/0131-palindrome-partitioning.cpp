class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,s,curr,ans);
        return ans;
    }
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void solve(int ind, string &s, vector<string>&curr, vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = ind; i<s.size(); i++){
            if(isPalindrome(s,ind,i)){
                curr.push_back(s.substr(ind, i - ind + 1));
                solve(i+1,s, curr, ans);
                curr.pop_back();
            }
        }
    }
};