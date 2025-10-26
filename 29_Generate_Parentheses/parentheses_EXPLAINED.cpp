// =============================================================================
// 🏆 IEEE Xtreme Competition - Generate Parentheses
// توليد الأقواس - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <bits/stdc++.h>
using namespace std;

void backtrack(string& current, int open, int close, int n) {
    // إذا وصلنا للطول المطلوب (2*n)، نطبع السلسلة
    // If we reached the required length (2*n), print the string
    if (current.length() == 2 * n) {
        cout << current << "\n";
        return;
    }
    
    // إضافة قوس فتح إذا كان عدد الأقواس المفتوحة أقل من n
    // Add opening bracket if number of open brackets < n
    if (open < n) {
        current += '(';
        backtrack(current, open + 1, close, n);
        current.pop_back();  // backtrack
    }
    
    // إضافة قوس إغلاق إذا كان عدد الأقواس المغلقة أقل من المفتوحة
    // Add closing bracket if number of close brackets < open brackets
    if (close < open) {
        current += ')';
        backtrack(current, open, close + 1, n);
        current.pop_back();  // backtrack
    }
}

void generateParentheses(int N) {
    string current = "";  // السلسلة الحالية
    backtrack(current, 0, 0, N);  // البدء بصفر أقواس
}

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل بيستخدم تقنية Backtracking لتوليد جميع سلاسل الأقواس الصحيحة.
// الفكرة: بنبني كل سلسلة خطوة بخطوة، وبنحرص إنها تضل صحيحة.
// 
// القواعد:
// 1. عدد الأقواس المفتوحة '(' لازم يكون <= N
// 2. عدد الأقواس المغلقة ')' لازم يكون <= عدد الأقواس المفتوحة
// 
// الخوارزمية:
// 1. نبدأ بسلسلة فارغة
// 2. في كل خطوة، نجرب إضافة '(' أو ')'
// 3. نضيف '(' إذا open < N
// 4. نضيف ')' إذا close < open
// 5. لما نوصل للطول 2*N، نطبع السلسلة
// 
// مثال: N=2
// - "" -> "(" -> "((" -> "(())" -> طباعة
// - "" -> "(" -> "()" -> "()()" -> طباعة
// النتيجة: "(())", "()()"
// 
// المميزات:
// - توليد جميع السلاسل الصحيحة
// - ترتيب معجمي تلقائي (نضيف '(' قبل ')')
// - تعقيد زمني: O(4^N / sqrt(N)) - عدد كاتالان
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <bits/stdc++.h>
using namespace std;

void backtrack(string& current, int open, int close, int n) {
    if (current.length() == 2 * n) {
        cout << current << "\n";
        return;
    }
    
    if (open < n) {
        current += '(';
        backtrack(current, open + 1, close, n);
        current.pop_back();
    }
    
    if (close < open) {
        current += ')';
        backtrack(current, open, close + 1, n);
        current.pop_back();
    }
}

void generateParentheses(int N) {
    string current = "";
    backtrack(current, 0, 0, N);
}
