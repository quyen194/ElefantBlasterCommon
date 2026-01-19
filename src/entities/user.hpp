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
#include <time.h>
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

// -----------------------------------------------------------------------------

struct User {
  UserType type;
  std::string username;
  std::string password;
  std::string display_name;
  std::string api_token;
  bool is_banned;
  std::string ban_reason;
  time_t banned_until;
  bool is_actived;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_USER_HPP
// -----------------------------------------------------------------------------
