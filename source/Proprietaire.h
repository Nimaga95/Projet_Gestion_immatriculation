/**
 * \file:   Propriétaire.h
 * @brief Interface de la classe Proprietaire
 * \author: El hadji Nimaga
 */
#include "Vehicule.h"
#include <vector>
#include <memory>
#ifndef PROPRIETAIRE_H
#define PROPRIETAIRE_H
namespace saaq
{

  /**
   * \class Proprietaire
   * \brief Cette classe permet de gérer les propriétaires de véhicules.
   */
  class Proprietaire
  {
  public:
    Proprietaire (const std::string& p_nom, const std::string& p_prenom);
    Proprietaire (const Proprietaire& p_proprietaire);
    virtual ~Proprietaire ();

    Proprietaire& operator= (const Proprietaire& p_proprietaire);


    std::string reqNom () const;
    std::string reqPrenom () const;

    int reqnbVehicules () const;

    void ajouterVehicule (const Vehicule& p_nouveauVehicule);

    std::string reqProprietaireFormate () const;


  private:

    std::string m_nom;
    std::string m_prenom;
    std::vector<std::unique_ptr<Vehicule>> m_vehicules;
    virtual void verifieInvariant () const;
  };
}
#endif /* PROPRIETAIRE_H */

