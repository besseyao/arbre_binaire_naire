#pragma once
#include <string>
#include <iostream>

class noeud
{
    public:
        noeud() =default;
        noeud(const unsigned int &id);
        noeud(noeud const & n);

        unsigned int getId() const ;
        bool getEstUnfils() const ;
        void setEstUnfils(const bool &rep);

    private:
        unsigned int _id;
        bool _estUnFils;
        //  -- Prevue pour la suite

        /*
         *  std::string _nom;
         * int _nbreGainCummule;
         * int _nbreFoisTraverse;
         * bool _estOuvert;
         */
};
