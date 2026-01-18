/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/18 09:23
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/system_roles.hpp

  purpose:   Header file for system roles
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_ENTITIES_SYSTEM_ROLES_HPP
#define ELEFANT_BLASTER_COMMON_ENTITIES_SYSTEM_ROLES_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <string_view>
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
namespace system {
namespace role {
  inline constexpr std::string_view super_admin = "system.super_admin";
  inline constexpr std::string_view server_admin = "system.server_admin";
  inline constexpr std::string_view game_admin = "system.game_admin";
  inline constexpr std::string_view player = "system.player";
  inline constexpr std::string_view guest = "system.guest";
  inline constexpr std::string_view match_owner = "system.match_owner";
} // namespace role
} // namespace system
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_SYSTEM_ROLES_HPP
// -----------------------------------------------------------------------------
