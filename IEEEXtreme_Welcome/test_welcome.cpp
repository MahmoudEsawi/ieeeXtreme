#include <iostream>
using namespace std;

void welcome_optimal() {
    cout << "Hello IEEEXtreme team!" << endl;
    cout << "Thank you for organizing this amazing programming competition." << endl;
    cout << "These challenges help us grow as problem solvers and coders." << endl;
    cout << "Looking forward to tackling all the problems!" << endl;
    cout << "Best regards from a passionate competitor." << endl;
}

void welcome_2nd_best() {
    cout << "Greetings IEEEXtreme team!" << endl;
    cout << "Thank you for organizing this incredible programming competition." << endl;
    cout << "These challenges help us develop as problem solvers and programmers." << endl;
    cout << "Excited to solve all the problems!" << endl;
    cout << "Best wishes from an enthusiastic participant." << endl;
}

void test_solutions() {
    cout << "🧪 Testing IEEEXtreme Welcome Message Solutions\n";
    cout << "=============================================\n\n";
    
    cout << "📝 Optimal Solution Output:\n";
    cout << "---------------------------\n";
    welcome_optimal();
    
    cout << "\n📝 2nd Best Solution Output:\n";
    cout << "----------------------------\n";
    welcome_2nd_best();
    
    cout << "\n📊 Analysis:\n";
    cout << "• Both solutions output appropriate welcome messages\n";
    cout << "• Messages are under 200 words as required\n";
    cout << "• Different wording but same sentiment\n";
    cout << "• Both express gratitude and enthusiasm\n";
    
    cout << "\n🔍 Key Differences:\n";
    cout << "• Optimal: 'Hello' vs 2nd Best: 'Greetings'\n";
    cout << "• Optimal: 'amazing' vs 2nd Best: 'incredible'\n";
    cout << "• Optimal: 'grow' vs 2nd Best: 'develop'\n";
    cout << "• Optimal: 'coders' vs 2nd Best: 'programmers'\n";
    cout << "• Optimal: 'Looking forward' vs 2nd Best: 'Excited'\n";
    cout << "• Optimal: 'passionate competitor' vs 2nd Best: 'enthusiastic participant'\n";
    
    cout << "\n✅ Both solutions are valid and appropriate for the IEEEXtreme welcome message!\n";
}

int main() {
    test_solutions();
    return 0;
}
