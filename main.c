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

struct Solution resolveOne(int a, int b){
    struct Solution sol;
    sol.type = 1;
    sol.x0= -(b/a);
    sol.x1 = 0;
    sol.x2 = 0;
    return sol;
}

struct Solution resolveTwo(int a, int b, int c){
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

struct Solution resolve(int a, int b, int c) {
    if (a == 0) {
        return resolveOne(b, c);
    } else {
        return resolveTwo(a, b, c);
    }
}

struct Solution decode(char eq[]){
    int a = 0,b = 0,c = 0,a1 = 0,a2 = 0,b1 = 0,b2 = 0,c1 = 0,c2 = 0, c0=0;
    int i = 0;
    int signA = 0, signB = 0, signC = 0;
    if(eq[0]=='-'){ //Premier boucle permettant de stocker quelque pars le premier - puis de sotcker la valeur de a
        signA = 1;
        while(eq[i+1]!='x') {
            eq[i] = a1;
            a2 = a2 * 10 + a1;
            i += 1;
        }
    }
    else {
        while(eq[i]!='x'){ // Premier boucle permettant de stocker quelque pars la valeurs de 1 sans le moins
            eq[i]=a1;
            a2=a2*10+a1;
            i+=1;
        }
    }
    if(eq[i+1] == '`'){
        if(eq[i+2]=='-'){
            signB = 1;
            while(eq[i+3]!='x') {
                eq[i] = b1;
                b2 = b2 * 10 + b1;
                i += 1;
            }
        }
        if(eq[i+2]=='+'){
            while(eq[i+3]!='x') {
                eq[i] = b1;
                b2 = b2 * 10 + b1;
                i += 1;
            }
        }
        if(eq[i+1]=='-'){
            signC = 1;
            while(eq[i+3]!='x') {
                eq[i] = c1;
                c2 = c2 * 10 + c1;
                i += 1;
            }
        }
        if(eq[i+1]=='+'){
            while(eq[i+2]!='x') {
                eq[i] = c1;
                c2 = c2 * 10 + c1;
                i += 1;
            }
        }
    }
    if(eq[i+1]=='-'){
        signB = 1;
        while(eq[i+2]!='x') {
            eq[i] = b1;
            b2 = b2 * 10 + b1;
            i += 1;
            c0=1;
        }
    }
    if(eq[i+1]=='+'){
        while(eq[i+2]!='x') {
            eq[i] = b1;
            b2 = b2 * 10 + b1;
            i += 1;
            c0=1;
        }
    }
    if(c0==1){
        if(signA==1){
            a = -a2;
        }
        else{
            a = a2;
        }
        if(signB==1){
            b = -b2;
        }
        else{
            b = b2;
        }
    }
    else{
        if(signB==1){
            a = -a2;
        }
        else{
            a = a2;
        }
        if(signB==1){
            b = -b2;
        }
        else{
            b = b2;
        }
        if(signC==1){
            c = -c2;
        }
        else{
            c = c2;
        }
    }
}


int main(){
    return 0;
}
