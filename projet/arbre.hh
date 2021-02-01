#pragma once

#include <sstream>
#include <algorithm>
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
        virtual void affichage() const = 0;
    private:
        std::vector<noeud> _noeuds;
};

class arbreBinaire : public arbre {

    public:
        arbreBinaire(std::vector<noeud> const & vn);
        const std::vector<relationBinaire> &relation() const;
        void addNoeuds(std::vector<noeud> & vn);
        void genereRelation() override ;
        void affichage() const override;
        // ajout de methode set relation fils gauche
        void setRelationFG (noeud &origine,noeud &fg,bool &trouve);
        // ajout de methode set relation fils droit
        void setRelationFD (noeud &origine,noeud &fd,bool &trouve);
        std::vector<int> arbreToTable() const;
        void relation(relationBinaire const & r);

    private:
        std::vector<relationBinaire> _relation;
};


class arbreNaire : public arbre {
    public:
        arbreNaire(std::vector<noeud> const &vn);
        //methode modifié
        void naireToBinaire(arbreBinaire & arbb);
        void genereRelation() override;
        void affichage() const override;
        //ajout de methode relation
        void relation(relationNaire const & r);
    private:
        std::vector<relationNaire> _relation;
};
