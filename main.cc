#include <iostream>
#include "arbre.hh"

using namespace std;

int main()
{

    noeud n0(0); //A
    noeud n1(1); //B
    noeud n2(2); //C
    noeud n3(3); //D
    noeud n4(4); //E
    noeud n5(5); //F
    noeud n6(6); //G


    std::vector<noeud> vn;
    vn.push_back(n0);
    vn.push_back(n1);
    vn.push_back(n2);
    vn.push_back(n3);
    vn.push_back(n4);
    vn.push_back(n5);
    vn.push_back(n6);

    /*
    arbreBinaire arbn(vn);
    relationBinaire r1(n0);
    r1.filsGauche(n1);
    r1.filsDroit(n2);
    relationBinaire r2(n1);
    r2.filsDroit(n3);
    relationBinaire r3(n2);
    r3.filsGauche(n4);
    r3.filsDroit(n5);
    relationBinaire r4(n4);
    r4.filsDroit(n6);

    arbn.relation(r1);
    arbn.relation(r2);
    arbn.relation(r3);
    arbn.relation(r4);

    arbn.affichage();
    */
    arbreNaire arnr(vn);

    std::vector<noeud> fils1;
    fils1.push_back(n1);
    fils1.push_back(n2);
    fils1.push_back(n3);
    relationNaire rn1 (n0,fils1);

    std::vector<noeud> fils2;
    fils2.push_back(n4);
    fils2.push_back(n5);
    relationNaire rn2 (n2,fils2);

    std::vector<noeud> fils3;
    fils3.push_back(n6);
    relationNaire rn3 (n3,fils3);

    arnr.relation(rn1);
    arnr.relation(rn2);
    arnr.relation(rn3);

    arnr.affichage();

    std::cout << "naireToBinaire :" << std::endl;
    arbreBinaire arbn(vn);
    arnr.naireToBinaire(arbn);
    arbn.affichage();
    return 0;
}
