/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/16 15:28
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/permission.hpp

  purpose:   Header file for permission entity
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_HPP
#define ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <string_view>

#include "entities/permission_name.hpp"
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
namespace _RiskLevel {
  enum T {
    kUnknown,
    Low,
    Medium,
    High,
  };
}
typedef _RiskLevel::T RiskLevel;
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

struct Permission {
  RiskLevel risk = RiskLevel::kUnknown;
  std::string_view name;
  std::string_view desc;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_HPP
// -----------------------------------------------------------------------------
