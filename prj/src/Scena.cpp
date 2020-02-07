/*!
 * \file
 * \brief Zawiera definicje metod klasy Scena
 *
 *  Zawiera definicje metod klasy Scena
 *  wraz z ich opisem
 */

#include "Scena.hh"
#include <iostream>
#include "Przeszkoda.hh"
#include <unistd.h>

/*!
 * Inicjalisuje obiekty na scenie
 */
Scena::Scena(){
  this->Zapis();
  this->Rysowanie();
}



/*!
 * Zapisuje obiekty sceny do plikow 
 */
void Scena::Zapis(){

  Lacze.DodajNazwePliku("figury/robot.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("figury/sciezka.dat",PzG::RR_Ciagly,2);

  Lacze.DodajNazwePliku("figury/robot2.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("figury/sciezka2.dat",PzG::RR_Ciagly,2);

  Lacze.DodajNazwePliku("figury/robot3.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("figury/sciezka3.dat",PzG::RR_Ciagly,2);
 
  Lacze.DodajNazwePliku("figury/przeszkoda1.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("figury/przeszkoda2.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("figury/przeszkoda3.dat",PzG::RR_Ciagly,2);
 
  Lacze.ZmienTrybRys(PzG::TR_2D);
}


/*!
 * Rysuje obiekty sceny za pomoca Lacza do GNUplota 
 */
void Scena::Rysowanie(){
  this->Lacze.Rysuj();
}


/*!
 * Ruch wskazanym robotem
 *
 * \parami[in] odl - odleglosc na jaka przesowamy robota
 * \parami[in] nr - nr robota dla ktorego wykonujemu operacje 
 */
void Scena::RuchR(double odl,unsigned int nr,unsigned int speed){
  
  bool spr = false;
  
  for(; odl>0 ; odl-=speed)
    {
      ListaRob[nr].Translation(speed);
      //ListaOb[nr+1]->dodaj_el(ListaRob[nr].Position());
      Wektor2D poz = ListaRob[nr].Position();
      this->Rysowanie();
      for(const std::shared_ptr<ObiektGraficzny>&WOb:ListaOb){
	if( WOb->Kolizja(poz,ListaRob[nr].Promien) == true){
	  std::cerr<<"Kolizja wykryta"<<std::endl;
	  spr = true;
	}
      }
      if(spr == true){break;}
    }
}


/*!
 * Rotacja wskazanego robota
 *
 * \parami[in] angl - kat o jaki bracamy robota
 * \parami[in] nr - nr robota dla ktorego wykonujemu operacje
 */
void Scena::RotR(double angl,unsigned int nr, unsigned int speed){
  ListaRob[nr].Rotation(speed);
  usleep(200000);
}


/*!
 * Sprawdzenie czy doszlo do kolizji
 *
 * \parami[in] nr - numer robota dla ktorego sprawdzamy kolizje
 */
bool Scena::CzyKol( unsigned int nr){
  double promien = ListaRob[nr].Promien;
  Wektor2D poz = ListaRob[nr].Position();
  for(unsigned int i=0;i<ListaOb.size();++i){
    if(ListaOb[i]->Kolizja(poz,promien) == true){return true;}
  }
  return false;
}
