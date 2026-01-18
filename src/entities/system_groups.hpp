/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/18 09:37
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/system_groups.hpp

  purpose:   Header file for system groups
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_ENTITIES_SYSTEM_GROUPS_HPP
#define ELEFANT_BLASTER_COMMON_ENTITIES_SYSTEM_GROUPS_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <string_view>
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
namespace system {
namespace group {
  inline constexpr std::string_view server_admins = "system.server_admins";
  inline constexpr std::string_view game_admins = "system.game_admins";
  inline constexpr std::string_view players = "system.players";
  inline constexpr std::string_view guests = "system.guests";
} // namespace role
} // namespace system
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_SYSTEM_GROUPS_HPP
// -----------------------------------------------------------------------------
