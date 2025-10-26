#include <bits/stdc++.h>
using namespace std;

int evenStepsElimination(int N) {
    // Based on Josephus problem formula from cp-algorithms.com
    if (N == 1) return 1;
    
    int power_of_2 = 1;
    while (power_of_2 * 2 <= N) {
        power_of_2 *= 2;
    }
    
    int result = 2 * (N - power_of_2) + 1;
    return result;
}
