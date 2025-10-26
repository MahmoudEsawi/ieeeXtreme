#include <iostream>
#include <vector>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

int intersectingRectangles(vector<Rectangle>& rectangles) {
    int cnt = 0;
    int n = rectangles.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int xOverlap = min(rectangles[i].x2, rectangles[j].x2) - max(rectangles[i].x1, rectangles[j].x1);
            int yOverlap = min(rectangles[i].y2, rectangles[j].y2) - max(rectangles[i].y1, rectangles[j].y1);
            
            if (xOverlap > 0 && yOverlap > 0) {
                cnt++;
            }
        }
    }
    
    return cnt;
}
