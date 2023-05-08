#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include "Vehicule.h"
#include "Proprietaire.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "ContratException.h"
using namespace saaq;
using namespace std;


/**
 * \brief Test du Constructeur avec parametres
 *        cas valide: Constructeur avec les bons paramètres : p_nom, p_prenom.
 *        cas invalides : p_nom vide, p_prenom vide.
 */

TEST (Proprietaire, ConstructeurAvecParametres)
{
  Proprietaire unProprietaire ("Tremblay", "Louis");
  ASSERT_EQ ("Tremblay", unProprietaire.reqNom ());
  ASSERT_EQ ("Louis", unProprietaire.reqPrenom ());
}

// Cas invalide 1 : Le nom est invalide.


TEST (Proprietaire, ConstructeurNomInvalide)

{
  ASSERT_THROW (Proprietaire unProprietaire ("", "Louis"), PreconditionException) << " Le nom ne doit pas être vide";
}

// Cas invalide 2 : Le prénom est invalide.


TEST (Proprietaire, ConstructeurPrenomInvalide)

{
  ASSERT_THROW (Proprietaire unProprietaire ("Tramblay", ""), PreconditionException) << " Le prénom ne doit pas être vide";
}


/**
 * \brief Test du Constructeur copie.
 *        cas valide: Constructeur avec les bons paramètres : p_nom, p_prenom.
 *        cas invalides : aucun.
 */
TEST (Prorietaire, ConstructeurCopie)
{

  Proprietaire proprietaireOriginal ("Tremblay", "Louis"); // On crée un objet proprietaire1 avec paramètres nom et prénom.
  Camion unCamion ("1HTMKADN43H561298", "L000000", 4000, 6 ); // On crée un objet camion avec paramètres aussi.
  proprietaireOriginal.ajouterVehicule (unCamion); // ajout du camion au propriètaire1



  Proprietaire proprietaireCopie (proprietaireOriginal); // On appelle le constructeur de copie pour créer un propriètaire2.

  ASSERT_EQ (proprietaireOriginal.reqProprietaireFormate (), proprietaireCopie.reqProprietaireFormate ()); // On vérifie que les deux proprietaires ont les mêmes informations.

}

/**
 * \class ProprietaireTest
 * \brief Fixture proprietaireFixture pour la création d'un objet Proprietaire pour les tests.
 */
class ProprietaireTest : public ::testing::Test
{

public:


  ProprietaireTest () :
  proprietaireFixture ("Tremblay", "Louis") { };
  Proprietaire proprietaireFixture;
} ;


/**
 * \brief Test de la méthode reqNom
 *        cas valide: rétourner le nom du proprietaireFixture.
 *        cas invalides : aucun
 **/

TEST_F (  ProprietaireTest, reqNom)
{
  ASSERT_EQ ("Tremblay", proprietaireFixture.reqNom ());
}


/**
 * \brief Test de la méthode reqPrenom
 *        cas valide: rétourner le prénom du proprietaireFixture.
 *        cas invalides : aucun
 **/

TEST_F (  ProprietaireTest, reqPrenom )

{
  ASSERT_EQ ("Louis", proprietaireFixture.reqPrenom ());
}


/**
 * \brief Test de la méthode renbVehicules
 *        cas valide: rétourner le nombre de véhicules du proprietaireFixture.
 *        cas invalides : aucun
 **/
TEST_F (  ProprietaireTest, reqnbVehicules )
{
  VehiculePromenade VehiculePromenade1 ("3VWFE21C04M000001", "IFT 007", 6);
  VehiculePromenade VehiculePromenade2 ("3VWFE21C04M000001", "IFT 008", 7);
  proprietaireFixture.ajouterVehicule (VehiculePromenade1);
  proprietaireFixture.ajouterVehicule (VehiculePromenade2);

  ASSERT_EQ (2, proprietaireFixture.reqnbVehicules ());
}


/**
 * \brief Test de la méthode reqProprietaireFormate
 *        cas valide: vérifier que la méthode reqProprietaireFormate rétourne les bonnes informations du proprietaireFixture.
 *        cas invalides : aucun
 **/
TEST_F (ProprietaireTest, reqProprietaireFormate)
{

  ostringstream os;
  os << proprietaireFixture.reqProprietaireFormate ();
  ASSERT_EQ (os.str (), proprietaireFixture.reqProprietaireFormate ());
}


/**
 * \brief Test de la méthode l'operateur d'assignation
 *        cas valide: vérifier que la méthode reqProprietaireFormate rétourne les bonnes informations du proprietaireFixture.
 *        cas invalides : aucun
 **/
TEST_F (ProprietaireTest, OperateurAssignation)

{
  Proprietaire proprietaireBase ("John", "Doe");
  VehiculePromenade vehiculePromenade ("3VWFE21C04M000001", "IFT 007", 6);
  proprietaireBase.ajouterVehicule (vehiculePromenade);

  proprietaireFixture.operator = (proprietaireBase);

  ASSERT_EQ (proprietaireBase.reqProprietaireFormate (), proprietaireFixture.reqProprietaireFormate () );

}


/**
 * \brief Test de la méthode l'operateur ajouterVehicule
 *        cas valide: vérifier qu'un véhicule de proménade a bien été ajouté à un propriètaire.
 *        cas invalides : aucun
 **/
// Cas 1 : Ajouter un véhicule


TEST_F (ProprietaireTest, ajouterVehicule)
{

  VehiculePromenade car1 ("3VWFE21C04M000001", "IFT 006", 5);
  proprietaireFixture.ajouterVehicule (car1);
  ASSERT_EQ (1, (proprietaireFixture.reqnbVehicules ()));
}

//Cas 2 : Ajouter un véhicule à travers un pointeur


TEST_F (ProprietaireTest, ajouterVehicule2)
{
  VehiculePromenade * vehiculePromenade = new VehiculePromenade ("3VWFE21C04M000001", "IFT 006", 5);

  proprietaireFixture.ajouterVehicule (*vehiculePromenade);
  EXPECT_EQ (proprietaireFixture.reqnbVehicules (), 1);

}

