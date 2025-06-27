#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto criterio = [](const auto* a, const auto* b) {
            return a->val > b->val;
        };

        vector<ListNode*> v;
        for (auto no_inicial : lists) {
            if (no_inicial) {
                v.push_back(no_inicial);
            }
        }

        make_heap(v.begin(), v.end(), criterio);

        ListNode cabeca_falsa;
        ListNode* ponta = &cabeca_falsa;

        while (!v.empty()) {
            pop_heap(v.begin(), v.end(), criterio);
            
            ListNode* no_atual = v.back();
            
            v.pop_back();

            ponta->next = no_atual;
            ponta = ponta->next;

            if (no_atual->next) {
                v.push_back(no_atual->next);
                push_heap(v.begin(), v.end(), criterio);
            }
        }

        return cabeca_falsa.next;
    }
};