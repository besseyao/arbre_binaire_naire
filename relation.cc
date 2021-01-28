#include "relation.hh"

relation::relation(const noeud &noeudOrigine)
    :_noeudOrigine(noeudOrigine){}

noeud relation::noeudOrigine() const
{
    return _noeudOrigine;
}

relationNaire::relationNaire(const noeud &noeudOrigine, const std::vector<noeud> &noeudDest)
    :relation (noeudOrigine), _noeudDest(noeudDest){}

std::vector<noeud> relationNaire::noeudDest() const
{
    return _noeudDest;
}

relationBinaire::relationBinaire(const noeud &noeudOrigine)
    :relation (noeudOrigine){}

relationBinaire::relationBinaire(const noeud &noeudOrigine, const noeud &filsG, const noeud &filsD)
    :relation (noeudOrigine), _filsGauche(filsG), _filsDroit(filsD){}

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
