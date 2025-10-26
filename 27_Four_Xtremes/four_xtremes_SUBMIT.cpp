#include <bits/stdc++.h>
using namespace std;

int fourXtremes(int a, int b, int c, int d) {
    int maxVal = max({a, b, c, d});
    int minVal = min({a, b, c, d});
    return maxVal - minVal;
}
