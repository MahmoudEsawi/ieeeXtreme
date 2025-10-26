// =============================================================================
// 🏆 IEEE Xtreme Competition - Closest Pair
// أقرب زوج - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <bits/stdc++.h>
using namespace std;

int closestPair(vector<int>& first, vector<int>& second) {
    // ترتيب المصفوفتين
    // Sort both arrays
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    int minDiff = INT_MAX;  // أصغر فرق تم العثور عليه
    int i = 0, j = 0;       // مؤشرات للمصفوفتين
    int n = first.size();
    
    // استخدام تقنية المؤشرين (Two Pointers)
    // Use two pointers technique
    while (i < n && j < n) {
        // حساب الفرق المطلق الحالي
        // Calculate current absolute difference
        minDiff = min(minDiff, abs(first[i] - second[j]));
        
        // تحريك المؤشر للعنصر الأصغر
        // Move pointer of smaller element
        if (first[i] < second[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return minDiff;
}

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل بيستخدم تقنية المؤشرين (Two Pointers) بعد ترتيب المصفوفتين.
// الفكرة: لما المصفوفات مرتبة، بنقدر نستخدم مؤشرين ونحركهم بذكاء
// عشان نلاقي أقرب زوج بدون ما نفحص كل الأزواج الممكنة.
// 
// الخوارزمية:
// 1. نرتب المصفوفتين
// 2. نبدأ بمؤشرين من البداية
// 3. نحسب الفرق المطلق للعنصرين الحاليين
// 4. نحرك المؤشر للعنصر الأصغر (عشان نقرب من العنصر التاني)
// 5. نكمل لحد ما نخلص إحدى المصفوفات
// 
// مثال: first = [4, 10, 4], second = [2, 6, 7]
// بعد الترتيب: first = [4, 4, 10], second = [2, 6, 7]
// - i=0, j=0: |4-2| = 2, first[0] > second[0], j++
// - i=0, j=1: |4-6| = 2, first[0] < second[1], i++
// - i=1, j=1: |4-6| = 2, first[1] < second[1], i++
// - i=2, j=1: |10-6| = 4, first[2] > second[1], j++
// - i=2, j=2: |10-7| = 3, first[2] > second[2], j++
// النتيجة: 2
// 
// المميزات:
// - تعقيد زمني: O(N log N) للترتيب + O(N) للمؤشرين
// - أسرع من O(N²) (فحص كل الأزواج)
// - استخدام تقنية المؤشرين الذكية
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <bits/stdc++.h>
using namespace std;

int closestPair(vector<int>& first, vector<int>& second) {
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    int minDiff = INT_MAX;
    int i = 0, j = 0;
    int n = first.size();
    
    while (i < n && j < n) {
        minDiff = min(minDiff, abs(first[i] - second[j]));
        
        if (first[i] < second[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return minDiff;
}
