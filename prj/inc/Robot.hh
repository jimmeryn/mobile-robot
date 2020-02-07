#pragma once 
/*!
 * \file 
 * \brief Definicja klasy Robot 
 *
 *  Plik zawiera definicjê klasy Robot
 */

#include <iostream>
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"
#include "SWektor.hh"
#include <vector>
#include  "Macierz.hh"

/*!
 * \brief Modeluje obiekt klasy Robot, który ma swoj± 
 *        reprezentacjê graficzn±
 *
 * Modeluje obiekt, który ma swoj± reprezentacjê graficzn±
 * w postaci ³amanej zamkniêtej w postaci
 * wieloboku. Ilo¶æ jej wierzcho³ków jest równa 6 (jeden powtarzajacy sie)
 */
class Robot : public ObiektGraficzny
{
  /*!
   * \brief Orientacja Robota
   *
   *  Zawiera orientacje robota wzglêdem, którego podane s±
   *  wspó³rzêdne punktów obrysu.
   */
public:
  double orientation;
  
  /*!
   * \brief Wierzcholki robota
   *
   *  Zawiera wspolzedne wierzcholkow robota.
   */
  //public:
  Wektor2D _TabLok[7];
  
  /*!
   * \brief Polozenie Obiektu
   *
   *  Zawiera polozenie robota na ukladzie wsp. wzgledem, którego podane s±
   *  wspó³rzêdne punktów obrysu.
   */
  Wektor2D _PolozenieObiektu;
  
  std::string Name;

  double Promien;
public:
  
  /*!
   * \brief Wiezcholki robota zapisuje do _TabWie z kalsy ObiektGraficzny
   *
   * Wierzcholki lokalne ustawia na globalne.
   */
  void LokGlob();
  
  
  /*!
   * \brief Macierz obrotu 
   */
  Macierz RotZ(double alpha);  
  
  
  /*!
   * \brief Inicjalizacja wspó³rzêdnych wierzcho³ków
   */
  //  void InicjalizujKsztalt() override;  
  Robot();
  
  /*!
   * \brief Inicjalizacja wspó³rzêdnych wierzcho³ków w okreslonym polozeniu
   */
  Robot(double, double);
  
  /*!
   * \brief Przesuwa robota o podana dlugosc wektora 
   */
  void Translation(double);
  
  /*!
   * \brief Obraca robota o zadany kat
   */
  void Rotation(double a);
  
  /*!
   * \brief Zwraca aktualne polozenie robota
   */
  Wektor2D Position()const{return _PolozenieObiektu;}
  
  /*!
   * Sprawdzenie czy dojdzie do kolizji miedzy dwoma robotami
   */
  bool Kolizja(const Wektor2D Pozycja, double Promien)const;
};
