#include <bits/stdc++.h>
using namespace std;

int findDuplicate(const vector<int>& v) {
    int n = v.size();
    int tortoise = v[0];
    int hare = v[0];
    
    while (true) {
        tortoise = v[tortoise];
        hare = v[v[hare]];
        if (tortoise == hare) break;
    }
    
    tortoise = v[0];
    while (tortoise != hare) {
        tortoise = v[tortoise];
        hare = v[hare];
    }
    
    return tortoise;
}
