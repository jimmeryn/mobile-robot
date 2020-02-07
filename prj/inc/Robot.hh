#pragma once 
/*!
 * \file 
 * \brief Definicja klasy Robot 
 *
 *  Plik zawiera definicj� klasy Robot
 */

#include <iostream>
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"
#include "SWektor.hh"
#include <vector>
#include  "Macierz.hh"

/*!
 * \brief Modeluje obiekt klasy Robot, kt�ry ma swoj� 
 *        reprezentacj� graficzn�
 *
 * Modeluje obiekt, kt�ry ma swoj� reprezentacj� graficzn�
 * w postaci �amanej zamkni�tej w postaci
 * wieloboku. Ilo�� jej wierzcho�k�w jest r�wna 6 (jeden powtarzajacy sie)
 */
class Robot : public ObiektGraficzny
{
  /*!
   * \brief Orientacja Robota
   *
   *  Zawiera orientacje robota wzgl�dem, kt�rego podane s�
   *  wsp�rz�dne punkt�w obrysu.
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
   *  Zawiera polozenie robota na ukladzie wsp. wzgledem, kt�rego podane s�
   *  wsp�rz�dne punkt�w obrysu.
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
   * \brief Inicjalizacja wsp�rz�dnych wierzcho�k�w
   */
  //  void InicjalizujKsztalt() override;  
  Robot();
  
  /*!
   * \brief Inicjalizacja wsp�rz�dnych wierzcho�k�w w okreslonym polozeniu
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
