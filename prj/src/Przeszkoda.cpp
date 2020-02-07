/*!
 * \file
 * \brief Zawiera definicje metod klasy Przeszkoda
 *
 * Zawiera definicje metod klasy Przeszkoda
 * wraz z ich opisem.
 */

#include "ObiektGraficzny.hh"
#include "Przeszkoda.hh"

/*!
 *
 * Przypisuje warto¶ci wspó³rzêdnych poszczególnym wierzcho³kom.
 *
 */
Przeszkoda::Przeszkoda(){

}

/*!
 *
 * Przypisuje warto¶ci wspó³rzêdnych poszczególnym wierzcho³kom.
 *
 * \param[in] a - wspolzedne wierzcholka przeszkody
 *            b - wspolzedne wierzcholka przeszkody
 *            c - wspolzedne wierzcholka przeszkody
 *            d - wspolzedne wierzcholka przeszkody
 */
Przeszkoda::Przeszkoda(double a1,double a2,double b1,double b2,double c1,double c2,double d1,double d2){
  _Wie[0][0] = a1;
  _Wie[0][1] = a2;
  _Wie[1][0] = b1;
  _Wie[1][1] = b2;
  _Wie[2][0] = c1;
  _Wie[2][1] = c2;
  _Wie[3][0] = d1;
  _Wie[3][1] = d2;
  _Wie[4][0] = a1;
  _Wie[4][1] = a2;
  
  for(unsigned int i=0; i<5; ++i)
    _TabWie.push_back(_Wie[i]);
}

/*!
 * Sprawdzenie czy dojdzie do kolizji miedzy robotem a przeszkoda
 * .
 * \param[in,out] Pozycja - pozycja robota z ktorym moze dojsc do kolizji 
 *                Promien - promien robota z kotrym moze dojsc do kolizji.
 * \retval true - gdy dojdzie do kolizji,
 * \retval false - w przypadku przeciwnym.
 */
bool Przeszkoda::Kolizja(const Wektor2D Pozycja, double Promien)const
{
  if(((Pozycja[0])>(_Wie[0][0]-Promien)) && ((Pozycja[0])<(_Wie[2][0]+Promien)) && ((Pozycja[1])>(_Wie[0][1]-Promien)) && ((Pozycja[1])< (_Wie[2][1] +Promien)))
    {
      std::cerr<<"\n--------------------- \n";
      std::cerr<<"Kolizja z przeszkoda! \n";
      std::cerr<<"--------------------- \n";
      return true;
    }
  return false;  
}
