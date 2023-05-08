/**
 * \file:   Vehicule.cpp
 * @brief Implémentation de la classe Vehicule
 * \author: El hadji Nimaga
 */
#include <string>
#include "Vehicule.h"
#include <sstream>
#include "ContratException.h"
#include "ValidationFormat.h"

using namespace std;
using namespace util;


namespace saaq
{


  /**
   * \brief Constructeur de la classe Vehicule.
   * \param[in] p_niv : Le numéro de série du Véhicule (ou NIV).
   * \param[in] p_immatriculation : Le numéro de plaque d’immatriculation du Véhicule.
   * \pre (validerNiv (p_niv)) : Le numéro de série du Vehicule doit être dans un format valide avant de continuer.
   * \post (p_niv == m_niv) : Vérifie que le numéro de serie du véhicule est bien initialisé avec la valeur passée en paramètre.
   *
   */
  Vehicule::Vehicule (const string& p_niv, const string& p_immatriculation) : m_niv (p_niv),
  m_immatriculation (p_immatriculation)
  {

    PRECONDITION (validerNiv (p_niv));

    POSTCONDITION (p_niv == m_niv);
    // Vérifie que tous les invariants de la classe sont respectés après l'exécution du constructeur.
    INVARIANTS ();
  }


  /**
   * \brief Accesseur pour le numéro de série (NIV) du Vehicule.
   * \return string : une chaîne de caractères représentant le numéro de série (NIV) du Vehicule.
   */
  string
  Vehicule::reqNiv () const
  {
    return m_niv;
  }


  /**
   * \brief Accesseur pour le numéro de plaque d’immatriculation du Vehicule.
   * \return string : une chaîne de caractères représentant le numéro de plaque d’immatriculation du Vehicule.
   */
  string
  Vehicule::reqImmatriculation () const
  {
    return m_immatriculation;

  }


  /**
   * \brief Surcharge de l'opérateur == pour comparer deux objets véhicules.
   * \param[in] p_vehicule : L'objet Vehicule à comparer.
   * \return bool : True si les deux objets sont égaux, False sinon.
   */
  bool Vehicule::operator== (const Vehicule & p_vehicule) const
  {
    return m_niv == p_vehicule.m_niv && m_immatriculation == p_vehicule.m_immatriculation;
  }


  /**
   * \brief Convertit les données du Véhicule dans une chaîne de caractères formatée.
   * \return string : la chaîne de caractères formatée contenant les informations du Véhicule.
   */
  string
  Vehicule::reqVehiculeFormate () const
  {
    ostringstream os;
    os << "Numero de série : " << reqNiv () << endl; // Ajout du numéro de série (NIV) au flux.
    os << "Numero d'immatriculation : " << reqImmatriculation () << endl; // Ajout du numéro d'immatriculation au flux.
    return os.str ();
  }


  /**
   * \brief Vérifie que tous les invariants de la classe Vehicule sont respectés.
   *
   */
  void
  Vehicule::verifieInvariant ()const
  {
    INVARIANT (validerNiv (m_niv) );

  }


  /**
   * \brief Destructeur de la classe Vehicule.
   *
   */
  Vehicule::~Vehicule () { }

}/* namesapace saaq */
