#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int processar(vector<int>& dados, int ini, int fim) {
        if (ini >= fim) {
            return 0;
        }

        int meio = ini + ((fim - ini) >> 1);
        int pares = 0;

        pares += processar(dados, ini, meio);
        pares += processar(dados, meio + 1, fim);

        int p2 = meio + 1;
        for (int p1 = ini; p1 <= meio; p1++) {
            while (p2 <= fim && (long long)dados[p1] > 2LL * dados[p2]) {
                p2++;
            }
            pares += p2 - (meio + 1);
        }

        vector<int> temp;
        temp.reserve(fim - ini + 1);
        int p1 = ini;
        p2 = meio + 1;

        while (p1 <= meio && p2 <= fim) {
            if (dados[p1] <= dados[p2]) {
                temp.push_back(dados[p1++]);
            } else {
                temp.push_back(dados[p2++]);
            }
        }
        while (p1 <= meio) {
            temp.push_back(dados[p1++]);
        }
        while (p2 <= fim) {
            temp.push_back(dados[p2++]);
        }
        
        copy(temp.begin(), temp.end(), dados.begin() + ini);

        return pares;
    }

public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        return processar(nums, 0, nums.size() - 1);
    }
};