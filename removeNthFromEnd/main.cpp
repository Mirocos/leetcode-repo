//
// Created by zeming on 22-5-27.
//

#include <iostream>
#include <vector>

using namespace std;


struct ListNode{
    int val;

    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};


class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){

        int size = 0;
        ListNode* L = head;
        while(L){
            size++;
            L = L->next;
        }
        n = size - n + 1;
        if(n == 1)
            return head->next;
        int cnt = 0;

        ListNode* pre = head;
        ListNode* cur = head;
        while(cur){
            cnt++;
            if(cnt == n){
                pre->next = cur->next;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

ListNode* ConstructList(vector<int> v){
    ListNode* L;
    ListNode* p;

    for(int i = 0; i < v.size(); ++i){

        if(i == 0){
            p = new ListNode(v[i]);
            L = p;
        } else {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
    }

    return L;

}


int main(){
    vector<int> v{1,2};
    ListNode* L = ConstructList(v);


    return 0;
}

