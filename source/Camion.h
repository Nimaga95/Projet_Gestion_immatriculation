/**
 * \file:   Camion.h
 * @brief Interface de la classe Camion
 * \author: El hadji Nimaga
 */
#include"Vehicule.h"
#ifndef CAMION_H
#define CAMION_H
#include<string>


namespace saaq
{

  /**
   * \class Camion
   * \brief Cette classe permet de gérer les vehicules de type camion. Elle hérite de la classe Vehicule.
   */
  class Camion : public saaq::Vehicule
  {
  public:
    Camion (const std::string& p_niv, const std::string& p_immatriculation, const double& p_poids, const int& p_nbEssieux);

    virtual void asgImmatriculation (const std::string& nouveauImmatriculation);

    virtual std::string reqVehiculeFormate () const;

    double reqPoids () const;
    int reqnbEssieux () const;

    virtual double tarificationAnnuelle () const;

    virtual std::unique_ptr<Vehicule> clone ()const;

    virtual ~Camion ();
  private:
    double m_poids;
    int m_nbEssieux;

    void
    verifieInvariant ()const;

  };
}

#endif /* CAMION_H */

