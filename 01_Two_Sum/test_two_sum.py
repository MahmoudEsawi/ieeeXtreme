#!/usr/bin/env python3
# هذا السطر يخبر النظام أن يستخدم Python 3 لتشغيل الملف
"""
Two Sum Problem - Test Solution
مشكلة مجموع رقمين - حل الاختبار
"""

def two_sum_hashmap(nums, target):
    """
    Hash Map Solution - O(n) time, O(n) space
    Optimal solution for competitive programming
    
    حل باستخدام خريطة التجزئة - تعقيد زمني O(n)، تعقيد مكاني O(n)
    الحل الأمثل للبرمجة التنافسية
    """
    num_to_index = {}  # إنشاء قاموس فارغ لحفظ الأرقام وفهارسها
    
    for i, num in enumerate(nums):  # تكرار عبر كل رقم في المصفوفة مع فهرسه
        complement = target - num  # حساب الرقم المكمل (الرقم المطلوب للوصول للهدف)
        if complement in num_to_index:  # إذا كان الرقم المكمل موجود في القاموس
            return [num_to_index[complement], i]  # إرجاع فهارس الرقمين
        num_to_index[num] = i  # إضافة الرقم الحالي وفهرسه للقاموس
    
    return []  # إرجاع قائمة فارغة إذا لم يتم العثور على حل

# هاد الحل هو الأسرع والأذكى للبرمجة التنافسية. بدل ما نروح نفحص كل رقم مع كل رقم تاني
# (وهيك راح ياخد وقت طويل)، احنا بنحفظ كل رقم شفناه في قاموس مع رقمه في المصفوفة.
# بعدين كل مرة نشوف رقم جديد، بنحسب إيش الرقم اللي لازم نجمعو معاه عشان نوصل للهدف.
# إذا هاد الرقم موجود في القاموس، يبقى لقينا الحل! هيك الحل ياخد وقت خطي فقط
# (يعني إذا عندك 1000 رقم، راح ياخد 1000 خطوة مش مليون خطوة زي الحل التاني).

def two_sum_brute_force(nums, target):
    """
    Brute Force Solution - O(n²) time, O(1) space
    حل القوة الغاشمة - تعقيد زمني O(n²)، تعقيد مكاني O(1)
    """
    n = len(nums)  # حفظ طول المصفوفة في متغير
    for i in range(n):  # حلقة خارجية للرقم الأول
        for j in range(i + 1, n):  # حلقة داخلية للرقم الثاني (بدءاً من الرقم التالي)
            if nums[i] + nums[j] == target:  # إذا كان مجموع الرقمين يساوي الهدف
                return [i, j]  # إرجاع فهارس الرقمين
    return []  # إرجاع قائمة فارغة إذا لم يتم العثور على حل

# هاد الحل هو الحل البسيط والواضح. بنروح نفحص كل رقم مع كل رقم تاني في المصفوفة
# ونشوف إذا مجموعهم بيساوي الهدف اللي بدنا إياه. الحل صحيح 100% بس بطيء شوي
# لأنه إذا عندك 1000 رقم، راح يفحص مليون تركيبة ممكنة. بس الميزة إنه ما بياخد
# مساحة إضافية في الذاكرة، كل شي بيشتغل على المصفوفة الأصلية.

