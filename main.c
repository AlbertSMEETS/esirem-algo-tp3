#include <stdio.h>

enum SolutionType {NONE = 0, ONE = 1, TWO = 2};

struct Solution {
    enum SolutionType type;
    double x0;
    double x1;
    double x2;
};

struct Equation{
    int a,b,c;
    struct Solution solution;

};

int main() {
    return 0;
}
