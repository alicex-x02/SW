#include <iostream>
#include <cmath>
using namespace std;

struct point {
    int x;
    int y;
};

double squaredDistance(point p1, point p2) {
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

void triangle_2() {
    double ab = 0;
    double bc = 0;
    double ca = 0;
    point a, b, c;

    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    ab = squaredDistance(a, b);
    bc = squaredDistance(b, c);
    ca = squaredDistance(c, a);

    if ((sqrt(ab) + sqrt(bc) <= sqrt(ca)) || (sqrt(ab) + sqrt(ca) <= sqrt(bc)) || (sqrt(bc) + sqrt(ca) <= sqrt(ab))) {
        cout << 0 << endl;
        return;
    }

    if ((ab + ca == bc) || (ab + bc == ca) || (bc + ca == ab)) {
        cout << 1 << endl;
        return;
    }


    if ((ab + ca < bc) || (ab + bc < ca) || (bc + ca < ab)) {
        cout << 2 << endl;
        return;
    }

    cout << 3 << endl;
}

int main() {
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        triangle_2();
    }
    return 0;
}