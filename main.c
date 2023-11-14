#include <stdio.h>
#include <math.h>

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
    if(sol.type == 0){
        printf("Il n'y a aucune solution.\n");
    }

    if(sol.type == 1){
        printf("La solution simple est x0 =%f.\n", sol.x0);
    }

    if(sol.type == 2){
        printf("Les deux solution sont %f et %f.\n", sol.x1, sol.x2);
    }
}

void test(){
    struct Solution sol1,sol2,sol3,sol4,sol5,sol6;
    int i = 0;

    struct Solution solution[i];
    solution[0]=sol1;
    solution[1]=sol2;
    solution[2]=sol3;
    solution[3]=sol4;
    solution[4]=sol5;
    solution[5]=sol6;

    for(i=0;i<=sizeof(solution);i++){
        ShowSolution(solution[i]);
    }
}

struct Solution resolveOne(double a, double b){
    struct Solution sol;
    sol.type = 1;
    sol.x0= -(b/a);
    sol.x1 = 0;
    sol.x2 = 0;
    return sol;
}

struct Solution resolveTwo(double a, double b, double c){
    struct Solution sol;
    if(b*b-(4*a*c)>0){
        sol.type = 2;
        sol.x0 = 0;
        sol.x1 = (-b-sqrt(b*b-(4*a*c)))/2*a;
        sol.x2 = (-b+sqrt(b*b-(4*a*c)))/2*a;
    }
    if(b*b-(4*a*c)==0){
        sol.type = 1;
        sol.x0 = -b/(2*a);
        sol.x1 = 0;
        sol.x2 = 0;
    }
    return sol;
}

int main() {
    return 0;
}
