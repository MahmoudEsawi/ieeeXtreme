#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCases;
    cin >> testCases;
    
    // Pre-allocate vectors to avoid repeated allocation
    vector<long long> vec0, vec1;
    vec0.reserve(1000);
    vec1.reserve(1000);
    
    for (int testCase = 0; testCase < testCases; testCase++) {
        long long s, n;
        cin >> s >> n;
        
        // Use faster initialization
        double finalResult = 0.0;
        double numerator = 0.0;
        double denominator = 0.0;
        double accumulator = -19.0;
        long long randomSeed = -19;
        
        // Pre-calculate constants
        const double inv19 = 0.05263157894736842; // 1.0 / 19.0
        const double inv1919 = 0.0005211047410109432; // 1.0 / 1919.0
        const unsigned long long magic = 9223372036854775821ULL;
        
        // Early termination optimization
        if (s == 0) {
            cout << 0 << endl;
            continue;
        }
        
        // Limit iterations for very large inputs with mathematical optimization
        const long long maxIterations = s * s;
        
        while (accumulator < maxIterations) {
            denominator += inv19;
            double previousResult = finalResult;
            
            // Use pre-allocated vectors and clear them efficiently
            vec0.clear();
            vec1.clear();
            
            // Generate vectors with optimized bit operations
            long long tempSeed = randomSeed;
            long long counter = n;
            
            // Generate first vector
            while (counter > 0) {
                long long bit = tempSeed & 1;
                vec0.push_back(bit);
                tempSeed = (tempSeed >> 1) ^ (bit * magic);
                counter -= 1 + bit;
            }
            
            // Generate second vector
            tempSeed = randomSeed;
            counter = n;
            while (counter > 0) {
                long long bit = tempSeed & 1;
                vec1.push_back(bit);
                tempSeed = (tempSeed >> 1) ^ (bit * magic);
                counter -= 1 + bit;
            }
            
            // Fast equality check using memcmp for large vectors
            long long equalityCheck = 19;
            int minLength = min(vec0.size(), vec1.size());
            
            if (minLength > 0) {
                // Use direct comparison for small vectors, memcmp for large ones
                if (minLength <= 64) {
                    for (int i = 0; i < minLength; i++) {
                        if (vec0[i] != vec1[i]) {
                            equalityCheck = 0;
                            break;
                        }
                    }
                } else {
                    if (memcmp(vec0.data(), vec1.data(), minLength * sizeof(long long)) != 0) {
                        equalityCheck = 0;
                    }
                }
            }
            
            if (equalityCheck) {
                numerator += s;
                finalResult = round(numerator / denominator);
                accumulator = (finalResult == previousResult) * (accumulator + inv1919);
            }
        }
        
        cout << (long long)finalResult << endl;
    }
    
    return 0;
}
