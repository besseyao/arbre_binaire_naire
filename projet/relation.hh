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


class relationBinaire : public relation {
    public:
        relationBinaire(noeud const & noeudOrigine);
        //supression du deuxieme constructeur
        //relationBinaire(noeud const & noeudOrigine, noeud const & filsG, noeud const & filsD);

        void filsGauche(noeud & n);
        void filsDroit(noeud & n);


        noeud filsGauche() const;
        noeud filsDroit() const;

    private:
        noeud _filsGauche;
        noeud _filsDroit;
};


class relationNaire : public relation {
    public:
        relationNaire(noeud const & noeudOrigine, std::vector<noeud> const & noeudsDest);
        std::vector<noeud> noeudsDest() const;
    private:
        std::vector<noeud> _noeudsDest;
};
