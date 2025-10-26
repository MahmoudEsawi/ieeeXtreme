// =============================================================================
// 🏆 IEEE Xtreme Competition - Add Two Numbers Solution
// جمع رقمين ممثلين بقوائم مرتبطة - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // الحل الأمثل للسرعة والذاكرة معاً
        // Optimal solution for both speed and memory
        ListNode* dummy = new ListNode(0);  // عقدة وهمية لتسهيل الإدارة
        ListNode* current = dummy;  // مؤشر للعقدة الحالية
        int carry = 0;  // متغير لحفظ القيمة المحمولة
        
        // تكرار حتى انتهاء كلا القائمتين أو وجود قيمة محمولة
        // Loop until both lists are exhausted or carry exists
        while (l1 || l2 || carry) {
            int sum = carry;  // بدء المجموع بالقيمة المحمولة
            
            // إضافة قيمة العقدة الأولى إذا كانت موجودة
            // Add first list value if exists
            if (l1) {
                sum += l1->val;
                l1 = l1->next;  // الانتقال للعقدة التالية
            }
            
            // إضافة قيمة العقدة الثانية إذا كانت موجودة
            // Add second list value if exists
            if (l2) {
                sum += l2->val;
                l2 = l2->next;  // الانتقال للعقدة التالية
            }
            
            // حساب القيمة المحمولة والرقم الحالي
            // Calculate carry and current digit
            carry = sum / 10;  // القيمة المحمولة
            current->next = new ListNode(sum % 10);  // إنشاء العقدة الجديدة
            current = current->next;  // الانتقال للعقدة التالية
        }
        
        // إرجاع النتيجة (تجاهل العقدة الوهمية)
        // Return result (skip dummy node)
        return dummy->next;
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأسرع والأذكى لجمع رقمين ممثلين بقوائم مرتبطة. الفكرة الأساسية إنه
// بنعمل عملية جمع عادية زي ما بنعمل باليد، بس مع متغير "carry" عشان نحفظ القيمة المحمولة.
// 
// الخوارزمية الأمثل للسرعة والذاكرة:
// 1. بنستخدم عقدة وهمية (dummy) عشان نسهل إدارة النتيجة (أسرع في التنفيذ)
// 2. بنعمل متغير carry عشان نحفظ القيمة المحمولة
// 3. بنروح نضيف كل عقدة من القائمتين مع carry
// 4. بنحسب carry الجديد والرقم الحالي
// 5. بنضيف العقدة الجديدة للنتيجة مباشرة (أسرع من البحث عن الذيل)
// 6. نكمل حتى ما نخلص القائمتين والـ carry
// 
// مثال: [2,4,3] + [5,6,4] = [7,0,8]
// - 2 + 5 = 7, carry = 0
// - 4 + 6 = 10, digit = 0, carry = 1
// - 3 + 4 + 1 = 8, carry = 0
// - النتيجة: [7,0,8]
// 
// المميزات:
// - تعقيد زمني: O(max(m,n)) حيث m,n أطوال القائمتين
// - تعقيد مكاني: O(max(m,n)) للنتيجة
// - عقدة وهمية للسرعة (أسرع في التنفيذ من البحث عن الذيل)
// - معالجة القيم المحمولة بكفاءة
// - كود بسيط وواضح (أقل أخطاء)
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(max(m,n)) - حيث m,n أطوال القائمتين
// Space Complexity: O(max(m,n)) - للنتيجة الجديدة
// Algorithm: Elementary addition with carry - جمع ابتدائي مع قيمة محمولة
// Best for: Competitive Programming - مثالي للبرمجة التنافسية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807
// 
// Example 2: l1 = [0], l2 = [0]
// Output: [0]
// Explanation: 0 + 0 = 0
// 
// Example 3: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
// Explanation: 9999999 + 9999 = 10009998
// 
// Edge Cases:
// - Different lengths: handled automatically
// - Carry propagation: handled correctly
// - Single digit: works perfectly
// - Large numbers: efficient processing

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        
        return dummy->next;
    }
};
