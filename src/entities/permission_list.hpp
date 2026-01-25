/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/16 15:28
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/permission_list.hpp

  purpose:   Header file for permission list
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_LIST_HPP
#define ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_LIST_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <array>
#include <set>
#include <string>
#include <string_view>

#include "entities/permission.hpp"
#include "entities/permission_name.hpp"
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

inline constexpr std::array kPermissions = {
  Permission{ RiskLevel::kHigh, permission::self::all,
              "All permission permissions (FULL ACCESS)" },

  Permission{ RiskLevel::kHigh, permission::self::update_risk,
              "Update permission risk level" },

  Permission{ RiskLevel::kHigh, permission::self::view_high_risk,
              "View high risk permissions" },

  Permission{ RiskLevel::kMedium, permission::self::view_medium_risk,
              "View medium risk permissions" },

  Permission{ RiskLevel::kLow, permission::self::view_low_risk,
              "View low risk permissions" },

  Permission{ RiskLevel::kHigh, permission::admin::all,
              "All admin permissions (FULL ACCESS)" },

  Permission{ RiskLevel::kHigh, permission::user::all,
              "All user permissions (FULL ACCESS)" },

  Permission{ RiskLevel::kHigh, permission::role::all,
              "All role permissions (FULL ACCESS)" },

  Permission{ RiskLevel::kHigh, permission::server::app::all,
              "Full server application control (CRITICAL)" },

  Permission{ RiskLevel::kHigh, permission::server::app::shutdown,
              "Shutdown the server application (CRITICAL)" },

  Permission{ RiskLevel::kHigh, permission::server::app::restart,
              "Restart the server application (CRITICAL)" },

  Permission{ RiskLevel::kHigh, permission::match::update_as_god,
              "Force update match state (GOD MODE)" },

  Permission{ RiskLevel::kHigh, permission::server::game::disconnect_all,
              "Disconnect all game clients" },

  Permission{ RiskLevel::kMedium, permission::admin::create,
              "Create a new admin account" },

  Permission{ RiskLevel::kMedium, permission::admin::del,
              "Delete an admin account" },

  Permission{ RiskLevel::kMedium, permission::admin::update,
              "Update admin account information" },

  Permission{ RiskLevel::kMedium, permission::user::ban,
              "Ban a user account" },

  Permission{ RiskLevel::kMedium, permission::user::unban,
              "Unban a user account" },

  Permission{ RiskLevel::kMedium, permission::user::reset_password,
              "Reset user password" },

  Permission{ RiskLevel::kMedium, permission::usergroup::assign_role,
              "Assign role to a usergroup" },

  Permission{ RiskLevel::kMedium, permission::role::add_permission,
              "Add permission to a role" },

  Permission{ RiskLevel::kMedium, permission::role::remove_permission,
              "Remove permission from a role" },

  Permission{ RiskLevel::kMedium, permission::server::game::maintenance,
              "Put game server into maintenance mode" },

  Permission{ RiskLevel::kMedium, permission::server::game::disconnect_one,
              "Disconnect a single game client" },

  Permission{ RiskLevel::kMedium, permission::match::kick_member,
              "Kick a player from a match" },

  Permission{ RiskLevel::kMedium, permission::map::approve,
              "Approve a custom map" },

  Permission{ RiskLevel::kMedium, permission::map::make_official,
              "Mark a map as official" },

  Permission{ RiskLevel::kLow, permission::admin::view,
              "View admin list" },

  Permission{ RiskLevel::kLow, permission::usergroup::all,
              "All usergroup permissions" },

  Permission{ RiskLevel::kLow, permission::usergroup::create,
              "Create a usergroup" },

  Permission{ RiskLevel::kLow, permission::usergroup::del,
              "Delete a usergroup" },

  Permission{ RiskLevel::kLow, permission::usergroup::view,
              "View usergroup list" },

  Permission{ RiskLevel::kLow, permission::usergroup::add_user,
              "Add user to a usergroup" },

  Permission{ RiskLevel::kLow, permission::usergroup::remove_user,
              "Remove user from a usergroup" },

  Permission{ RiskLevel::kLow, permission::user::create,
              "Create a user account" },

  Permission{ RiskLevel::kLow, permission::user::del,
              "Delete a user account" },

  Permission{ RiskLevel::kLow, permission::user::view,
              "View user information" },

  Permission{ RiskLevel::kLow, permission::user::update,
              "Update user information" },

  Permission{ RiskLevel::kLow, permission::user::assign_role,
              "Assign role to a user" },

  Permission{ RiskLevel::kLow, permission::role::create,
              "Create a role" },

  Permission{ RiskLevel::kLow, permission::role::del,
              "Delete a role" },

  Permission{ RiskLevel::kLow, permission::role::view,
              "View role list" },

  Permission{ RiskLevel::kLow, permission::role::update,
              "Update role information" },

  Permission{ RiskLevel::kLow, permission::server::admin::all,
              "All server admin permissions" },

  Permission{ RiskLevel::kLow, permission::server::admin::view_logs,
              "View server admin logs" },

  Permission{ RiskLevel::kLow, permission::server::game::all,
              "All game server permissions" },

  Permission{ RiskLevel::kLow, permission::server::game::activate,
              "Activate game server" },

  Permission{ RiskLevel::kLow, permission::server::game::deactivate,
              "Deactivate game server" },

  Permission{ RiskLevel::kLow, permission::server::game::view_logs,
              "View game server logs" },

  Permission{ RiskLevel::kLow, permission::match::all,
              "All match permissions" },

  Permission{ RiskLevel::kLow, permission::match::create,
              "Create a match" },

  Permission{ RiskLevel::kLow, permission::match::update,
              "Update match settings" },

  Permission{ RiskLevel::kLow, permission::match::start,
              "Start a match" },

  Permission{ RiskLevel::kLow, permission::match::restart,
              "Restart a match" },

  Permission{ RiskLevel::kLow, permission::match::pause,
              "Pause a match" },

  Permission{ RiskLevel::kLow, permission::match::resume,
              "Resume a match" },

  Permission{ RiskLevel::kLow, permission::match::add_member,
              "Add player to a match" },

  Permission{ RiskLevel::kLow, permission::match::replay,
              "Replay a match" },

  Permission{ RiskLevel::kLow, permission::map::all,
              "All map permissions" },

  Permission{ RiskLevel::kLow, permission::map::create,
              "Create a map" },

  Permission{ RiskLevel::kLow, permission::map::del,
              "Delete a map" },

  Permission{ RiskLevel::kLow, permission::map::view,
              "View map list" },

  Permission{ RiskLevel::kLow, permission::map::update,
              "Update map information" },

  Permission{ RiskLevel::kLow, permission::map::file_export,
              "Export map file" },

  Permission{ RiskLevel::kLow, permission::map::file_import,
              "Import map file" },
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
Permission GetPermission(const std::string_view& name);
bool HasPermission(const std::set<std::string> permissions,
                   const std::string_view permission);
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_LIST_HPP
// -----------------------------------------------------------------------------
