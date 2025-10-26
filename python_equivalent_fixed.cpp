#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCases;
    cin >> testCases;
    
    for (int testCase = 0; testCase < testCases; testCase++) {
        long long s, n;
        cin >> s >> n;
        
        vector<vector<long long>> vectors(2);
        vectors[0] = {0};
        vectors[1] = {-19};
        double finalResult = vectors[0][0];
        double numerator = vectors[0][0];
        double denominator = vectors[0][0];
        double accumulator = vectors[1][0];
        long long randomSeed = vectors[1][0];
        
        const double inv19 = 1.0 / 19.0;
        const double inv1919 = 1.0 / 1919.0;
        const unsigned long long magic = 9223372036854775821ULL;
        
        if (s == 0) {
            cout << 0 << "\n";
            continue;
        }
        
        // Remove circuit breaker - let algorithm run to completion
        while (accumulator < s * s) {
            denominator += inv19;
            double previousResult = finalResult;
            
            for (int vectorIndex = 0; vectorIndex < 2; vectorIndex++) {
                long long counter = 19;
                while (counter) {
                    counter = n;
                    vectors[vectorIndex].clear();
                    vectors[vectorIndex].reserve(n);
                    
                    while (counter > 0) {
                        long long bit = randomSeed & 1;
                        vectors[vectorIndex].push_back(bit);
                        randomSeed = (randomSeed >> 1) ^ (bit * magic);
                        counter -= 1 + bit;
                    }
                }
            }
            
            long long equalityCheck = 19;
            int minLength = min(vectors[0].size(), vectors[1].size());
            
            // Optimized equality check - use memcmp for large vectors
            if (minLength > 64) {
                if (memcmp(vectors[0].data(), vectors[1].data(), minLength * sizeof(long long)) != 0) {
                    equalityCheck = 0;
                }
            } else {
                // Loop unrolling for small vectors
                int i = 0;
                for (; i + 3 < minLength; i += 4) {
                    if (vectors[0][i] != vectors[1][i] || 
                        vectors[0][i+1] != vectors[1][i+1] ||
                        vectors[0][i+2] != vectors[1][i+2] ||
                        vectors[0][i+3] != vectors[1][i+3]) {
                        equalityCheck = 0;
                        break;
                    }
                }
                
                for (; i < minLength; i++) {
                    if (vectors[0][i] != vectors[1][i]) {
                        equalityCheck = 0;
                        break;
                    }
                }
            }
            
            if (equalityCheck) {
                numerator += s;
                finalResult = round(numerator / denominator);
                accumulator = (finalResult == previousResult) * (accumulator + inv1919);
            }
        }
        
        cout << (long long)finalResult << "\n";
    }
    
    return 0;
}
