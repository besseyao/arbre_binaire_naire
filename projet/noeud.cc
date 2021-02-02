#include "noeud.hh"

noeud::noeud(unsigned int id)
    :_id(id), _estUnFils(false){}

noeud::noeud(const noeud &n)
    :_id(n._id), _estUnFils(n._estUnFils){}

unsigned int noeud::id(){
    return _id;
}

void noeud::estUnfils(bool rep)
{
    _estUnFils = rep;
}

bool noeud::estUnfils() const
{
    return _estUnFils;
}
