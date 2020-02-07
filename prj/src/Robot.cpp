/*!
 * \file
 * \brief Zawiera definicje metod klasy Robot
 *
 * Zawiera definicje metod klasy Robot
 * wraz z ich opisem.
 */

#include "ObiektGraficzny.hh"
#include "Robot.hh"
#include "math.h"
#include "Macierz.hh"

/*!
 *
 * Przypisuje warto¶ci wspó³rzêdnych poszczególnym wierzcho³kom.
 *
 */
Robot::Robot()
{ 
  _PolozenieObiektu[0] = 0;
  _PolozenieObiektu[1] = 0;
  orientation = 0;
  Promien = ( 30 * sqrt(2));
  /*
  _TabLok[0][0] =   0;  _TabLok[0][1]=   0;
  _TabLok[1][0] =  30;  _TabLok[1][1]=   0;
  _TabLok[2][0] =   0;  _TabLok[2][1]= -30;
  _TabLok[3][0] = -30;  _TabLok[3][1]= -30;
  _TabLok[4][0] = -30;  _TabLok[4][1]=  30;
  _TabLok[5][0] =   0;  _TabLok[5][1]=  30;
  _TabLok[6][0] =  30;  _TabLok[6][1]=   0;

  for(unsigned int i=0; i<7; i++)
    _TabWie.push_back( _TabLok[i] );
  */

  _TabLok[0][0] = _PolozenieObiektu[0];    _TabLok[0][1]= _PolozenieObiektu[1];
  _TabLok[1][0] = _PolozenieObiektu[0]+30; _TabLok[1][1]= _PolozenieObiektu[1];
  _TabLok[2][0] = _PolozenieObiektu[0];    _TabLok[2][1]= _PolozenieObiektu[1]-30 ;
  _TabLok[3][0] = _PolozenieObiektu[0]-30; _TabLok[3][1]= _PolozenieObiektu[1]-30 ;
  _TabLok[4][0] = _PolozenieObiektu[0]-30; _TabLok[4][1]= _PolozenieObiektu[1]+30 ;
  _TabLok[5][0] = _PolozenieObiektu[0];    _TabLok[5][1]= _PolozenieObiektu[1]+30 ;
  _TabLok[6][0] = _PolozenieObiektu[0]+30; _TabLok[6][1]= _PolozenieObiektu[1];
  for(unsigned int i=0; i<7; i++)
    _TabWie.push_back( _TabLok[i] );

}


/*!
 *
 * Przypisuje warto¶ci wspó³rzêdnych poszczególnym wierzcho³kom.
 *
 * \param[in] Polozeniex - wartosc x dla poaczatkowego polozenia
 *            Polozeniey - wartosc y dla poaczatkowego polozenia
 */
Robot::Robot(double Polozeniex, double Polozeniey)
{ 
  _PolozenieObiektu[0] = Polozeniex;
  _PolozenieObiektu[1] = Polozeniey;
  orientation = 0;
  Promien = ( 30 * sqrt(2));

  _TabLok[0][0] = _PolozenieObiektu[0];       _TabLok[0][1]= _PolozenieObiektu[1];
  _TabLok[1][0] = _PolozenieObiektu[0]+30;    _TabLok[1][1]= _PolozenieObiektu[1];
  _TabLok[2][0] = _PolozenieObiektu[0];       _TabLok[2][1]= _PolozenieObiektu[1]-30 ;
  _TabLok[3][0] = _PolozenieObiektu[0]-30;    _TabLok[3][1]= _PolozenieObiektu[1]-30 ;
  _TabLok[4][0] = _PolozenieObiektu[0]-30;    _TabLok[4][1]= _PolozenieObiektu[1]+30 ;
  _TabLok[5][0] = _PolozenieObiektu[0];       _TabLok[5][1]= _PolozenieObiektu[1]+30 ;
  _TabLok[6][0] = _PolozenieObiektu[0]+30;    _TabLok[6][1]= _PolozenieObiektu[1];
  for(unsigned int i=0; i<7; i++)
    _TabWie.push_back( _TabLok[i] );
}


