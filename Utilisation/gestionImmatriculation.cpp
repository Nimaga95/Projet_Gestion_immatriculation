/*
 * File:   gestionImmatriculation.cpp
 * Author: etudiant
 * Created on 20 avril 2023, 20:53
 */
#include <limits>
#include <cstdlib>
#include <string>
#include <iostream>
#include "ValidationFormat.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "Vehicule.h"
#include "Proprietaire.h"
using namespace std;
using namespace saaq;


int
main ()
{

  string nivPromenade, nivCamion, immatriculationPromenade, immatriculationCamion;
  int poids, nbPlaces, nbEssieux;
  char buffer [256];
  cout << "*******************************************************" << endl;
  cout << " Bienvenue a l'outil d'ajout de gestion de vehicules " << endl;
  cout <<  "*******************************************************" << endl;

  cout << " -------------------------------------------------------" << endl;
  cout << " Ajoutez un vehicule de promenade" << endl;
  cout << " -------------------------------------------------------" << endl;

  do
    {
      cout << "Entrez le numero de serie :" << endl;
      cin >> nivPromenade;
      cin.ignore (numeric_limits<streamsize>::max (), '\n');
      if (!util::validerNiv (nivPromenade))
        {
          cout << "Ce numero de Serie n'est pas valide" << endl;
        }
    }
  while (!util::validerNiv (nivPromenade));

  do
    {
      cout << "Entrez le numero d'Immatriculation :" << endl;
      getline (cin, immatriculationPromenade);
      if (!util::validerImmatriculationPromenade (immatriculationPromenade))
        {
          cout << "Le numero d'immatriculation n'est pas valide" << endl;
        }
    }
  while (!util::validerImmatriculationPromenade (immatriculationPromenade));

  do
    {
      cout << "Entrez le nombre de places > 0" << endl;
      cin >> nbPlaces;
      if (nbPlaces <= 0)
        {
          cout << "Le nombre de place n'est pas valide" << endl;
        }
    }
  while (!nbPlaces > 0);
  VehiculePromenade vehicule1 (nivPromenade, immatriculationPromenade, nbPlaces);
  Proprietaire proprietaire ("Tremblay", "Louis");
  proprietaire.ajouterVehicule (vehicule1);





  cout << " -------------------------------------------------------" << endl;
  cout << " Ajoutez un camion" << endl;
  cout << " -------------------------------------------------------" << endl;

  do
    {
      cout << "Entrez le numero de serie :" << endl;
      cin >> nivCamion;
      cin.ignore (numeric_limits<streamsize>::max (), '\n');
      if (!util::validerNiv (nivCamion))
        {
          cout << "Ce numero de Serie n'est pas valide" << endl;
        }
    }
  while (!util::validerNiv (nivCamion));

  do
    {
      cout << "Entrez le numero d'Immatriculation :" << endl;
      getline (cin, immatriculationCamion);
      if (!util::validerImmatriculationCamion (immatriculationCamion))
        {
          cout << "Le numero d'immatriculation n'est pas valide" << endl;
        }
    }
  while (!util::validerImmatriculationCamion (immatriculationCamion));

  do
    {
      cout << "Entrez le poids du camion > 3000" << endl;
      cin >> poids;
      if (poids < 3000)
        {
          cout << "Le poids du camion n'est pas valide" << endl;
        }
    }
  while (!poids > 3000);

  do
    {
      cout << "Entrez le nombre d'essieux >= 2" << endl;
      cin >> nbEssieux;
      if (!nbEssieux >= 2)
        {
          cout << "Le nombre d'essieux n'est pas valide" << endl;
        }
    }
  while (!nbEssieux >= 2);

  Camion camion1 (nivCamion, immatriculationCamion, poids, nbEssieux);

  proprietaire.ajouterVehicule (camion1);
  cout << proprietaire.reqProprietaireFormate ();





  return 0;
}

