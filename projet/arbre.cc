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

void arbreBinaire::setRelationFG(noeud &origine, noeud &fg, bool &trouve){
    auto i (_relation.begin());
    while ( i!=_relation.end() && !trouve){
        if ((*i).noeudOrigine().id()== origine.id()){
            (*i).filsGauche(fg);
            trouve=true;
        }
        ++i;
    }
}

void arbreBinaire::setRelationFD(noeud &origine, noeud &fd, bool &trouve){
    auto i (_relation.begin());
    while ( i!=_relation.end() && !trouve){
        if ((*i).noeudOrigine().id()== origine.id()){
            (*i).filsDroit(fd);
            trouve=true;
        }
        ++i;
    }
}

void arbreBinaire::genereRelation()
{
    unsigned int repere;

    for (auto i(0); i < noeuds().size(); ++i){

        auto n = returnNoeud(i);
        relationBinaire r(*n);

        repere = 2*i+1;

        if( repere <= noeuds().size()){

            r.filsGauche(*returnNoeud(repere));

            if(repere++ <= noeuds().size())
                r.filsDroit(*returnNoeud(repere));
        }

        _relation.push_back(r);
    }
}


void arbreBinaire::affichage() const
{
    //suppression de os et mise de std::cout pour le moment
    for(auto & r : _relation){
            //breve modif de l'affichage
            std::cout << r.noeudOrigine().id() << " -- ";
            if(r.filsGauche().estUnfils())
                std::cout << r.filsGauche().id() << " ";
            else std::cout << "x ";
            if(r.filsDroit().estUnfils())
                    std::cout << r.filsDroit().id();
            else std::cout << "x ";
            std::cout << "\n";
    }
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


//ajout de cette methode
void arbreNaire::relation (const relationNaire &r){
    _relation.push_back(r);
}

arbreNaire::arbreNaire(const std::vector<noeud> &vn)
    :arbre(vn){}

//methode modifié elle marche bien
void arbreNaire::naireToBinaire(arbreBinaire &arbb)
{
    std::vector<noeud> vn =  noeuds();
    if (vn.size() != 0){

        arbb.noeuds(vn); // Ajouter les noeuds a l'abre binaire
        for (auto i(0); i < _relation.size(); ++i){

            for (auto j(0); j < _relation[i].noeudsDest().size(); ++j) {
                if(i == 0 && j == 0) {
                    noeud origin = _relation[i].noeudOrigine();
                    noeud fg = _relation[0].noeudsDest()[0];
                    bool trouve = false;
                    arbb.setRelationFG(origin,fg,trouve);
                    if (!trouve){
                        relationBinaire r(origin);
                        r.filsGauche(fg);// Connecter ce noeud a son premier fils gauche
                        arbb.relation(r);
                    }
                }else {
                    if (j==0){
                        noeud origin = _relation[i].noeudOrigine();
                        noeud fg = _relation[i].noeudsDest()[j];
                        bool trouve = false;
                        arbb.setRelationFG(origin,fg,trouve);
                        if (!trouve){
                            relationBinaire r2(_relation[i].noeudOrigine());
                            r2.filsGauche(_relation[i].noeudsDest()[j]);
                            arbb.relation(r2);
                        }
                    }else {
                        noeud origin = _relation[i].noeudsDest()[j-1];
                        noeud fd = _relation[i].noeudsDest()[j];
                        bool trouve = false;
                        arbb.setRelationFD(origin,fd,trouve);
                        if (!trouve){
                            relationBinaire r3(_relation[i].noeudsDest()[j-1]);
                            r3.filsDroit(_relation[i].noeudsDest()[j]);
                            arbb.relation(r3);
                        }
                    }
                }
            }
        }
    }
}


void arbreNaire::genereRelation()
{
    std::cout << "GENERER RELATION";
}


//ajout de l'affichage
void arbreNaire::affichage() const
{
    for(auto & r : _relation){
            std::cout << r.noeudOrigine().id() << " -- ";
            for (auto & n : r.noeudsDest()){
                std::cout << n.id() << " ";
            }
            std::cout << "\n";
    }
}


