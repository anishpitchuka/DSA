#include <iostream>
#include <cmath>
using namespace std;

// Structure definition
struct Point {
    int X;
    int Y;
    struct Point *next;
};

int main() {
    // (a) Create three points A, B, C dynamically and initialize
    Point *A = new Point{0, 0, nullptr};
    Point *B = new Point{3, 4, nullptr};
    Point *C = new Point{6, 8, nullptr};

    // (b) BEGIN points to A
    Point *BEGIN = A;

    // (c) Modify pointers so that BEGIN → A → B → C
    A->next = B;
    B->next = C;
    C->next = nullptr;

    // (d) Print all three points using BEGIN
    cout << "Points:\n";
    Point *temp = BEGIN;
    while (temp != nullptr) {
        cout << "(" << temp->X << ", " << temp->Y << ")\n";
        temp = temp->next;
    }

    // (e) Compute all pairwise Euclidean distances and find closest pair
    auto distance = [](Point *p1, Point *p2) {
        return sqrt(pow(p1->X - p2->X, 2) + pow(p1->Y - p2->Y, 2));
    };

    double dAB = distance(A, B);
    double dAC = distance(A, C);
    double dBC = distance(B, C);

    cout << "\nPairwise distances:\n";
    cout << "A-B: " << dAB << "\n";
    cout << "A-C: " << dAC << "\n";
    cout << "B-C: " << dBC << "\n";

    // Identify closest pair
    double minDist = dAB;
    string closest = "A-B";

    if (dAC < minDist) {
        minDist = dAC;
        closest = "A-C";
    }
    if (dBC < minDist) {
        minDist = dBC;
        closest = "B-C";
    }

    cout << "\nClosest pair: " << closest << " with distance " << minDist << "\n";

    // Free memory
    delete A;
    delete B;
    delete C;

    return 0;
}