def test_solutions():
    """Test all solutions with provided examples
    اختبار جميع الحلول بالأمثلة المعطاة"""
    test_cases = [  # قائمة حالات الاختبار
        ([2, 7, 11, 15], 9, [0, 1]),  # حالة اختبار 1: مصفوفة، هدف، النتيجة المتوقعة
        ([3, 2, 4], 6, [1, 2]),       # حالة اختبار 2
        ([3, 3], 6, [0, 1])           # حالة اختبار 3
    ]
    
    print("🏆 Two Sum Problem - Competitive Programming Solutions")
    print("مشكلة مجموع رقمين - حلول البرمجة التنافسية")
    print("=" * 60)  # طباعة خط من علامات المساواة
    print()  # سطر فارغ
    
    for i, (nums, target, expected) in enumerate(test_cases, 1):  # تكرار عبر حالات الاختبار
        print(f"📝 Test Case {i}:")  # طباعة رقم حالة الاختبار
        print(f"   Input: nums = {nums}, target = {target}")  # طباعة المدخلات
        print(f"   Expected: {expected}")  # طباعة النتيجة المتوقعة
        print()  # سطر فارغ
        
        # Test hash map (optimal solution)
        # اختبار حل خريطة التجزئة (الحل الأمثل)
        result_hm = two_sum_hashmap(nums, target)  # استدعاء دالة الحل الأمثل
        print(f"   🚀 Hash Map Solution (O(n)): {result_hm} {'✅' if result_hm == expected else '❌'}")
        # طباعة نتيجة الحل الأمثل مع رمز النجاح أو الفشل
        
        # Test brute force
        # اختبار حل القوة الغاشمة
        result_bf = two_sum_brute_force(nums, target)  # استدعاء دالة الحل البسيط
        print(f"   💪 Brute Force Solution (O(n²)): {result_bf} {'✅' if result_bf == expected else '❌'}")
        # طباعة نتيجة الحل البسيط مع رمز النجاح أو الفشل
        
        print("   " + "-" * 50)  # طباعة خط فاصل
        print()  # سطر فارغ

# هاد الحل هو اللي بختبر الحلين اللي فوق. بنحط أمثلة مختلفة ونشوف إذا الحلين
# بيرجعوا نفس النتيجة اللي متوقعينها. كل مثال فيه مصفوفة أرقام وهدف معين
# والنتيجة المتوقعة. بعدين بنطبع النتائج مع علامة صح أو خطأ عشان نشوف
# إذا الحلول شغالة صح. هيك نقدر نتأكد إنه الكود شغال زي ما بدنا إياه.

if __name__ == "__main__":  # إذا كان الملف يتم تشغيله مباشرة (وليس استيراد)
    test_solutions()  # استدعاء دالة الاختبار
    
    print("🎯 Algorithm Analysis:")  # طباعة عنوان تحليل الخوارزمية
    print("تحليل الخوارزمية:")
    print("=" * 30)  # خط فاصل
    print("1. Hash Map Solution:")  # عنوان الحل الأول
    print("1. حل خريطة التجزئة:")
    print("   - Time Complexity: O(n)")  # التعقيد الزمني
    print("   - التعقيد الزمني: O(n)")
    print("   - Space Complexity: O(n)")  # التعقيد المكاني
    print("   - التعقيد المكاني: O(n)")
    print("   - Best for: Competitive programming, large datasets")  # أفضل استخدام
    print("   - الأفضل لـ: البرمجة التنافسية، مجموعات البيانات الكبيرة")
    print()  # سطر فارغ
    print("2. Brute Force Solution:")  # عنوان الحل الثاني
    print("2. حل القوة الغاشمة:")
    print("   - Time Complexity: O(n²)")  # التعقيد الزمني
    print("   - التعقيد الزمني: O(n²)")
    print("   - Space Complexity: O(1)")  # التعقيد المكاني
    print("   - التعقيد المكاني: O(1)")
    print("   - Best for: Small datasets, memory-constrained environments")  # أفضل استخدام
    print("   - الأفضل لـ: مجموعات البيانات الصغيرة، البيئات محدودة الذاكرة")
    print()  # سطر فارغ
    print("🏁 Recommendation: Use Hash Map solution for IEEE Xtreme competition!")
    print("🏁 التوصية: استخدم حل خريطة التجزئة لمسابقة IEEE Xtreme!")

# =============================================================================
# 🚀 BEST SOLUTION - READY FOR COPY PASTE
# =============================================================================

def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    target = int(input())
    
    num_to_index = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_to_index:
            print(num_to_index[complement], i)
            return
        num_to_index[num] = i
    
    print(-1, -1)

if __name__ == "__main__":
    solve()
