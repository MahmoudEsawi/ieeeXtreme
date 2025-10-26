// =============================================================================
// 🏆 IEEE Xtreme Competition - Anagrams
// المفردات المتناظرة - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // تسريع الإدخال والإخراج
    // Speed up input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;  // عدد الكلمات
    
    // خريطة لحفظ تكرار كل كلمة مرتبة
    // Map to store frequency of each sorted word
    unordered_map<string, int> freq;
    int maxCnt = 0;  // أكبر مجموعة من الكلمات المتناظرة
    
    // قراءة ومعالجة كل كلمة
    // Read and process each word
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        
        // ترتيب الحروف أبجدياً (الكلمات المتناظرة ستكون متطابقة بعد الترتيب)
        // Sort letters alphabetically (anagrams will be identical after sorting)
        sort(word.begin(), word.end());
        
        // زيادة عدد هذه الكلمة المرتبة
        // Increment count for this sorted word
        freq[word]++;
        
        // تحديث أكبر عدد
        // Update maximum count
        maxCnt = max(maxCnt, freq[word]);
    }
    
    // طباعة النتيجة
    // Print result
    cout << maxCnt << endl;
    
    return 0;
}

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأسرع والأذكى لإيجاد أكبر مجموعة من الكلمات المتناظرة (anagrams).
// الفكرة الأساسية إنه الكلمات المتناظرة راح تكون متطابقة لما نرتب حروفها.
// 
// الخوارزمية:
// 1. بنقرأ عدد الكلمات n
// 2. بنعمل خريطة (map) عشان نحفظ تكرار كل كلمة مرتبة
// 3. لكل كلمة:
//    - بنرتب حروفها أبجدياً
//    - بنزيد العدد للكلمة المرتبة في الخريطة
//    - بنحدث أكبر عدد شفناه
// 4. بنطبع أكبر عدد
// 
// مثال: "cats", "acts", "dogs"
// - "cats" -> sort -> "acst" -> freq["acst"] = 1
// - "acts" -> sort -> "acst" -> freq["acst"] = 2
// - "dogs" -> sort -> "dgos" -> freq["dgos"] = 1
// النتيجة: 2 (أكبر مجموعة)
// 
// المميزات:
// - تعقيد زمني: O(n × m × log m) حيث n عدد الكلمات، m متوسط طول الكلمة
// - تعقيد مكاني: O(n) للخريطة
// - حل بسيط ومباشر
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(n × m × log m) - n words, m average word length
// Space Complexity: O(n) - for the hash map
// Algorithm: Sort + Hash Map - ترتيب + خريطة تجزئة
// Best for: Competitive Programming - مثالي للبرمجة التنافسية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1:
// Input: ["cats", "caller", "dogs", "cellar", "parrots", "recall"]
// Output: 3
// Explanation: caller, cellar, recall are anagrams
// 
// Example 2:
// Input: ["disease", "burned", "viewer", "praised", "despair", "burden", "diapers", "review"]
// Output: 3
// Explanation: praised, despair, diapers are anagrams
// 
// Edge Cases:
// - All words are anagrams: returns n
// - No anagrams: returns 1
// - Single word: returns 1

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    unordered_map<string, int> freq;
    int maxCnt = 0;
    
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        
        sort(word.begin(), word.end());
        freq[word]++;
        maxCnt = max(maxCnt, freq[word]);
    }
    
    cout << maxCnt << endl;
    
    return 0;
}
