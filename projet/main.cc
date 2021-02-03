#include "arbre.hh"

using namespace std;

int main()
{

    noeud n0(0);
    noeud n1(1);
    noeud n2(2);
    noeud n3(3);
    noeud n4(4);
    noeud n5(5);
    noeud n6(6);


    arbreBinaire arbn;
    relationBinaire r1(n0);
    r1.setFilsGauche(n1);
    r1.setFilsDroit(n2);
    relationBinaire r2(n1);
    r2.setFilsDroit(n3);
    relationBinaire r3(n2);
    r3.setFilsGauche(n4);
    r3.setFilsDroit(n5);
    relationBinaire r4(n3);
    relationBinaire r5(n4);
    r5.setFilsDroit(n6);
    relationBinaire r6(n5);
    relationBinaire r7(n6);

    arbn.ajout(r1);
    arbn.ajout(r2);
    arbn.ajout(r3);
    arbn.ajout(r4);
    arbn.ajout(r5);
    arbn.ajout(r6);
    arbn.ajout(r7);

    std::cout << "affichage d'un arbre binaire : " << std::endl;
    arbn.affichage();



    arbreNaire arnr;

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

    arnr.ajout(rn1);
    arnr.ajout(rn2);
    arnr.ajout(rn3);

    std::cout << "affichage d'un arbre naire : " << std::endl;
    arnr.affichage();

    std::cout << "naireToBinaire :" << std::endl;
    arbreBinaire a1;
    arnr.naireToBinaire(a1);
    std::cout << "arbre binaire créé : " << std::endl;
    a1.affichage();




    arbreNaire an1;
    an1.binaireToNaire(a1);
    std::cout << "binaireTonaire :" << std::endl;
    std::cout << "arbre naire créé : " << std::endl;
    an1.affichage();
    std::cout << std::endl;


    std::vector<unsigned int> tab;
    for (unsigned int i(0);i<10;++i)
        tab.push_back(i);

    std::cout << "tabToBin :" << std::endl;
    std::cout << "tableau de base :" << std::endl;
    for(const auto &i : tab)
        std::cout << i << " ";
    std::cout<<std::endl;
    std::cout << "arbre binaire créé : " << std::endl;
    arbreBinaire a2;
    a2.tabToBin(tab);
    a2.affichage();

    std::cout << "binToTab :" << std::endl;
    std::cout << "arbre binaire de base :" << std::endl;
    arbn.affichage();
    std::vector<unsigned int> t;
    t = arbn.binToTab();
    std::cout << "tableau créé : " << std::endl;
    for( auto i : t)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "passage du tableu créé a un nouvel arbre binaire :" << std::endl;
    std::cout << "arbre binaire créé avec tabToBin :" << std::endl;

    arbreBinaire a3;
    a3.tabToBin(t);
    a3.affichage();
    return 0;
}
