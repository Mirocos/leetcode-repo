//
// Created by zeming on 22-5-25.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution{

public:
    unordered_map<char, string> charMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };

    void dfs(vector<string>& ans, const string& digits, int pos, string& res){
        if(pos >= digits.size()) {
            ans.push_back(res);
        }

        int step = charMap[digits[pos]].size();
        for(int i = 0; i < step; ++i){
            res.push_back(charMap[digits[pos]][i]);
            dfs(ans, digits, pos+1, res);
            res.pop_back();
        }

    }

    vector<string> letterCombinations(string digits){

        vector<string> ret;
        int len = digits.size();
        if(len == 0)
            return ret;
        string res = "";
        dfs(ret, digits, 0, res);


        return ret;
    }
};



int main(){
    Solution solution;

    string digits = "23";
    auto res = solution.letterCombinations(digits);
    for(auto s : res){
        cout << s << endl;
    }
    return 0;
}