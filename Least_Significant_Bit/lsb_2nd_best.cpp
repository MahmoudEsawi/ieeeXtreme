#include <bits/stdc++.h>
using namespace std;

int lsb(int x) {
    return (x & (x - 1)) ^ x;
}
