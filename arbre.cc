#include "arbre.hh"
#include <sstream>

arbre::arbre(std::vector<noeud> const &noeuds)
    :_noeuds(noeuds){}

std::vector<noeud>::iterator arbre::returnNoeud(unsigned int id)
{
    for (auto i (_noeuds.begin()); i!=_noeuds.end(); ++i)
        if ((*i).id() == id)
            return i;
    return _noeuds.end();
}

void arbre::ajoutNoeud(const noeud &n)
{
    _noeuds.push_back(n);
}

std::vector<noeud> arbre::noeuds() const
{
    return  _noeuds;
}

void arbre::noeuds(std::vector<noeud> &vn)
{
    _noeuds = vn;
}

arbreBinaire::arbreBinaire(const std::vector<noeud> &vn):arbre(vn){}


const std::vector<relationBinaire> &arbreBinaire::relation() const
{
    return _relation;
}

void arbreBinaire::addNoeuds(std::vector<noeud> &vn)
{
    noeuds(vn);
}

void arbreBinaire::genereRelation()
{
    unsigned int repere;

    for (auto i(0); i < noeuds().size(); ++i){

        auto n = returnNoeud(i);
        relationBinaire r(*n, NULL, NULL);

        repere = 2*i+1;

        if( repere <= noeuds().size()){

            r.filsGauche(*returnNoeud(repere));

            if(repere++ <= noeuds().size())
                r.filsDroit(*returnNoeud(repere));
        }

        _relation.push_back(r);
    }
}

std::string arbreBinaire::affichage() const
{
    std::ostringstream os;

    for(auto & r : relation()){
            os << r.noeudOrigine().id() << " -- ";
            if(r.filsGauche().estUnfils()){
                os << r.filsGauche().id() << " ";

                if(r.filsDroit().estUnfils()){
                    os << r.filsDroit().id();
                }
            }
            os << "\n";
    }

    return os.str();
}

std::vector<int> arbreBinaire::arbreToTable() const
{
    std::vector<int> table;
    for (size_t i(0); i < relation().size(); ++i) {
        if(i == 0)
            table.push_back(relation()[i].noeudOrigine().id());

        if(relation()[i].filsGauche().estUnfils())
            table.push_back(relation()[i].filsGauche().id());
        if(relation()[i].filsDroit().estUnfils())
            table.push_back(relation()[i].filsDroit().id());

    }

    return table;
}

void arbreBinaire::relation(const relationBinaire &r) {
    _relation.push_back(r);
}

arbreNaire::arbreNaire(const std::vector<noeud> &vn)
    :arbre(vn){}

void arbreNaire::naireToBinaire(arbreBinaire &arbb)
{
    std::vector<noeud> vn =  noeuds();
    if (vn.size() != 0){

        arbb.noeuds(vn); // Ajouter les noeuds a l'abre binaire
        for (auto & n: vn){ // A - B - C - D - E - F - G - H - I - J - K

            for (auto i(0); i < _relation.size(); ++i) {
                if(i == 0) {
                    relationBinaire r(arbb.noeuds()[0].id(), _relation[0].noeudDest()[0].id(), NULL);  // Connecter ce noeud a son premier fils gauche
                    arbb.relation(r); // A(B, _) | B(E, _) | C (F, _) | D(I, _) | E(_, _), F(_, _) | G(_, _) | H(_, _) | I(_, _)| J(K, _)
                    // tester si l'origine de la relation existe deja
                }else{
                    relationBinaire r2(_relation[i-1].noeudDest()[i-1].id(), NULL, _relation[i].noeudDest()[i].id());
                    arbb.relation(r2); //B(_, C) | C(F, D) | F(_ , G) | G(_, H) | I(_, J)
                    // tester si l'origine de la relation existe deja
                }
            }
        }
    }
}

void arbreNaire::genereRelation()
{
    std::cout << "GENERER RELATION";
}

std::string arbreNaire::affichage() const
{
    std::cout << "AFFICHAGE ARBRE BINAIRE";
}

// A(B, _)
// B(E,C)
// C(F, D)
// D(I, _)
// E(_,_)
// F(_ , G)
// G(_, H)
// I(_, J)
// J(K, _)
