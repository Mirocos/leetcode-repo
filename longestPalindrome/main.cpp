//
// Created by zeming on 22-5-24.
//



#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
        int len = s.length();
        if(len == 1)
            return s;
        vector<vector<bool>> legal(len, vector<bool>(len, false));
        int maxlen = 1, begin = 0;
        for(int i = 0; i < len; ++i)
            legal[i][i] = true;

        for(int ret_len = 2; ret_len <= len; ++ret_len){
            for(int i = 0; i < len; ++i){
                int j = ret_len + i - 1;
                if(j >= len)
                    break;
                if(s[i] != s[j])
                    legal[i][j] = false;
                else {
                    if(ret_len <= 3)
                        legal[i][j] = true;
                    else
                        legal[i][j] = legal[i+1][j-1];
                }

                if(legal[i][j] && ret_len > maxlen){
                    begin = i;
                    maxlen = ret_len;
                }
            }
        }

        return s.substr(begin, maxlen);
    }
};



int main(){
    string s = "aaaa";
    Solution solution;
    cout << solution.longestPalindrome(s);



    return 0;
}