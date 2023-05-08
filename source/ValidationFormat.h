/*
 * File:   Validation.h
 * Author: etudiant
 *
 * Created on 27 janvier 2023, 06:27
 */

#ifndef VALIDATION_H
#define VALIDATION_H
namespace util
{
  bool
  validerImmatriculationPromenade (const std::string& p_immatriculation);
  bool
  validerImmatriculationCamion (const std::string & p_immatriculation);
  bool
  validerNiv (const std::string & p_niv);
}
#endif /* VALIDATION_H */

