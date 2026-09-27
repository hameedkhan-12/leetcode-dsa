class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string current = "";
        int num = 0;

        for(char c: s){
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }
            else if(c == '['){
                countStack.push(num);
                stringStack.push(current);

                num = 0;
                current = "";
            }
            else if(c == ']'){
                int count = countStack.top();
                countStack.pop();

                string previous = stringStack.top();
                stringStack.pop();
                string decoded = "";

                for(int i = 0; i<count; i++){
                    decoded += current;
                }
                current = previous + decoded;
            }
            else{
                current += c;
            }
        } 
        return current;
    }
};