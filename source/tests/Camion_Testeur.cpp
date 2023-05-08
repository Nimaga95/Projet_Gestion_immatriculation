/**
 * \file: CamionTesteur.cpp
 * Created on : 2023-03-01
 * \author: El hadji Nimaga
 */
#include <gtest/gtest.h>
#include"Camion.h"
#include "Vehicule.h"
#include <string>
#include <sstream>
#include <iostream>
#include "ContratException.h"
using namespace saaq;
using namespace std;


/**
 * \brief Test du Constructeur avec parametres
 *        cas valide: Constructeur avec les bons paramètres : p_niv, p_immatriculation, poids, nbEssieux.
 *        cas invalides : p_niv invalide, p_immatriculation invalide, poids invalide, nbEssieux invalide.
 */
TEST (Camion, ConstructeurValide) // test si les parametres sont  bons
{
  Camion unCamion ("1M8GDM9AXKP042788", "L000000", 4000, 5);
  ASSERT_EQ ("1M8GDM9AXKP042788", unCamion.reqNiv ());
  ASSERT_EQ ("L000000", unCamion.reqImmatriculation ());
  ASSERT_EQ (4000, unCamion.reqPoids ());
  ASSERT_EQ (5, unCamion.reqnbEssieux ());
}
// Cas invalide 1 : Niv invalide.


TEST (Camion, ConstructeurInvalideNiv)
{
  ASSERT_THROW (Camion unCamion ("1M8GDM9AXKP04278", "L000000", 4000, 5), ContratException ) << "Le Niv n'est pas Valide";
}

// Cas invalide 2 : Numéro immatriculatio invalide.


TEST (Camion, ConstructeurInvalideImmatriculation)
{
  ASSERT_THROW (Camion unCamion ("1M8GDM9AXKP042788", "L00000", 4000, 5), ContratException) << "L'immatriculation n'est pas Valide";
}
// Cas invalide 3 : Le poids est invalide.


TEST (Camion, ConstructeurInvalidPoids)
{
  ASSERT_THROW (Camion unCamion ("1M8GDM9AXKP042788", "L000000", 2900, 10), ContratException) << "Le poids n'est pas valide";
}

// Cas invalide 4 : Le nombre d'essieux n'est pas valide.


TEST (Camion, ConstructeurInvalidenbEssieux)
{
  ASSERT_THROW (Camion unCamion ("1M8GDM9AXKP042788", "L000000", 4000, 1), ContratException) << "Le nombre d'essieux n'est pas valide";
}


/**
 * \brief Test de la méthode std::unique_ptr<Vehicule> clone ()
 * Cas valide : On vérifie que le clone est identique à l'original.
 * Cas invalide : aucun
 */
TEST (Camion , CloneTest)
{

  Camion camionOriginal ("1M8GDM9AXKP042788", "L000000", 4000, 5);

  std::unique_ptr<Vehicule>  camionClone = camionOriginal.clone ();

  ASSERT_EQ (camionOriginal.reqVehiculeFormate (), camionClone-> reqVehiculeFormate ());
}

/**
 * \class CamionTest
 * \brief Fixture CamionFixture pour la création d'un objet Camion pour les tests.
 */

class CamionTest : public ::testing::Test
{

public:


  CamionTest () :
  camionFixture ("1M8GDM9AXKP042788", "L000000", 4001, 5) { };
  Camion camionFixture;
} ;


/**
 * \brief Test de la méthode reqNiv
 *        cas valide: retourner le numéro de série (ou NIV) du camionFixture.
 *        cas invalides : aucun identifié.
 **/
TEST_F (CamionTest, reqNiv)
{
  ASSERT_EQ ("1M8GDM9AXKP042788", camionFixture.reqNiv ());
}


/**
 * \brief Test de la méthode reqImmatriculation
 *        cas valide: retourner le numéro d'immatriculation du camionFixture.
 *        cas invalides : aucun identifié.
 **/
TEST_F (CamionTest, reqImmatriculation)
{
  ASSERT_EQ ("L000000", camionFixture.reqImmatriculation ());
}


/**
 * \brief Test de la méthode asgImmatriculation
 *        cas valide: vérifier que le numéro d'immatriculation du camionFixture a bien été modifié.
 *        cas invalides : Mauvais immatriculation
 **/
TEST_F (CamionTest, asgImmatriculation)
{
  camionFixture.asgImmatriculation ("L000111");
  ASSERT_EQ ("L000111", camionFixture.reqImmatriculation ());
}
//Cas invalide : Le numéro d'immatriculation n'est pas valide.


TEST_F (CamionTest, asgImmatriculationMauvaisImmatriculation)
{
  ASSERT_THROW (camionFixture.asgImmatriculation ("ABBBBBB"), ContratException ) << "Cette immtriculation n'est pas valide";
}


/**
 * \brief Test de la méthode reqnnEssieux
 *        cas valide: rétourner le nombre d'essieux du camionFixture.
 *        cas invalides : Mauvais immatriculation
 **/


TEST_F (CamionTest, reqnbEssieux )
{
  ASSERT_EQ (5, camionFixture.reqnbEssieux ());
}


/**
 * \brief Test de la méthode rePoids
 *        cas valide: rétourner le nombre poids du camionFixture.
 *        cas invalides : aucun
 **/

TEST_F (CamionTest, reqPoids)
{
  ASSERT_EQ (4001, camionFixture.reqPoids ()
             );
}


/**
 * \brief Test de la méthode reqVehiculeFormate
 *        cas valide: vérifier que la méthode reqVehiculeFormate rétourne les bonnes informations du camionFixture.
 *        cas invalides : aucun
 **/
TEST_F (CamionTest, reqVehiculeFormate)
{


  ostringstream os;
  os << camionFixture.reqVehiculeFormate ();
  ASSERT_EQ (os.str (), camionFixture.reqVehiculeFormate ());
}


/**
 * \brief Test de la méthode tarificationAnnuelle
 *        cas valide: rétourne la bonne tarification du camionFixture.
 *        cas invalides : aucun
 **/
TEST_F (CamionTest, tarificationAnnuelle)
{

  ASSERT_EQ (3051.13, camionFixture.tarificationAnnuelle ());
}


/**
 * \brief Test de l'opérateur bool ==
 *        cas valide: retouner true si les deux camions sont pareils, false sinon.
 *        cas invalides : Deux camions différents.
 **/
TEST_F (CamionTest, Egalite)
{
  EXPECT_TRUE ( (camionFixture.operator == (camionFixture)));
}

//Cas invalide : deux camions différents


TEST_F (CamionTest, PasEgalite)
{
  Camion camionFixture1 ("1M8GDM9AXKP042788", "L000001", 4000, 5);
  EXPECT_FALSE (camionFixture.operator == (camionFixture1));
}