/**
 * \file: VehiculePromenadeTesteur.cpp
 * Created on : 2023-03-01
 * \author: El hadji Nimaga
 */

#include<gtest/gtest.h>
#include"VehiculePromenade.h"
#include "Vehicule.h"
#include<string>
#include <sstream>
#include<iostream>
#include "ContratException.h"
using namespace saaq;
using namespace std;


/**
 * \brief Test du Constructeur avec parametres
 *        cas valide: Constructeur avec les bons paramètres : p_niv, p_immatriculation, nbPlaces.
 *        cas invalides : p_niv invalide, p_immatriculation invalide, nbPlaces invalide.
 */
TEST (VehiculePromenade, ConstructeurAvecParametre) // test si les parametres sont  bons
{
  VehiculePromenade unVehicule ("1M8GDM9AXKP042788", "ABC 000", 10);
  ASSERT_EQ ("1M8GDM9AXKP042788", unVehicule.reqNiv ());
  ASSERT_EQ ("ABC 000", unVehicule.reqImmatriculation ());
  ASSERT_EQ (10, unVehicule.reqnbPlaces ());
}
// Cas invalide 1 : Niv invalide.


TEST (VehiculePromenade, ConstructeurInvalideNiv)
{
  ASSERT_THROW (VehiculePromenade unVehicule ("1M8GDM9AXKP04278", "ABC 000", 10), ContratException ) << "Le Niv n'est pas Valide";
}
//Cas invalide 2 : Immatriculation invalide.


TEST (VehiculePromenade, ConstructeurInvalideImmatriculation)
{
  ASSERT_THROW (VehiculePromenade unVehicule ("1M8GDM9AXKP042788", "ABCD0", 10), ContratException) << "L'immatriculation n'est pas Valide";
}

// cas invalide 3 : Nombre de places invalide.


TEST (VehiculePromenade, ConstructeurInvalidenbPlace)
{
  ASSERT_THROW (VehiculePromenade unVehicule ("1M8GDM9AXKP042788", "ABCD0", 0), ContratException) << "Le nombre de place ne peut etre 0";
}


/**
 * \brief Test de la méthode std::unique_ptr<Vehicule> clone ()
 * Cas valide : On vérifie que le clone est identique à l'original.
 * Cas invalide : aucun
 */

TEST (VehiculePromenade , CloneTest)
{

  saaq::VehiculePromenade vehiculePromenadeOriginal ("1M8GDM9AXKP042788", "IFT 006", 5); // On crée un nouvel objet car1

  std::unique_ptr<Vehicule>  vehiculePromenadeClone = vehiculePromenadeOriginal.clone (); // On crée un nouvel obejt car2 à partir du clone de car1


  ASSERT_EQ (vehiculePromenadeOriginal.reqVehiculeFormate (), vehiculePromenadeClone-> reqVehiculeFormate ()); // On vérifie que les deux objets sont identiques.
}

/**
 * \class VehiculePromenadeDeTest
 * \brief Fixture VehiculePromenadeFixture pour la création d'un objet VehiculePromenade pour les tests.
 */
class VehiculePromenadeDeTest : public ::testing::Test
{

public:


  VehiculePromenadeDeTest () :
  vehiculePromenadeFixture ("1M8GDM9AXKP042788", "IFT 006", 5) { };
  VehiculePromenade vehiculePromenadeFixture;
} ;


/**
 * \brief Test de la méthode reqNiv
 *        cas valide: retourner le numéro de série (ou NIV) du vehiculePromenadeFixture.
 *        cas invalides : aucun identifié.
 **/
TEST_F (VehiculePromenadeDeTest, reqNiv)
{
  ASSERT_EQ ("1M8GDM9AXKP042788", vehiculePromenadeFixture.reqNiv ());
}


/**
 * \brief Test de la méthode reqImmatriculation
 *        cas valide: retourner le numéro d'immatriculation du vehiculePromenadeFixture.
 *        cas invalides : aucun identifié.
 **/

TEST_F (VehiculePromenadeDeTest, reqImmatriculation)
{
  ASSERT_EQ ("IFT 006", vehiculePromenadeFixture.reqImmatriculation ());
}


/**
 * \brief Test de la méthode reqnbPlaces
 *        cas valide: retourner le nombre de places du vehiculePromenadeFixture.
 *        cas invalides : aucun identifié.
 **/
TEST_F (VehiculePromenadeDeTest, reqnbPlaces )
{
  ASSERT_EQ (5, vehiculePromenadeFixture.reqnbPlaces ());
}


/**
 * \brief Test de la méthode asgImmatriculation
 *        cas valide: vérifier que le numéro d'immatriculation du vehiculePromenadeFixture a bien été modifié.
 *        cas invalides : Mauvais immatriculation
 **/
TEST_F (VehiculePromenadeDeTest, asgImmatriculation)
{
  vehiculePromenadeFixture.asgImmatriculation ("IFT 006");
  ASSERT_EQ ("IFT 006", vehiculePromenadeFixture.reqImmatriculation ());
}

//Cas inavalide : Immatriculation invalide.


TEST_F (VehiculePromenadeDeTest, asgImmatriculationInvalide)
{
  ASSERT_THROW (vehiculePromenadeFixture.asgImmatriculation ("ABBBBBB"), ContratException ) << "Cette immtriculation n'est pas valide";
}


/**
 * \brief Test de la méthode reqVehiculeFormate
 *        cas valide: vérifier que la méthode reqVehiculeFormate rétourne les bonnes informations du vehiculePromenadeFixture.
 *        cas invalides : aucun
 **/

TEST_F (VehiculePromenadeDeTest, reqVehiculeFormate)
{
  ostringstream os;
  os << vehiculePromenadeFixture.reqVehiculeFormate ();
  ASSERT_EQ (os.str (), vehiculePromenadeFixture.reqVehiculeFormate ());
}


/**
 * \brief Test de la méthode tarificationAnnuelle
 *        cas valide: vérifier que la méthode rétourne bien la valeur attendue.
 *        cas invalides : aucun cas
 **/
TEST_F (VehiculePromenadeDeTest, tarificationAnnuelle)

{

  ASSERT_EQ (232.74, vehiculePromenadeFixture.tarificationAnnuelle ());
}


/**
 * \brief Test de l'opérateur bool ==
 *        cas valide: retourner true si les deux vehicules de promenade sont pareils, false sinon.
 *        cas invalides : Deux véhicules différents.
 **/
TEST_F (VehiculePromenadeDeTest, Egalite)
{
  EXPECT_TRUE (vehiculePromenadeFixture.operator == (vehiculePromenadeFixture));
}
// Cas invalide


TEST_F (VehiculePromenadeDeTest, PasEgalite)
{
  VehiculePromenade vehiculePromenadeFixture1 ("1M8GDM9AXKP042788", "IFT 008", 10);
  EXPECT_FALSE (vehiculePromenadeFixture.operator == (vehiculePromenadeFixture1));
}
