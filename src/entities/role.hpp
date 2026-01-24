/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/18 06:00
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/role.hpp

  purpose:
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_ENTITIES_ROLE_HPP
#define ELEFANT_BLASTER_COMMON_ENTITIES_ROLE_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <cstdint>
#include <string>
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

struct Role {
  std::uint64_t id = 0;
  bool is_system = false;
  std::string name;
  std::string display_name;
  std::string desc;
  bool is_actived = false;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_ROLE_HPP
// -----------------------------------------------------------------------------
