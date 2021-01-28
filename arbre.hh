#pragma once

#include <sstream>
#include "noeud.hh"
#include "relation.hh"

class arbre {
    public:
        arbre() = default;
        arbre(std::vector<noeud> const & noeuds);
        std::vector<noeud>::iterator returnNoeud(unsigned int id);
        void ajoutNoeud(noeud const & n);
        std::vector<noeud> noeuds() const;
        void noeuds(std::vector<noeud> & vn);
        virtual void genereRelation() = 0 ;
        virtual std::string affichage() const = 0;
    private:
        std::vector<noeud> _noeuds;
};

class arbreBinaire : public arbre {

    public:
        arbreBinaire(std::vector<noeud> const & vn);
        const std::vector<relationBinaire> &relation() const;
        void addNoeuds(std::vector<noeud> & vn);
        void genereRelation() override ;
        std::string affichage() const override;

        std::vector<int> arbreToTable() const;
        void relation(relationBinaire const & r);

    private:
        std::vector<relationBinaire> _relation;
};


class arbreNaire : public arbre {
    public:
        arbreNaire(std::vector<noeud> const &vn);
        void naireToBinaire(arbreBinaire & arbb);
        void genereRelation() override;
        std::string affichage() const override;
    private:
        std::vector<relationNaire> _relation;
};
