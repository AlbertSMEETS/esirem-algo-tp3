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

void ShowSolution(struct Solution sol){
    if(sol.type = 0){
        printf("Il n'y a aucune solution.\n");
    }

    if(sol.type = 1){
        printf("La solution simple est x0 =%f.\n", sol.x0);
    }

    if(sol.type = 2){
        printf("Les deux solution sont %f et %f.\n", sol.x1, sol.x2);
    }
}

int main() {
    return 0;
}
