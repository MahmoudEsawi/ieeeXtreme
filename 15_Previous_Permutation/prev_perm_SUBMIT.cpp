#include <bits/stdc++.h>
using namespace std;

bool previousPermutation(vector<int>& permutation) {
    int n = permutation.size();
    
    // Step 1: Find rightmost position where perm[i] > perm[i+1]
    int i = n - 2;
    while (i >= 0 && permutation[i] <= permutation[i + 1]) {
        i--;
    }
    
    // If no such position, this is the smallest permutation
    if (i < 0) {
        return false;
    }
    
    // Step 2: Find largest j > i where perm[j] < perm[i]
    int j = n - 1;
    while (j > i && permutation[j] >= permutation[i]) {
        j--;
    }
    
    // Step 3: Swap elements at i and j
    swap(permutation[i], permutation[j]);
    
    // Step 4: Reverse the suffix starting at i+1
    reverse(permutation.begin() + i + 1, permutation.end());
    
    return true;
}
