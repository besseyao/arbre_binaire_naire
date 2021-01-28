#include <iostream>
#include "arbre.hh"

using namespace std;

int main()
{
/*
    noeud n0(0); //A
    noeud n1(1); //B
    noeud n2(2); //C
    noeud n3(3); //D
    noeud n4(4); //E
    noeud n5(5); //F
    noeud n6(6); //G
    noeud n7(7); //H
    noeud n8(8); //I
    noeud n9(9); //J
    noeud n10(10);  //K

    std::vector<noeud> vn;
    std::vector<noeud> vn1;
    vn.push_back(n0);
    vn.push_back(n1);
    vn.push_back(n2);
    vn.push_back(n3);
    vn.push_back(n4);
    vn.push_back(n5);
    vn.push_back(n6);
    vn.push_back(n7);
    vn.push_back(n8);
    vn.push_back(n9);
    vn.push_back(n10);

    arbreNaire arbn(vn);
    arbreBinaire arbb(vn1);
    arbn.naireToBinaire(arbb);
*/

    // arbreBinaire g;

    noeud n0(0);
    noeud n1(1);
    noeud n2(2);
    noeud n3(3);
    noeud n4(4);
    noeud n5(5);
    noeud n6(6);
    noeud n7(7);
    noeud n8(8);
    noeud n9(9);
    noeud n10(10);
    noeud n11(11);

    std::vector<noeud> vn;
    vn.push_back(n0);
    vn.push_back(n1);
    vn.push_back(n2);
    vn.push_back(n3);
    vn.push_back(n4);
    vn.push_back(n5);
    vn.push_back(n6);
    vn.push_back(n7);
    vn.push_back(n8);
    vn.push_back(n9);
    vn.push_back(n10);
    vn.push_back(n11);

    arbreBinaire arbb(vn);

    arbb.genereRelation();

    std::cout << "Arbre\n";

    std::cout << arbb.affichage();

    std::cout <<"\nAbre to list\n";

    std::vector<int> table;

    table = arbb.arbreToTable();

    for (auto const & e : table) {
        std::cout << e << " ";
    }

    return 0;
}
