#include <bits/stdc++.h>
using namespace std;

int bitcount(int x) {
    int cnt = 0;
    while (x) {
        x &= (x - 1);
        cnt++;
    }
    return cnt;
}
