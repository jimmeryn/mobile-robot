#pragma once 
/*!
 * \file 
 * \brief Definicja klasy Przeszkoda 
 *
 *  Plik zawiera definicjê klasy Przeszkoda
 */

#include <iostream>
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"
#include "SWektor.hh"


/*!
 * \brief Modeluje obiekt klasy Przeszkoda, który ma swoj± 
 *        reprezentacjê graficzn±
 *
 * Modeluje obiekt, który ma swoj± reprezentacjê graficzn±
 * w postaci prostokata.
 */
class Przeszkoda : public ObiektGraficzny
{
  /*!
   * \brief Wierzcholki przeszkody
   *
   *  Zawiera wspolzedne wierzcholkow przeszkody.
   *
   *  _Wie[0] - lewy dolny
   *  _Wie[1] - lewy gorny
   *  _Wie[2] - prawy gorny
   *  _Wie[3] - prawy dolny
   *  _Wie[5] - lewy dolny = _Wie[0]
   */
  Wektor2D _Wie[5];


  
public:
  
  /*!
   * \brief Inicjalizacja wspó³rzêdnych wierzcho³ków
   */
  Przeszkoda();
  
  
  /*!
   * \brief Inicjalizacja wspó³rzêdnych wierzcho³ków w okreslonym polozeniu
   */
  Przeszkoda(double, double, double, double, double, double, double, double);
  
  
  /*!
   * Sprawdzenie czy dojdzie do kolizji miedzy robotem a przeszkoda 
   */
  bool Kolizja(const Wektor2D Pozycja, double Promien)const;  
};

