/**
 * \file:   VehiculePromenade.h
 * @brief Interface de la classe VehiculePromenade
 * \author: El hadji Nimaga
 */
#include"Vehicule.h"
#ifndef VEHICULEPROMENADE_H
#define VEHICULEPROMENADE_H
#include <string>

namespace saaq
{

  /**
   * \class VehiculePromenade
   * \brief Cette classe permet de gérer les vehicules de type promenade. Elle hérite de la classe Vehicule.
   */

  class VehiculePromenade : public saaq::Vehicule
  {
  public:

    VehiculePromenade (const std::string& p_niv, const std::string& p_immatriculation, const int& p_nbPlaces);

    virtual std::string reqVehiculeFormate () const;
    virtual void asgImmatriculation (const std::string& nouveauImmatriculation);

    virtual double tarificationAnnuelle () const;

    int reqnbPlaces () const;

    virtual ~VehiculePromenade ();

    virtual std::unique_ptr<Vehicule> clone ()const;

  private:
    int m_nbPlaces;
    void verifieInvariant () const;

  };
}

#endif /* VEHICULEPROMENADE_H */

