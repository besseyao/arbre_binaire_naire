#include "relation.hh"

relation::relation(const noeud &noeudOrigine)
    :_noeudOrigine(noeudOrigine){}

noeud relation::noeudOrigine() const
{
    return _noeudOrigine;
}




relationBinaire::relationBinaire(const noeud &noeudOrigine)
    :relation (noeudOrigine){
    //mise en place de false par default pour pas de bug de la fonction affichage
    _filsGauche.estUnfils(false);
    _filsDroit.estUnfils(false);}

/*relationBinaire::relationBinaire(const noeud &noeudOrigine, const noeud &filsG, const noeud &filsD)
    :relation (noeudOrigine), _filsGauche(filsG), _filsDroit(filsD){}
*/

void relationBinaire::filsGauche(noeud &n)
{
    _filsGauche = n;
    _filsGauche.estUnfils(true);
}

void relationBinaire::filsDroit(noeud &n)
{
    _filsDroit = n ;
    _filsDroit.estUnfils(true);
}

noeud relationBinaire::filsGauche() const
{
    return _filsGauche;
}

noeud relationBinaire::filsDroit() const
{
    return  _filsDroit;
}



relationNaire::relationNaire(const noeud &noeudOrigine, const std::vector<noeud> &noeudsDest)
    :relation (noeudOrigine), _noeudsDest(noeudsDest){
    //ajout de ca
    for (auto r : _noeudsDest)
        r.estUnfils(true);
    }

std::vector<noeud> relationNaire::noeudsDest() const
{
    return _noeudsDest;
}














