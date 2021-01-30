#pragma once
#include "noeud.hh"
#include <vector>

class relation {
    public:
        relation() = default;
        relation(noeud const & noeudOrigine);
        noeud noeudOrigine() const;
    private:
        noeud _noeudOrigine;
};

class relationNaire : public relation {
    public:
        relationNaire(noeud const & noeudOrigine, std::vector<noeud> const & noeudDest);
        std::vector<noeud> noeudDest() const;
    private:
        std::vector<noeud> _noeudDest;
};

class relationBinaire : public relation {
    public:
        relationBinaire(noeud const & noeudOrigine);
        relationBinaire(noeud const & noeudOrigine, noeud const & filsG, noeud const & filsD);

        void filsGauche(noeud & n);
        void filsDroit(noeud & n);


        noeud filsGauche() const;
        noeud filsDroit() const;

    private:
        noeud _filsGauche;
        noeud _filsDroit;
};
