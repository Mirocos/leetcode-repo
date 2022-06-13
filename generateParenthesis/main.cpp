//
// Created by zeming on 22-5-27.
//

#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution{
public:

    void traceback(vector<string>& ans, string& res, int left, int right){


        if(left != 0){
            res.push_back('(');
            traceback(ans, res, left-1, right);
            res.pop_back();
        }

        if(right != 0 && right > left){
            res.push_back(')');
            traceback(ans, res, left, right-1);
            res.pop_back();
        }

        if(left == 0 && right == 0){
            ans.push_back(res);
            return;
        }


    }

    vector<string> generateParenthesis(int n){
        vector<string> ret;
        string res="";
        traceback(ret, res, n, n);
        return ret;
    }
};

int main(){
    Solution solution;

    auto res = solution.generateParenthesis(1);
    for(auto s : res){
        cout << s << endl;
    }
    return 0;
}