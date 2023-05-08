/**
 * \file:   Proprietaire.cpp
 * @brief Implémentation de la classe Proprietaire
 * \author: El hadji Nimaga
 */
#include <vector>
#include<iostream>
#include<string>
#include<sstream>
#include"ContratException.h"
#include "Proprietaire.h"
#include "Vehicule.h"
#include "Camion.h"
#include "VehiculePromenade.h"
#include <vector>
#include <memory>

using namespace std;
using namespace saaq;
namespace saaq
{


  /**
   * \brief Constructeur de la classe Proprietaire
   * \param[in] p_nom : Le nom du propriétaire.
   * \param[in] p_prenom : Le prénom du propriétaire.
   * \pre (!p_nom.empty): Le nom du propriétaire ne peut pas être vide.
   * \pre (!p_prenom.empty) : Le prénom du propriétaire ne peut pas être vide.
   * \post (m_nom == p_nom) : Vérifie que le nom du propriétaire est bien initialisé avec la valeur passée en paramètre.
   * \post (m_prenom == p_prenom) : Vérifie que le prénom du propriétaire est bien initialisé avec la valeur passée en paramètre.
   */
  Proprietaire::Proprietaire (const std::string& p_nom, const std::string& p_prenom) : m_nom (p_nom), m_prenom (p_prenom)

  {
    PRECONDITION (!p_nom.empty ());
    PRECONDITION (!p_prenom.empty ());
    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_prenom == p_prenom);
    INVARIANTS ();
  };


  /**
   * \brief constructeur copie, c'est une forme canonique de coplien, il faut faire une copie en profondeur.
   * @param[in] p_proprietaire : Le propriétaire dont on on veut construire une copie.
   * \post (m_nom == p_proprietaire.m_nom) : Vérifie que le nom du propriétaire passé en paramétre a bien été modifié.
   * \post (m_prenom == p_proprietaire.m_prenom) : Vérifie que prénom du propriétaire passé en paramétre a bien été modifié.
   */
  Proprietaire::Proprietaire (const Proprietaire& p_proprietaire) : m_nom (p_proprietaire.m_nom), m_prenom (p_proprietaire.m_prenom)

  {
    for (auto & element : p_proprietaire.m_vehicules)

      {
        ajouterVehicule (*element);
      }
    POSTCONDITION (m_nom == p_proprietaire.m_nom);
    POSTCONDITION (m_prenom == p_proprietaire.m_prenom);


  }


  /**
   *\brief Cette méthode est un opérateur d'assignation permettant de copier l'objet p_proprietaire dans l'objet courant.
   * @param[in] p_proprietaire : un objet Proprietaire qui est passé par référence constante.
   * @return un pointeur vers l'objet courant pour les appels en cascade.
   */
  Proprietaire& Proprietaire::operator= (const Proprietaire& p_proprietaire)

  {
    if (!(this == & p_proprietaire))

      {
        m_nom = p_proprietaire.m_nom;
        m_prenom = p_proprietaire.m_prenom;
        m_vehicules.clear ();

        for (auto& element : p_proprietaire.m_vehicules)
          {
            ajouterVehicule (*element);
          }
        POSTCONDITION (m_nom == p_proprietaire.m_nom);
        POSTCONDITION (m_prenom == p_proprietaire.m_prenom);

      }
    return *this;

  }


  /**
   * \brief Accesseur pour le nom du propriétaire.
   * @return string : Le nom du propriétaire.
   */
  std::string
  Proprietaire::reqNom () const

  {
    return m_nom;

  }


  /**
   * \brief Accesseur pour  le prénom du propriétaire.
   * @return string : Le prénom du propriétaire.
   */
  std::string
  Proprietaire::reqPrenom () const
  {
    return m_prenom;
  }


  /**
   * \brief Cette méthode retourne le nombre de véhicules que possède un propriétaire.
   * @return int : Le nombre de véhicules du propriétaire.
   */
  int
  Proprietaire::reqnbVehicules () const
  {
    int compteur = 0;

    for (auto& element : m_vehicules)
      {
        compteur++;
      }

    return compteur;
  }


  /**
   * \brief Cette méthode permet d'ajouter un véhicule à un propriétaire en faisant une copie allouée sur le monceau.
   * @param[in] p_nouveauVehicule : le véhicule à ajouter.
   */
  void
  Proprietaire::ajouterVehicule (const Vehicule& p_nouveauVehicule)

  {

    m_vehicules.push_back (p_nouveauVehicule.clone ());
  }


  /**
   * \brief Cette méthode convertit les données du propriétaire dans une chaîne de caractères formatée.
   * \return string : la chaîne de caractères formatée contenant les informations du propriétaire.
   */
  std::string
  Proprietaire::reqProprietaireFormate () const
  {
    ostringstream os;
    os << "Proprietaire" << endl;
    os << "Nom      : " << reqNom () << endl;
    os << "Prénom   : " << reqPrenom () << endl;

    for (const auto & element : m_vehicules)
      {
        os << "--------------" << endl <<  element->reqVehiculeFormate ()  << endl;
      }

    return os.str ();
  }


  /* \brief Cette méthode vérifie que tous les invariants de la classe Propriétaire sont respectés.
   */
  void
  Proprietaire::verifieInvariant () const
  {

    INVARIANT (!m_nom.empty ());
    INVARIANT (!m_prenom.empty ());
  }


  /**
   * \brief Destructeur de la classe Proprietaire.
   */
  Proprietaire::~Proprietaire () { }

}; /* namesapace saaq */















