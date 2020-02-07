/*!
 * \file
 * \brief Zawiera wywołanie funkcji main
 *
 * Główny moduł programu wraz z wywołaniem funkcji main.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "string.h"

#include "lacze_do_gnuplota.hh"
#include "ObiektGraficzny.hh"
#include "Robot.hh"
#include "Sciezka.hh"
#include "Scena.hh"
#include "Przeszkoda.hh"
#include <unistd.h>
#define SPEED 10

using namespace std;


int main()
{
  unsigned int NRrob=0;
  Robot R1;
  Robot R2(100,100);
  //R2.Rotation(180);
    
  Robot R3(-200,-200);
  //R3.Rotation(45);
  
  Sciezka s;
  s.dodaj_el(R1.Position());
  Sciezka s2;
  s2.dodaj_el(R2.Position());
  Sciezka s3;
  s3.dodaj_el(R3.Position());
  
  Przeszkoda p1(-100,-100, -100,-50, 0,-50, 0,-100);
  Przeszkoda p2(-300,50, -300,200, -150,200, -150,50);
  Przeszkoda p3(200,-200, 200,10, 240,10, 240,-200);

  std::shared_ptr<ObiektGraficzny> Wsk_R1 = make_shared<ObiektGraficzny>(R1);
  std::shared_ptr<ObiektGraficzny> Wsk_R2 = make_shared<ObiektGraficzny>(R2);
  std::shared_ptr<ObiektGraficzny> Wsk_R3 = make_shared<ObiektGraficzny>(R3);
  std::shared_ptr<ObiektGraficzny> Wsk_P1 = make_shared<ObiektGraficzny>(p1);
  std::shared_ptr<ObiektGraficzny> Wsk_P2 = make_shared<ObiektGraficzny>(p2);
  std::shared_ptr<ObiektGraficzny> Wsk_P3 = make_shared<ObiektGraficzny>(p3);
  std::shared_ptr<ObiektGraficzny> Wsk_s1 = make_shared<ObiektGraficzny>(s);
  std::shared_ptr<ObiektGraficzny> Wsk_s2 = make_shared<ObiektGraficzny>(s2);
  std::shared_ptr<ObiektGraficzny> Wsk_s3 = make_shared<ObiektGraficzny>(s3);
  
  Scena I;

  I.ListaRob.push_back(R1);
  I.ListaRob.push_back(R2);
  I.ListaRob.push_back(R3);
  
  I.ListaOb.push_back(Wsk_R1);
  I.ListaOb.push_back(Wsk_R2);  
  I.ListaOb.push_back(Wsk_R3);
  
  I.ListaOb.push_back(Wsk_P1);
  I.ListaOb.push_back(Wsk_P2);
  I.ListaOb.push_back(Wsk_P3);
  
  I.Zapis();

  if (!s.ZapiszDoPliku("figury/sciezka.dat")) return 1;
  if (!R1.ZapiszDoPliku("figury/robot.dat")) return 1;

  if (!s2.ZapiszDoPliku("figury/sciezka2.dat")) return 1; 
  if (!R2.ZapiszDoPliku("figury/robot2.dat")) return 1;

  if (!s3.ZapiszDoPliku("figury/sciezka3.dat")) return 1; 
  if (!R3.ZapiszDoPliku("figury/robot3.dat")) return 1;

  if (!p1.ZapiszDoPliku("figury/przeszkoda1.dat")) return 1;
  if (!p2.ZapiszDoPliku("figury/przeszkoda2.dat")) return 1;
  if (!p3.ZapiszDoPliku("figury/przeszkoda3.dat")) return 1;
  

  I.Zapis();
  I.Rysowanie();
  char comm;
  do{
    cout<<endl<<"---MENU---"<<endl;
    cout<<      "t - translacja"<<endl;
    cout<<      "r - rotacja"<<endl;
    cout<<      "s - selekcja robota"<<endl;
    cout<<      "k - koniec pracy programu"<<endl;
    cout<<      "Podaj komende:";
    cin>>comm;

    
    switch (comm) {
    case 't':
      double p;
      cin>>p;
      //I.RuchR(p,NRrob,SPEED);
      
      for(;p>0;p-=SPEED)
	{
	  R1.Translation(SPEED);
	  Wektor2D Poz = R1.Position();
	  //I.ListaRob[NRrob].Translation(SPEED);
	  s.dodaj_el(R1.Position());
	  if (!R1.ZapiszDoPliku("figury/robot.dat")) return 1;
	  if(!s.ZapiszDoPliku("figury/sciezka.dat")) return 1;	
	  I.Rysowanie(); 
	  usleep(200000);
	  
	  if(R2.Kolizja(Poz,R1.Promien) == true){break;};
	  if(R3.Kolizja(Poz,R1.Promien) == true){break;};
	  if(p1.Kolizja(Poz,R1.Promien) == true){break;};
	  if(p2.Kolizja(Poz,R1.Promien) == true){break;};
	  if(p3.Kolizja(Poz,R1.Promien) == true){break;};
	}

      I.Rysowanie();
      break;
      
      
    case 'r':
      int ang;
      cin>>ang;
      //I.ListaRob[NRrob].Rotation(SPEED);
      for(;ang>0; ang-=SPEED){
	//(I.ListaRob[NRrob]).Rotation(SPEED);
	//I.RotR(ang,NRrob,SPEED);
	R1.Rotation(SPEED);
	if (!s.ZapiszDoPliku("figury/sciezka.dat")) return 1;
	if (!R1.ZapiszDoPliku("figury/robot.dat")) return 1;
	I.Rysowanie();
	usleep(200000);
      }

  /*   for(;ang>0;ang-=SPEED){
	I.RotR(ang,NRrob,SPEED);
	if (!s.ZapiszDoPliku("figury/sciezka.dat")) return 1;
	if (!R1.ZapiszDoPliku("figury/robot.dat")) return 1;
	
	//if (!s2.ZapiszDoPliku("figury/sciezka2.dat")) return 1; 
	//if (!R2.ZapiszDoPliku("figury/robot2.dat")) return 1;
	
	//if (!s3.ZapiszDoPliku("figury/sciezka3.dat")) return 1; 
	//if (!R3.ZapiszDoPliku("figury/robot3.dat")) return 1;
	I.Rysowanie();
	}*/
      break;
      
      
    case 's':
      cout<<endl<<"Pozycja aktualnego robota:"<<I.ListaRob[NRrob].Position()<<endl;
      for(unsigned int i=0; i<I.ListaRob.size();++i)
	cout<<"Pozycja robota nr("<<i<<"):"<<I.ListaRob[i].Position();
      //cout<<"Podaj nr nowego robota:";
      //cin>>NRrob;
      cout<<endl;
      break;
      
    case 'k':
      exit(0);
      break;
         
    default :
      cerr<<endl<<"Bledna komenda!"<<endl;
      break;
    }
  }while(comm != 'k');  
}

