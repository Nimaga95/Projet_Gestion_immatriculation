/**
 * \file: VehiculeTesteur.cpp
 * \brief Implantation des tests unitaires de la classe Vehicule.
 *        Vehicule étant une classe abstraite, on crée une classe concrète
 *        dérivée de cette classe afin de pouvoir effectuer les tests
 * Created on : 2023-03-01
 * \author: El hadji Nimaga
 */

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "Vehicule.h"
#include "ContratException.h"
#include <memory>
#include <sstream>

using namespace saaq;
using namespace std;

/**
 * \class VehiculeDeTest
 * \brief classe de test permettant de tester la classe abstraite Vehicule.
 */
class VehiculeDeTest : public Vehicule
{

public:


  VehiculeDeTest (const string& p_niv, const string& p_immatriculation) : Vehicule (p_niv, p_immatriculation) { };
  //instancie un objet Vehicule


  virtual std::string
  reqVehiculeFormate () const
  {
    return "Test"; //on rétourne juste quelquechose
  };


  virtual std::unique_ptr<Vehicule>
  clone () const
  {
    return make_unique<VehiculeDeTest>(*this);
  }


  virtual
  ~VehiculeDeTest () { };


  double
  tarificationAnnuelle () const
  {
    return 1.2; // on rétourne juste quelquechose
  };


  void
  asgImmatriculation (const std::string& numero_vehicule) {
    // pas besoin de faire quoi que ce soit ici.
  }
} ;


/**
 * \brief Test du Constructeur avec paramètres
 *        cas valide: Constructeur avec les bonns paramètres : p_niv, p_immatriculation.
 *        cas invalides : p_niv invalide invalide, p_niv et p_immatriculation invalides.
 */

TEST (Vehicule, ConstructeurAvecParametre) // teste si les parametres sont les bons
{
  VehiculeDeTest unVehicule ("1M8GDM9AXKP042788", "L000000");
  ASSERT_EQ ("1M8GDM9AXKP042788", unVehicule.reqNiv ());
  ASSERT_EQ ("L000000", unVehicule.reqImmatriculation ());
}

// Cas invalide 1 : Le numéro de série du Véhicule (ou NIV) n'est pas valide.


TEST (Vehicule, ConstructeurInvalideNiv)
{
  ASSERT_THROW (VehiculeDeTest unVehicule ("1M8GDM9AXKP04278", "L000000"), ContratException) << "Le Niv n'est pas Valide";
}

// Cas invalide 2 : Le numéro d'immatriculation et le numéro de série du Véhicule (ou NIV) ne sont pas valides.


TEST (Vehicule, ConstructeurInvalideImmatriculationNiv)
{
  ASSERT_THROW (VehiculeDeTest unVehicule ("1M8GDM9AXKP04278", "L0000"), ContratException) << "L'immatriculation et le NIV ne sont pas Valides";
}

/**
 * \class VehiculeTest
 * \brief Fixture VehiculeFixture pour la création d'un objet Vehicule pour les tests.
 */
class VehiculeTest : public ::testing::Test
{

public:


  VehiculeTest () : vehiculeFixture ("1M8GDM9AXKP042788", "IFT 006") { }
  VehiculeDeTest vehiculeFixture;
} ;


/**
 * \brief Test de la méthode reqNiv
 *        cas valide: retouner le numéro de série (ou NIV) du véhicule.
 *        cas invalides : aucun identifié.
 **/

TEST_F (VehiculeTest, reqNiv)
{
  ASSERT_EQ ("1M8GDM9AXKP042788", vehiculeFixture.reqNiv ());
}


/**
 * \brief Test de la méthode reqImmatriculation
 *        cas valide: retouner le numéro d'immatriuclation du véhicule.
 *        cas invalides : aucun identifié.
 **/

TEST_F (VehiculeTest, reqImmatriculation)
{
  ASSERT_EQ ("IFT 006", vehiculeFixture.reqImmatriculation ());
}


/**
 * \brief Test de la méthode reqVehiculeFormate
 *        cas valide: retourner dans un string les données du véhicule.
 *        cas invalides : aucun identifié.
 **/
TEST_F (VehiculeTest, reqVehiculeFormate)
{
  ostringstream os;
  os << vehiculeFixture.reqVehiculeFormate ();
  ASSERT_EQ (os.str (), vehiculeFixture.reqVehiculeFormate ());
}


/**
 * \brief Test de l'opérateur surchagé d'égalité (operator ==)
 *        cas valide: retourner true si les deux véhicules sont pareils, false sinon.
 *        cas invalides : aucun identifié.
 **/
// Cas 1 : Un Véhicule égale à lui même


TEST_F (VehiculeTest, Egalite)
{
  VehiculeDeTest  vehiculeFixture1 ("1M8GDM9AXKP042788", "IFT 006");

  EXPECT_TRUE (vehiculeFixture.operator == (vehiculeFixture1));

}
// Cas 2 : Deux Véhicules différents


TEST_F (VehiculeTest, PasEgalite)
{
  VehiculeDeTest  vehiculeFixture2 ("1M8GDM9AXKP042788", "L000000");

  EXPECT_FALSE (vehiculeFixture.operator == (vehiculeFixture2));

}
