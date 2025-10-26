// =============================================================================
// 🏆 IEEE Xtreme Competition - Generate Combinations
// توليد التوافيق - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, int n, int k, vector<int>& current) {
    // إذا وصلنا للحجم المطلوب، نطبع التوافق
    // If we reached the required size, print the combination
    if (current.size() == k) {
        for (int i = 0; i < k; ++i) {
            cout << current[i];
            if (i < k - 1) cout << " ";
        }
        cout << "\n";
        return;
    }
    
    // جرب إضافة كل رقم من start إلى n
    // Try adding each number from start to n
    for (int i = start; i <= n; ++i) {
        current.push_back(i);           // إضافة الرقم
        backtrack(i + 1, n, k, current); // استدعاء تكراري
        current.pop_back();              // حذف الرقم (backtrack)
    }
}

void generateCombinations(int N, int K) {
    vector<int> current;  // التوافق الحالي
    backtrack(1, N, K, current);  // البدء من الرقم 1
}

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل بيستخدم تقنية Backtracking (الرجوع للخلف) لتوليد جميع التوافيق.
// الفكرة: بنبني كل توافق خطوة بخطوة، وبنجرب كل الإمكانيات.
// 
// الخوارزمية:
// 1. نبدأ بتوافق فارغ
// 2. نضيف رقم من الأرقام المتاحة
// 3. نستدعي الدالة تكرارياً لإضافة الأرقام التالية
// 4. لما نوصل للحجم المطلوب K، نطبع التوافق
// 5. نحذف آخر رقم (backtrack) ونجرب رقم تاني
// 
// مثال: N=4, K=2
// - [1] -> [1,2] -> طباعة -> backtrack -> [1,3] -> طباعة -> ...
// - [2] -> [2,3] -> طباعة -> backtrack -> [2,4] -> طباعة -> ...
// - [3] -> [3,4] -> طباعة
// 
// المميزات:
// - توليد جميع التوافيق بترتيب معجمي
// - استخدام Backtracking الكلاسيكي
// - تعقيد زمني: O(C(N,K)) حيث C(N,K) عدد التوافيق
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, int n, int k, vector<int>& current) {
    if (current.size() == k) {
        for (int i = 0; i < k; ++i) {
            cout << current[i];
            if (i < k - 1) cout << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = start; i <= n; ++i) {
        current.push_back(i);
        backtrack(i + 1, n, k, current);
        current.pop_back();
    }
}

void generateCombinations(int N, int K) {
    vector<int> current;
    backtrack(1, N, K, current);
}
