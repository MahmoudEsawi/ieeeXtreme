#!/bin/bash

# 🏆 IEEE Xtreme Competition - Navigation Script
# سكريبت التنقل لمسابقة IEEE Xtreme

echo "🏆 IEEE Xtreme Competition - Solutions Navigator"
echo "================================================"
echo ""

echo "📁 Available Problems:"
echo "1. Two Sum Problem"
echo "2. Palindrome Number Problem"
echo "3. Roman to Integer Problem"
echo "4. Longest Common Prefix Problem"
echo "5. Add Two Numbers Problem"
echo "6. Longest Substring Without Repeating Characters"
echo "7. Median of Two Sorted Arrays"
echo "8. Longest Palindromic Substring"
echo "9. Regular Expression Matching"
echo "10. View Templates"
echo "11. View All Files"
echo ""

read -p "Enter your choice (1-11): " choice

case $choice in
    1)
        echo "📂 Opening Two Sum Problem folder..."
        cd 01_Two_Sum/
        echo "📋 Files available:"
        ls -la
        echo ""
        echo "🚀 Ready to submit: two_sum_clean.cpp"
        echo "📚 Learn from: two_sum_leetcode.cpp"
        echo "🧪 Test with: ./test_two_sum_cpp"
        ;;
    2)
        echo "📂 Opening Palindrome Number Problem folder..."
        cd 02_Palindrome_Number/
        echo "📋 Files available:"
        ls -la
        echo ""
        echo "🚀 Ready to submit: palindrome_number_clean.cpp"
        echo "📚 Learn from: palindrome_number_explained.cpp"
        echo "🧪 Test with: ./test_palindrome"
        ;;
    3)
        echo "📂 Opening Roman to Integer Problem folder..."
        cd 03_Roman_to_Integer/
        echo "📋 Files available:"
        ls -la
        echo ""
        echo "🚀 Ready to submit: roman_to_integer_final.cpp (ULTRA-FAST)"
        echo "📚 Learn from: roman_to_integer_explained.cpp"
        echo "🧪 Test with: ./test_optimized"
        echo "⚡ Performance: < 3ms, Beats > 80%"
        ;;
    4)
        echo "📂 Opening Longest Common Prefix Problem folder..."
        cd 04_Longest_Common_Prefix/
        echo "📋 Files available:"
        ls -la
        echo ""
        echo "🚀 Ready to submit: longest_common_prefix_SUBMIT.cpp (ULTRA-FAST)"
        echo "📚 Learn from: longest_common_prefix_explained.cpp"
        echo "⚡ Performance: < 1ms, Beats > 90%"
        ;;
    5)
        echo "📂 Opening Add Two Numbers Problem folder..."
        cd 05_Add_Two_Numbers/
        echo "📋 Files available:"
        ls -la
        echo ""
        echo "🚀 Ready to submit: add_two_numbers_SUBMIT.cpp (ULTRA-FAST)"
        echo "📚 Learn from: add_two_numbers_EXPLAINED.cpp"
        echo "⚡ Performance: < 2ms, Beats > 90%"
        ;;
    6)
        echo "📂 Opening Longest Substring Without Repeating Characters folder..."
        cd 06_Longest_Substring_Without_Repeating_Characters/
        echo "📋 Files available:"
        ls -la
        echo ""
        echo "🚀 Ready to submit: longest_substring_SUBMIT.cpp (ULTRA-FAST)"
        echo "📚 Learn from: longest_substring_EXPLAINED.cpp"
        echo "⚡ Performance: < 1ms, Beats > 90%"
        ;;
    7)
        echo "📂 Opening Median of Two Sorted Arrays folder..."
        cd 07_Median_of_Two_Sorted_Arrays/
        echo "📋 Files available:"
        ls -la
        echo ""
        echo "🚀 Ready to submit: median_SUBMIT.cpp (ULTRA-FAST)"
        echo "📚 Learn from: median_EXPLAINED.cpp"
        echo "⚡ Performance: < 1ms, Beats > 95%"
        ;;
    8)
        echo "📂 Opening Longest Palindromic Substring folder..."
        cd 08_Longest_Palindromic_Substring/
        echo "📋 Files available:"
        ls -la
        echo ""
        echo "🚀 Ready to submit: longest_palindrome_SUBMIT.cpp (ULTRA-FAST)"
        echo "📚 Learn from: longest_palindrome_EXPLAINED.cpp"
        echo "⚡ Performance: < 1ms, Beats > 90%"
        ;;
    9)
        echo "📂 Opening Regular Expression Matching folder..."
        cd 09_Regular_Expression_Matching/
        echo "📋 Files available:"
        ls -la
        echo ""
        echo "🚀 Ready to submit: regex_SUBMIT.cpp (ULTRA-FAST)"
        echo "📚 Learn from: regex_EXPLAINED.cpp"
        echo "⚡ Performance: < 1ms, Beats > 90%"
        ;;
    10)
        echo "📂 Available Templates:"
        echo "- python_template.py (Complete Python template)"
        echo "- cpp_template.cpp (Complete C++ template)"
        echo "- java_template.java (Complete Java template)"
        echo "- algorithm_cheatsheet.py (Quick reference)"
        echo "- utility_functions.py (Helper functions)"
        echo "- quick_reference.py (Code snippets)"
        ;;
    7)
        echo "📂 All Files in Repository:"
        find . -name "*.cpp" -o -name "*.py" -o -name "*.java" -o -name "*.md" | sort
        ;;
    *)
        echo "❌ Invalid choice. Please run the script again."
        ;;
esac

echo ""
echo "🏁 Happy coding! Good luck with IEEE Xtreme! 🚀"
