class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(0, s.size()-1,s);
    }
    void reverse(int left, int right, vector<char> &s){
        if(left>=right) return;

        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        reverse(left+1, right-1, s);
    }
};