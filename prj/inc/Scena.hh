#pragma once
/*!
 * \file
 * \brief Definicja klasy Scena
 *
 * Plik zawiera definicje klasy Scena 
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>

#include "Wektor2D.hh"
#include "lacze_do_gnuplota.hh"
#include "ObiektGraficzny.hh"
#include "Robot.hh"
#include "Sciezka.hh"

/*!
 * \brief Modeluje ca³o¶æ sceny widzianej przez urzytkownika
 *
 * Modeluje scene, która ma swoj± reprezentacje graficzn±
 * w postaci obiektow graficznych. Znajduja siê tam 
 * obiekty kals Robot, Sciezka, Przeszkoda.
 */

class Scena{
public:
  /*!
   * \brief Lista wskaznikow na obiekty klasy ObiektGraficzny
   * 
   * Lista wskaznikow na obiekty dzidziczace z klasy ObiektGraficzny.
   * Sa to wiec wszystkie obiekty klas: Robot, Sciezka, Przeszkoda.
   */
  std::vector<std::shared_ptr<ObiektGraficzny>> ListaOb;

  
  /*!
   * \brief Lista wskaznikow na obiekty klasy robot
   * 
   * Lista wskaznikow na obiekty klasy Robot.
   */
  std::vector<Robot> ListaRob;

  
  /*!
   * \brief ³±cze do GNUPlota
   *
   * £±cze do GNUPlota
   */
  PzG::LaczeDoGNUPlota Lacze;
  
public:
  /*!
   * \brief Konstrukcja obiektów sceny
   */
   Scena();
  
  

  /*!
   * \brief Metoda zapisuj±ca wszystkie pliki
   */
  void Zapis();

  
  /*!
   * \brief Rysowanie z zapisanych plikow do lacza GNUplota
   */
  void Rysowanie();


  /*!
   * \brief Ruch Robota
   */
  void RuchR(double,unsigned int,unsigned int);  


  /*!
   * \brief Rotacja Robota
   */
  void RotR(double,unsigned int,unsigned int);  

  /*!
   * \brief Sprawdzenie czy doszlo do kolizji
   */
  bool CzyKol(unsigned int);
};
