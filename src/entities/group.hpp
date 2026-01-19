/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/18 07:54
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/group.hpp

  purpose:   Header file for group entity
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_ENTITIES_GROUP_HPP
#define ELEFANT_BLASTER_COMMON_ENTITIES_GROUP_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <string>
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

struct Group {
  bool is_system;
  std::string name;
  std::string display_name;
  std::string desc;
  bool is_actived;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_GROUP_HPP
// -----------------------------------------------------------------------------
