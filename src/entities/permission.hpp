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
#include <map>
#include <string>
#include <string_view>

#include <aries_base/utils/get_default.hpp>

#include "entities/permission_name.hpp"
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
using namespace aries_base;
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
namespace _RiskLevel {
  enum T {
    kUnknown,
    kLow,
    kMedium,
    kHigh,
  };
}
typedef _RiskLevel::T RiskLevel;
// -----------------------------------------------------------------------------
inline const std::string ToString(const RiskLevel e) {
  static const std::map<RiskLevel, std::string> kMap = {
      {RiskLevel::kUnknown, "Unknown"},
      {RiskLevel::kLow, "Low"},
      {RiskLevel::kMedium, "Medium"},
      {RiskLevel::kHigh, "High"},
  };

  return utils::GetDefault(kMap, e, std::string("Unknown"));
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

struct DefPermission {
  RiskLevel risk = RiskLevel::kUnknown;
  std::string_view name;
  std::string_view desc;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

struct Permission {
  RiskLevel risk = RiskLevel::kUnknown;
  std::string name;
  std::string desc;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_HPP
// -----------------------------------------------------------------------------
