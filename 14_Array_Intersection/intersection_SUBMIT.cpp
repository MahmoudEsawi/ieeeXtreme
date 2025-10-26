#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> arrayIntersection(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freq;
    vector<int> result;
    
    for (int num : arr1) {
        freq[num]++;
    }
    
    for (int num : arr2) {
        if (freq[num] > 0) {
            result.push_back(num);
            freq[num]--;
        }
    }
    
    return result;
}
