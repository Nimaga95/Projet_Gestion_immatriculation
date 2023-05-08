/**
 * \file:   Camion.cpp
 * \author: El hadji Nimaga
 */
#include <sstream>
#include "ContratException.h"
#include "ValidationFormat.h"
#include <string>
#include <sstream>
#include "Camion.h"


using namespace std;
using namespace util;
namespace saaq
{


  /**
   * \brief Constructeur de la classe Camion.
   * \param[in] p_niv : Le numéro de série du camion (ou NIV).
   * \param[in] p_immatriculation : Le numéro de plaque d’immatriculation du camion.
   * \param[in] p_poids : Le poids du Camion.
   * \param[in] p_nbEssieux : Le nombre d'essieux du Camion.
   * \pre (m_poids > 3000) : Le poids du camion doit être supérieur à 3000 kg.
   * \pre (m_nbEssieux >= 2) :  Le nombre d'essieux du camion doit être supérieur ou égale à 2.
   * \pre (validerImmatriculationCamion (p_immatriculation)) : Le numéro de plaque d’immatriculation du camion doit être dans un format valide pour un camion.
   * \post (m_poids == p_poids) : Vérifie que le poids du camion est bien initialisé avec la valeur passée en paramètre.
   * \post (m_nbEssieux == p_nbEssieux) : Vérifie que le nombre d'essieux du camion est bien initialisé avec la valeur passée en paramètre.
   */
  Camion::Camion (const string& p_niv, const string& p_immatriculation,
                  const double& p_poids, const int& p_nbEssieux) : Vehicule (p_niv, p_immatriculation), m_poids (p_poids), m_nbEssieux (p_nbEssieux)
  {
    PRECONDITION (m_poids > 3000);
    PRECONDITION (m_nbEssieux >= 2);

    PRECONDITION (validerImmatriculationCamion (p_immatriculation));

    POSTCONDITION (m_poids == p_poids);
    POSTCONDITION (m_nbEssieux == p_nbEssieux);
    // Vérifie que tous les invariants de la classe sont respectés après l'exécution du constructeur
    INVARIANTS ();
  }


  /**
   *  \brief Cette méthode modifie le numéro d'immatriculation du camion.
   *  @param nouveauImmatriculation le nouveau numéro d'immatriculation à assigner.
   *  \pre Le numéro d'immatriculation doit être valide pour un camion.
   *  \post (m_immatriculation == nouveauImmatriculation) : Verifie que numéro d'immatriculation du camion a bien été modifié avec la valeur passée en paramètre.
   */
  void
  Camion::asgImmatriculation (const std::string& nouveauImmatriculation)
  {


    PRECONDITION (validerImmatriculationCamion (nouveauImmatriculation));

    m_immatriculation = nouveauImmatriculation;

    POSTCONDITION (m_immatriculation == nouveauImmatriculation);

    INVARIANTS ();
  }


  /**
   * \brief Accesseur pour le poids du camion.
   * @return  double : le poids du camion.
   */
  double
  Camion::reqPoids () const
  {
    return m_poids;
  }


  /**
   * \brief Accesseur pour le nombre d'essieux du camion.
   * @return  int : le nombre d'essieux du camion.
   */
  int
  Camion::reqnbEssieux () const
  {
    return m_nbEssieux;
  }


  /**
   * \brief Cette méthode calcule la tarification annuelle d'un camion en fonction de son nombre d'essieux et de son poids.
   * @return double : La valeur de la tarification annuelle du camion.
   */
  double
  Camion::tarificationAnnuelle () const
  {
    double tarif;
    {
      if (m_nbEssieux == 2 )
        {
          if (m_poids >= 3001 && m_poids <= 4000)
            {
              tarif = 634.89;
            }

          else if (m_poids >= 4001)
            {
              tarif = 999.89 ;

            }
        }
      else if (m_nbEssieux == 3)
        {
          tarif = 1711.19;
        }
      else if (m_nbEssieux == 4)
        {
          tarif = 2409.19;
        }
      else  if (m_nbEssieux == 5)
        {
          tarif = 3051.13;
        }
      else
        {
          tarif = 4040.13;
        }
    }
    return tarif;
  }


  /**
   * \brief Cette méthode convertit les données du camion dans une chaîne de caractères formatée.
   * \return string : la chaîne de caractères formatée contenant les informations du camion.
   */
  std::string
  Camion::reqVehiculeFormate () const
  {
    ostringstream os;

    os << Vehicule::reqVehiculeFormate (); // Appel à la méthode reqVehiculeFormate() de la classe de base.
    os << "nombre d'essieux : " << reqnbEssieux () << endl;
    os << "poids : " <<  reqPoids () << " kg" << endl;
    os << "tarif : " << tarificationAnnuelle  () << "$" << endl;

    return os.str ();
  }


  /**
   * Cette méthode permet de faire une copie de l'objet camion.
   * @return un pointeur unique (std::unique_ptr) vers un nouvel objet camion qui a été créé en utilisant le constructeur de copie (*this).
   */
  std::unique_ptr<Vehicule>
  Camion::clone ()const
  {
    return make_unique <Camion> (*this);


  }


  /**
    @brief Cette méthode vérifie que tous les invariants de la classe Camion sont respectés.
   */
  void
  Camion::verifieInvariant ()const

  {
    INVARIANT (m_poids > 3000);
    INVARIANT (m_nbEssieux >= 2);
    INVARIANT (validerImmatriculationCamion (m_immatriculation));

  }


  /**
   * \brief Destructeur de la classe Camion.
   */
  Camion::~Camion () { }
} /* namesapace saaq */

