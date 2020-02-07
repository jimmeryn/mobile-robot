#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "iostream"
#include "Wektor2D.hh"
#include "assert.h"

class Macierz{
  Wektor2D mac[2];
    
public:
  double operator()(unsigned int wie, unsigned int kol)const{
    assert(wie<2 && kol<2);
    return this->mac[wie][kol];
  }

   double& operator()(unsigned int wie, unsigned int kol){
    assert(wie<2 && kol<2);
    return this->mac[wie][kol];
  }


/*!
 *  Realizuje mno¿enie macierzy przez wektor.
 *  \param[in] Wec - wektor który jest mnozony prze macierz
 *  \return Wynik operacji mno¿enia przez wektor.
 */
  Wektor2D operator * (Wektor2D Wec)
  {
    Wektor2D  Wynik;
    
    Wynik[0] = mac[0][0]*Wec[0] + mac[0][1]*Wec[1];
    Wynik[1] = mac[1][0]*Wec[0] + mac[1][1]*Wec[1]; 
    return Wynik;  
  }
};


#endif
