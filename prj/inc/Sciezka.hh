#pragma once
/*!
 * \file 
 * \brief Definicja klasy Sciezka 
 *
 * Plik zawiera definicj� klasy Sciezka
 */

#include <iostream>
#include "Wektor2D.hh"
#include "ObiektGraficzny.hh"
#include <list>

/*!
 * \brief Modeluje obiekt, kt�ry ma swoj� reprezentacj� graficzn�
 *
 * Modeluje obiekt, kt�ry ma swoj� reprezentacj� graficzn�
 * w postaci �amanej otwartej. Ilo�� jej wierzcho�k�w nie jest jawnie
 * ograniczona. Jedynym ograniczeniem jest dost�pno�� pami�ci
 * komputera.
 */

class Sciezka:public ObiektGraficzny{
    std::list<Wektor2D> road;
public:

  /*!
   * \brief Inicjalizacja wsp�rz�dnych wierzcho�k�w
   */
  Sciezka();  

  /*!
   * \brief Inicjalizacja wsp�rz�dnych wierzcho�k�w w danym punkcie
   */
  Sciezka(double,double);  

  
  /*!
   * \brief Dodawanie kolejnych wsp�rz�dnych wierzcho�k�w
   */
  void dodaj_el(Wektor2D pkt);
};
