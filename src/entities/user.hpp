/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/18 06:33
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/user.hpp

  purpose:   Header file for user entity
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_ENTITIES_USER_HPP
#define ELEFANT_BLASTER_COMMON_ENTITIES_USER_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <cstdint>
#include <string>
#include <map>
#include <time.h>

#include <aries_base/utils/get_default.hpp>
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
using namespace aries_base;
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
namespace _UserType {
  enum T {
    kUnknown,
    kAdmin,
    kPlayer,
  };
}
typedef _UserType::T UserType;
// -----------------------------------------------------------------------------
inline const std::string ToString(const UserType e) {
  static const std::map<UserType, std::string> kMap = {
      {UserType::kUnknown, "Unknown"},
      {UserType::kAdmin, "Admin"},
      {UserType::kPlayer, "Player"},
  };

  return utils::GetDefault(kMap, e, std::string("Unknown"));
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

struct User {
  std::uint64_t id = 0;
  UserType type = UserType::kUnknown;
  std::string username;
  std::string password;
  std::string display_name;
  std::string api_token;
  time_t last_online_at = 0;
  bool is_banned = false;
  std::string ban_reason;
  time_t banned_until = 0;
  bool is_actived = false;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_USER_HPP
// -----------------------------------------------------------------------------