/*!
 *
 * Warto¶ci wierzcholkow robota wpisuje do wartosci globalnych
 * ObiektuGraficzengo.
 *
 */
void Robot::LokGlob(){   
  //Wektor2D Tab[7];
  //for(unsigned int i=0; i<7 ;++i){
  //  _TabWie[i] =  RotZ(orientation) *  _PolozenieObiektu;
  //}  
  //for(unsigned int i=0; i<7 ;++i){
  //std::cerr<< _TabLok[i] <<std::endl;
  //} 
  
   _TabWie[0][0] = _PolozenieObiektu[0];          _TabWie[0][1]= _PolozenieObiektu[1];
  _TabWie[1][0] = _PolozenieObiektu[0] + 30 ;    _TabWie[1][1]= _PolozenieObiektu[1]  ;
  _TabWie[2][0] = _PolozenieObiektu[0] ;         _TabWie[2][1]= _PolozenieObiektu[1]-30 ;
  _TabWie[3][0] = _PolozenieObiektu[0] -30 ;     _TabWie[3][1]= _PolozenieObiektu[1]-30 ;
  _TabWie[4][0] = _PolozenieObiektu[0] - 30 ;    _TabWie[4][1]= _PolozenieObiektu[1]+30 ;
  _TabWie[5][0] = _PolozenieObiektu[0] ;         _TabWie[5][1]= _PolozenieObiektu[1]+30 ;
  _TabWie[6][0] = _PolozenieObiektu[0] + 30;     _TabWie[6][1]= _PolozenieObiektu[1];
}


/*!
 * 
 * Oblicza macierz obrotu robota o zadany kat alpha
 * 
 * \param[in] alpha - kat dla ktorego liczona jest macierz obrotu
 *
 * \retval m - macierz obrotu alpha
 *
 */
Macierz Robot::RotZ(double alpha){
  alpha = (alpha * M_PI) / 180;
  Macierz m;
  m(0,0) = cos(alpha);
  m(0,1) = -sin(alpha);
  m(1,0) = sin(alpha);
  m(1,1) = cos(alpha);
  return m;
}


/*!
 * 
 * Obraca obiekt klasy Robot o zadany kat
 *
 * \param[in] angle - kat obrotu robota.
 *
 */
void Robot::Rotation(double angle){
  orientation  = orientation + angle;
  for(unsigned int i =0; i<7; ++i)
    _TabWie[i] = RotZ(this->orientation) * _TabLok[i] + _PolozenieObiektu; 
  //LokGlob();
}

/*!
 * 
 * Przesuwa obiekt kalsy Robot o zadany wektor
 *
 * \param[in] DW - dlugosc Wektora o ktory przesuwany jest obiekt
 *
 */
void Robot::Translation(double DW){
  Wektor2D Wector;
  Wector[0] = DW;
  Wector[1] = 0;
    
  _PolozenieObiektu = _PolozenieObiektu + (RotZ(this->orientation) * Wector); 

  //for(unsigned int i=0; i<7; ++i)
 //  _TabWie[i] =   (RotZ(this->orientation) *  _TabLok[i]) + _PolozenieObiektu;

  //  LokGlob();
  this->Rotation(0);
}



/*!
 * Sprawdzenie czy dojdzie do kolizji miedzy dwoma robotami
 * 
 * \param[in,out] Pozycja - pozycja obiektu z ktorym moze dojsc do kolizji 
 *                Promien - promien robota z kotrym moze dojsc do kolizji.
 * \retval true - gdy dojdzie do kolizji,
 * \retval false - w przypadku przeciwnym.
 */
bool Robot::Kolizja(const Wektor2D Pozycja, double Promien)const
{
  double Odl =sqrt( (Pozycja[0] - this->_PolozenieObiektu[0])*(Pozycja[0] - this->_PolozenieObiektu[0]) + (Pozycja[1] - this->_PolozenieObiektu[1])*(Pozycja[1] - this->_PolozenieObiektu[1]) );

  if((2*Promien) > Odl)
    {
      std::cerr<<"\n------------------ \n";
      std::cerr<<"Kolizja z robotem! \n";
      std::cerr<<"------------------ \n";
      return true;
    } 
  return false;  
}


