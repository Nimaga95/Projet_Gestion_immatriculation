/**
 * \file:   Vehicule.h
 * @brief Interface de la classe Vehicule
 * \author: El hadji Nimaga
 */
#ifndef VEHICULE_H
#define VEHICULE_H
#include <string>
#include <memory>


namespace saaq
{

  /**
   * \class Vehicule
   * \brief Classe abstraite qui permet de gérer les vehicules.
   */

  class Vehicule
  {
  public:

    Vehicule (const std::string& p_niv, const std::string& p_immatriculation);

    virtual~Vehicule ();


    std::string reqNiv () const;

    std::string reqImmatriculation () const;

    bool operator== (const Vehicule & p_vehicule) const;


    virtual std::unique_ptr<Vehicule> clone () const = 0;

    virtual double tarificationAnnuelle () const = 0;

    virtual std::string reqVehiculeFormate () const;


  protected:

    std::string m_immatriculation;

    virtual void

    asgImmatriculation (const std::string& nouveauImmatriculation) = 0;

  private:

    void verifieInvariant ()const;

    std::string m_niv;


  };

}/* namesapace saaq */
#endif /* VEHICULE_H */


