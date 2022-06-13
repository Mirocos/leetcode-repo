//
// Created by zeming on 22-6-13.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{

public:

    void stepAdd(const vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> per_ans, int sum, int start){

        if(sum > target)
            return;

        if(sum == target){
            ans.push_back(per_ans);
            return;
        }

        if(sum < target){
            for(int i = start; i < candidates.size(); ++i){

                per_ans.push_back(candidates[i]);
                stepAdd(candidates, target, ans, per_ans, sum + candidates[i], i);
                per_ans.pop_back();
            }
        }

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> per_ans;
        stepAdd(candidates, target, ans, per_ans, 0, 0);
        return ans;
    }
};



int main(){
    Solution s;
    vector<int> candidates{100,200,4,12};
    int target = 400;

    auto ans = s.combinationSum(candidates, target);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << (j == ans[i].size()-1? "\n":" ");
        }
    }
    return 0;
}
