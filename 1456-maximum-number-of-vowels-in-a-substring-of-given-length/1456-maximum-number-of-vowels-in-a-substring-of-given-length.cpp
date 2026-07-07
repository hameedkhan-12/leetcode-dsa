class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0;
        int vowelCount = 0;
        int ans = 0;

        for(int right = 0; right<s.size(); right++){
            if(isVowel(s[right])){
                vowelCount++;
            }

            if(right - left + 1 > k){
                if(isVowel(s[left])){
                    vowelCount--;
                }
                left++;
            }

            if(right - left + 1 == k){
                ans = max(ans, vowelCount);
            }
        }
    return ans;
    }

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u';
    }
};