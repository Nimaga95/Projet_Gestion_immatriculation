/**
 * \file:   VehiculePromenade.cpp
 * @brief Implémentation de la classe VehiculePromenade
 * \author: El hadji Nimaga
 */
#include <sstream>
#include "ContratException.h"
#include "VehiculePromenade.h"
#include "ValidationFormat.h"
#include <string>
#include <sstream>
#include <memory>
using namespace std;
using namespace util;

namespace saaq
{


  /**
   * \brief Constructeur de la classe VehiculePromenade.
   * \param[in] p_niv : Le numéro de série du véhicule de promenade (ou NIV).
   * \param[in] p_immatriculation : Le numéro de plaque d’immatriculation du véhicule de promenade.
   * \pre (validerImmatriculationPromenade (p_immatricultion)) : La plaque d'immatriculation doit être valide pour un véhicule de promenade.
   * \pre (p_nbPlaces > 0) : Le nombre de places du véhicule de promenade doit être supérieur à 0.
   * \post (p_immatriculation == m_immatriculatio) : Vérifie que la plaque d'immatriculation du véhicule de promenade est bien initialisée avec la valeur passée en paramètre.
   * \post (m_nbPlaces == p_nbPLaces) : Vérifie que le nombre de places du véhicule de promenade est bien initialisé avec la valeur passée en paramètre.
   */
  VehiculePromenade::VehiculePromenade (const string& p_niv, const string& p_immatriculation,
                                        const int& p_nbPlaces) : Vehicule (p_niv, p_immatriculation), m_nbPlaces (p_nbPlaces)
  {
    PRECONDITION (validerImmatriculationPromenade (p_immatriculation));
    PRECONDITION (p_nbPlaces > 0);
    POSTCONDITION (m_immatriculation == p_immatriculation );
    POSTCONDITION (m_nbPlaces == p_nbPlaces);
    INVARIANTS (); // Vérification des invariants de la classe.

  }


  /**
   * \brief Accesseur pour le nombre de places du véhicule de promenade.
   * @return  int : le nombre de places du véhicule de promenade.
   */
  int
  VehiculePromenade::reqnbPlaces () const
  {
    return m_nbPlaces;
  }


  /**
   *  \brief Cette méthode modifie le numéro d'immatriculation du véhicule de promenade.
   *  @param[in] nouveauImmatriculation : le nouveau numéro d'immatriculation à assigner.
   *  \pre Le numéro d'immatriculation doit être valide pour un véhicule de promenade.
   *  \post Verifier que numéro d'immatriculation du véhicule de promenade a bien été modifié.
   */
  void
  VehiculePromenade::asgImmatriculation (const std::string& nouveauImmatriculation)
  {
    PRECONDITION (validerImmatriculationPromenade (nouveauImmatriculation));
    m_immatriculation == nouveauImmatriculation;
    POSTCONDITION (m_immatriculation == nouveauImmatriculation);

    INVARIANTS ();
  }


  /**
   * \brief Cette méthode convertit les données du Véhicule de proménade dans une chaîne de caractères formatée.
   * \return string : la chaîne de caractères formatée contenant les informations du véhicule de promenade.
   */
  std::string
  VehiculePromenade::reqVehiculeFormate () const
  {
    ostringstream os;

    os << saaq::Vehicule::reqVehiculeFormate (); // Appelle de la méthode reqVehiculeFormate de la classe de base.
    os << "nombre de places : " << reqnbPlaces () << endl;
    os << "tarif : " <<  tarificationAnnuelle () << "$" << endl;

    return os.str ();
  }


  /**
   * @brief Cette méthode calcule la tarification annuelle d'un véhicule de promenade.
   * @return double : le tarif annuel fixe pour un véhicule de promenade.
   */
  double
  VehiculePromenade::tarificationAnnuelle () const
  {
    double tarif (232.74);
    return tarif;
  }


  /**
   * Cette méthode permet de faire une copie de l'objet VehiculePromenade.
   * @return un pointeur unique (std::unique_ptr) vers un nouvel objet VehiculePromenade qui a été créé en utilisant le constructeur de copie (*this).
   */
  std::unique_ptr<Vehicule>
  VehiculePromenade::clone ()const
  {
    return make_unique <VehiculePromenade> (*this);

  }


  /**
    @brief Méthode qui vérifie que tous les invariants de la classe VehiculePromenade sont respectés.
   */
  void
  VehiculePromenade::verifieInvariant () const
  {


    INVARIANT (validerImmatriculationPromenade (m_immatriculation));

    INVARIANT (m_nbPlaces > 0);
  }


  /**
   * \brief Destructeur de la classe VehiculePromenade.
   *
   */
  VehiculePromenade::~VehiculePromenade () { }

} /* namespace saaq*/



