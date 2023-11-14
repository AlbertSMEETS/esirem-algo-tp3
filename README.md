1.2)
DEBUT
PARAM solution sol
SI sol.type == 0 ALORS
AFFICHER (" il n'y a aucune solution")
SINON SI sol.type == 1 ALORS
AFFICHER ( x0 )
SINON SI sol.type == 2 ALORS
AFFICHER ( x1,x2 )
FIN

1.4)
DEBUT resolveOne
PARAM ENTIER a,b
VARIABLE Solution sol
sol.type ← 1
sol.x0 ← -(b / a)
sol.x1 ← 0
sol.x2 ← 0
RETOURNER sol
FIN

1.5)
DÉBUT resolveTwo
PARAM ENTIER a, b, c
VARIABLE Solution sol
SI b*b - (4*a*c) > 0 ALORS
sol.type ← 2
sol.x0 ← 0
sol.x1 ← (-b - sqrt(b*b - (4*a*c))) / (2 * a)
sol.x2 ← (-b + sqrt(b*b - (4*a*c))) / (2 * a)
FIN SI
SI b*b - (4*a*c) == 0 ALORS
sol.type ← 1
sol.x0 ← -b / (2 * a)
sol.x1 ← 0
sol.x2 ← 0
FIN SI
RETOURNER sol
FIN

1.6)
DÉBUT resolve(a, b, c)
PARAM ENIER a, b, c
SI a == 0 ALORS
RETOURNER resolveOne(b, c)
SINON
RETOURNER resolveTwo(a, b, c)
FIN SI
FIN

1.7)
DÉBUT decode
PARAM CHAR eq[]
VARIABLE Solution sol
VARIABLES ENTIER a = 0, b = 0, c = 0, a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, c0 = 0
VARIABLES ENTIER i = 0, signA = 0, signB = 0, signC = 0

    SI eq[0] == '-' ALORS
        signA ← 1
        TANT QUE eq[i+1] != 'x' FAIRE
            eq[i] ← a1
            a2 ← a2 * 10 + a1
            i ← i + 1
        FIN TANT QUE
    SINON
        TANT QUE eq[i] != 'x' FAIRE
            eq[i] ← a1
            a2 ← a2 * 10 + a1
            i ← i + 1
        FIN TANT QUE
    FIN SI

    SI eq[i+1] == '`' ALORS
        SI eq[i+2] == '-' ALORS
            signB ← 1
            TANT QUE eq[i+3] != 'x' FAIRE
                eq[i] ← b1
                b2 ← b2 * 10 + b1
                i ← i + 1
            FIN TANT QUE
        SINON SI eq[i+2] == '+' ALORS
            TANT QUE eq[i+3] != 'x' FAIRE
                eq[i] ← b1
                b2 ← b2 * 10 + b1
                i ← i + 1
            FIN TANT QUE
        FIN SI

        SI eq[i+1] == '-' ALORS
            signC ← 1
            TANT QUE eq[i+3] != 'x' FAIRE
                eq[i] ← c1
                c2 ← c2 * 10 + c1
                i ← i + 1
            FIN TANT QUE
        SINON SI eq[i+1] == '+' ALORS
            TANT QUE eq[i+2] != 'x' FAIRE
                eq[i] ← c1
                c2 ← c2 * 10 + c1
                i ← i + 1
            FIN TANT QUE
        FIN SI
    FIN SI

    SI eq[i+1] == '-' ALORS
        signB ← 1
        TANT QUE eq[i+2] != 'x' FAIRE
            eq[i] ← b1
            b2 ← b2 * 10 + b1
            i ← i + 1
            c0 ← 1
        FIN TANT QUE
    SINON SI eq[i+1] == '+' ALORS
        TANT QUE eq[i+2] != 'x' FAIRE
            eq[i] ← b1
            b2 ← b2 * 10 + b1
            i ← i + 1
            c0 ← 1
        FIN TANT QUE
    FIN SI

    SI c0 == 1 ALORS
        SI signA == 1 ALORS
            a ← -a2
        SINON
            a ← a2
        FIN SI

        SI signB == 1 ALORS
            b ← -b2
        SINON
            b ← b2
        FIN SI
    SINON
        SI signA == 1 ALORS
            a ← -a2
        SINON
            a ← a2
        FIN SI

        SI signB == 1 ALORS
            b ← -b2
        SINON
            b ← b2
        FIN SI

        SI signC == 1 ALORS
            c ← -c2
        SINON
            c ← c2
        FIN SI
    FIN SI

    sol ← resolve(a, b, c)
    RETOURNER sol
FIN


