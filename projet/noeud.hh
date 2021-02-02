#pragma once

#include <string>
#include <iostream>

class noeud
{
    public:
        noeud() =default;
        noeud(unsigned int id);
        noeud(noeud const & n);

        unsigned int id();

        void estUnfils(bool rep);

        bool estUnfils() const ;

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
