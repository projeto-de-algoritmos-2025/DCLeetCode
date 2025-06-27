#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> lado_a;
    priority_queue<int, vector<int>, greater<int>> lado_b;

    void ajustar() {
        if (lado_a.size() > lado_b.size() + 1) {
            lado_b.push(lado_a.top());
            lado_a.pop();
        } 
        else if (lado_b.size() > lado_a.size()) {
            lado_a.push(lado_b.top());
            lado_b.pop();
        }
    }

public:
    MedianFinder() = default;

    void addNum(int n) {
        if (lado_a.empty() || n <= lado_a.top()) {
            lado_a.push(n);
        } else {
            lado_b.push(n);
        }

        ajustar();
    }

    double findMedian() {
        const auto total = lado_a.size() + lado_b.size();

        if (total == 0) {
            throw runtime_error("Nao e possivel consultar a mediana de uma lista vazia.");
        }

        if (total % 2 != 0) {
            return static_cast<double>(lado_a.top());
        } 
        
        const double v1 = static_cast<double>(lado_a.top());
        const double v2 = static_cast<double>(lado_b.top());
        
        return (v1 + v2) * 0.5;
    }
};