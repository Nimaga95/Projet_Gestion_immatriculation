#include <string>
#include <iostream>
#include "ValidationFormat.h"
#include "ContratException.h"
#include <gtest/gtest.h>
using namespace util;
using namespace std;


/**
 *
 * Quelques tests pour les fonctions de validation du NIV et Immatriculation
 * Cela ne fait pas pas parti du travail mais je voulais m'assurer que mes fonctions retournent bien les bons résultats.
 */

TEST (ValidationTest, ValiderImmatriculationPromenade_PlaqueValide_ReturnsTrue)
{
  EXPECT_TRUE (util::validerImmatriculationPromenade ("ABC 123"));
}


TEST (ValidationTest, ValiderImmatriculationPromenade_PlaqueAvecEspaceEnFin_ReturnsFalse)
{
  EXPECT_FALSE (util::validerImmatriculationPromenade ("ABC 123 "));
}


TEST (ValidationTest, ValiderImmatriculationPromenade_PlaqueInvalide_ReturnsFalse)
{
  EXPECT_FALSE (util::validerImmatriculationPromenade ("ABC 12"));
}


TEST (ValidationTest, ValiderImmatriculationCamion_PlaqueValide_ReturnsTrue)
{
  EXPECT_TRUE (util::validerImmatriculationCamion ("L123456"));
}


TEST (ValidationTest, ValiderImmatriculationCamion_PlaqueInvalideNonLettreEnDebut_ReturnsFalse)
{
  EXPECT_FALSE (util::validerImmatriculationCamion ("1123456"));
}


TEST (ValidationTest, ValiderImmatriculationCamion_PlaqueInvalidePlusieursLettres_ReturnsFalse)
{
  EXPECT_FALSE (util::validerImmatriculationCamion ("LL12345"));
}


TEST (ValidationTest, ValiderNiv_NIVValide_ReturnsTrue)
{
  EXPECT_TRUE (util::validerNiv ("1M8GDM9AXKP042788"));
}


TEST (ValidationTest, ValiderNiv_NIVInvalideMoinsDe17Caracteres_ReturnsFalse)
{
  EXPECT_FALSE (util::validerNiv ("1M8GDM9AXKP04278"));
}


TEST (ValidationTest, ValiderNiv_NIVInvalidePremiereLettreNonValide_ReturnsFalse)
{
  EXPECT_FALSE (util::validerNiv ("IM8GDM9AXKP04278"));
}