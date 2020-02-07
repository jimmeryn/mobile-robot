/*!
 * \file 
 * \brief Zawiera definicje metod klasy Sciezka 
 *
 * Zawiera definicje metod klasy Sciezka
 * wraz z ich opisem.
 * 
 */


#include "ObiektGraficzny.hh"
#include "Sciezka.hh"
#include "lacze_do_gnuplota.hh"
#include "Robot.hh"
using namespace std;

/*!
 *
 * Przypisuje warto¶æ 0 poczatkowemu wierzcholkowi sciezki.
 *
 */

Sciezka::Sciezka(){
  Wektor2D zero;
  zero[0] = 0;
  zero[1] = 0;
  road.push_back(zero);
}


/*!
 *
 * Przypisuje warto¶ci wspó³rzêdnych poszczególnym wierzcho³kom.
 *
 * \param[in] Polozeniex - wspolzedna x wierzcholka poczatkowego sciezki.
 *            Polozeniey - wspolzedna y wierzcholka poczatkowego sciezki.
 *
 */
Sciezka::Sciezka(double Polozeniex, double Polozeniey){
  Wektor2D zero;
  zero[0] = Polozeniex;
  zero[1] = Polozeniey;
  road.push_back(zero);
}


/*!
 *
 * Dodaje wierzcholek do sciezki.
 *
 * \param[in] pkt - wspolzedne wierzcholka dodawanedo do sciezki.
 *
 */
void Sciezka::dodaj_el(Wektor2D pkt){
  road.push_back(pkt);
  _TabWie.push_back(pkt);
}
