#pragma once
/*!
 * \file 
 * \brief Definicja klasy Sciezka 
 *
 * Plik zawiera definicjê klasy Sciezka
 */

#include <iostream>
#include "Wektor2D.hh"
#include "ObiektGraficzny.hh"
#include <list>

/*!
 * \brief Modeluje obiekt, który ma swoj± reprezentacjê graficzn±
 *
 * Modeluje obiekt, który ma swoj± reprezentacjê graficzn±
 * w postaci ³amanej otwartej. Ilo¶æ jej wierzcho³ków nie jest jawnie
 * ograniczona. Jedynym ograniczeniem jest dostêpno¶æ pamiêci
 * komputera.
 */

class Sciezka:public ObiektGraficzny{
    std::list<Wektor2D> road;
public:

  /*!
   * \brief Inicjalizacja wspó³rzêdnych wierzcho³ków
   */
  Sciezka();  

  /*!
   * \brief Inicjalizacja wspó³rzêdnych wierzcho³ków w danym punkcie
   */
  Sciezka(double,double);  

  
  /*!
   * \brief Dodawanie kolejnych wspó³rzêdnych wierzcho³ków
   */
  void dodaj_el(Wektor2D pkt);
};
