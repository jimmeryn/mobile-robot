#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH

/*!
 * \file
 * \brief Definicja klasy ObiektGraficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny.
 */

#include <iostream>
#include "Wektor2D.hh"
#include "SWektor.hh"
#include <string>
#include <vector>
/*!
 * \brief Modeluje obiekt, który ma swoją reprezentację graficzną
 *
 * Modeluje obiekt, który ma swoją reprezentację graficzną
 * w postaci łamanej. Może ona być łamaną zamkniętą w postaci
 * wieloboku lub otwartą. Ilość jej wierzchołków nie jest jawnie
 * ograniczona. Jedynym ograniczeniem jest dostępność pamięci
 * komputera.
 */
class ObiektGraficzny {
protected:

  /*!
   * \brief Współrzędne pozycji obiektu
   *
   *  Zawiera współrzędne punktu względem, którego podane są
   *  współrzędne punktów obrysu obiektu.
   */
  Wektor2D   _PolozenieObiektu;


  /*!
   * \brief Tablica wierzchołków
   */
  std::vector<Wektor2D> _TabWie;

   /*!
   * \brief Nazwa obiektu graficznego
   */
  std::string Name;

public: 

  /*!
   * \brief Metoda sprawdzenie kolizji 
   */
  bool Kolizja(const Wektor2D Pozycja, double Promien)const{return false;}

  
  /*!
   * \brief Metoda zapisuje do pliku współrzędne wierzchołków
   */
   bool ZapiszDoPliku(const char* sNazwaPliku) const;

  
  /*!
   * \brief Metoda zapisuje do strumienia współrzędne wierzchołków
   */   
   bool ZapiszDoStrumienia(std::ostream& StrmWy) const;

  
  /*!
   * \brief Zmiania współrzędne położenia obiektu
   */
  void ZmienPolozenie(double x, double y);
  
};


#endif
