/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/16 15:28
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/permission.hpp

  purpose:
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_HPP
#define ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <array>
#include <cstdint>
#include <string>
#include <string_view>
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Permission Names
namespace permission {

  namespace admin {
    inline constexpr std::string_view all     = "admin.*";
    inline constexpr std::string_view create  = "admin.create";
    inline constexpr std::string_view del     = "admin.delete";
    inline constexpr std::string_view view    = "admin.view";
    inline constexpr std::string_view update  = "admin.update";
  } // namespace admin

  namespace usergroup {
    inline constexpr std::string_view all         = "usergroup.*";
    inline constexpr std::string_view create      = "usergroup.create";
    inline constexpr std::string_view del         = "usergroup.delete";
    inline constexpr std::string_view view        = "usergroup.view";
    inline constexpr std::string_view add_user    = "usergroup.add_user";
    inline constexpr std::string_view remove_user = "usergroup.remove_user";
    inline constexpr std::string_view assign_role = "usergroup.assign_role";
  } // namespace usergroup

  namespace user {
    inline constexpr std::string_view all             = "user.*";
    inline constexpr std::string_view create          = "user.create";
    inline constexpr std::string_view del             = "user.delete";
    inline constexpr std::string_view view            = "user.view";
    inline constexpr std::string_view update          = "user.update";
    inline constexpr std::string_view reset_password  = "user.reset_password";
    inline constexpr std::string_view assign_role     = "user.assign_role";
    inline constexpr std::string_view ban             = "user.ban";
    inline constexpr std::string_view unban           = "user.unban";
  } // namespace user

  namespace role {
    inline constexpr std::string_view all               = "role.*";
    inline constexpr std::string_view create            = "role.create";
    inline constexpr std::string_view del               = "role.delete";
    inline constexpr std::string_view view              = "role.view";
    inline constexpr std::string_view update            = "role.update";
    inline constexpr std::string_view add_permission    = "role.add_permission";
    inline constexpr std::string_view remove_permission = "role.remove_permission";
  } // namespace role

  namespace server {

    namespace app {
      inline constexpr std::string_view all      = "server.app.*";
      inline constexpr std::string_view shutdown = "server.app.shutdown";
      inline constexpr std::string_view restart  = "server.app.restart";
    } // namespace app

    namespace admin {
      inline constexpr std::string_view all       = "server.admin.*";
      inline constexpr std::string_view view_logs = "server.admin.view_logs";
    } // namespace admin

    namespace game {
      inline constexpr std::string_view all             = "server.game.*";
      inline constexpr std::string_view activate        = "server.game.activate";
      inline constexpr std::string_view deactivate      = "server.game.deactivate";
      inline constexpr std::string_view maintenance     = "server.game.maintenance";
      inline constexpr std::string_view disconnect_one  = "server.game.disconnect_one";
      inline constexpr std::string_view disconnect_all  = "server.game.disconnect_all";
      inline constexpr std::string_view view_logs       = "server.game.view_logs";
    } // namespace game
  } // namespace server

  namespace match {
    inline constexpr std::string_view all            = "match.*";

    inline constexpr std::string_view create         = "match.create";
    inline constexpr std::string_view update         = "match.update";
    inline constexpr std::string_view update_as_god  = "match.update_as_god";

    inline constexpr std::string_view start          = "match.start";
    inline constexpr std::string_view restart        = "match.restart";
    inline constexpr std::string_view pause          = "match.pause";
    inline constexpr std::string_view resume         = "match.resume";

    inline constexpr std::string_view add_member     = "match.add_member";
    inline constexpr std::string_view kick_member    = "match.kick_member";

    inline constexpr std::string_view replay         = "match.replay";
  } // namespace match

  namespace map {
    inline constexpr std::string_view all           = "map.*";
    inline constexpr std::string_view create        = "map.create";
    inline constexpr std::string_view del           = "map.delete";
    inline constexpr std::string_view view          = "map.view";
    inline constexpr std::string_view update        = "map.update";
    inline constexpr std::string_view make_official = "map.make_official";
    inline constexpr std::string_view approve       = "map.approve";
    inline constexpr std::string_view file_export   = "map.file_export";
    inline constexpr std::string_view file_import   = "map.file_import";
  } // namespace map

} // namespace permission
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

enum class PermissionRisk {
  Low,
  Medium,
  High,
};
// -----------------------------------------------------------------------------

struct Permission {
  PermissionRisk risk;
  std::string_view name;
  std::string_view desc;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Permission Registry (STATIC METADATA)
inline constexpr auto kPermissions = std::array{

  // ================== HIGH RISK ==================
  Permission{ PermissionRisk::High, permission::admin::all,
              "All admin permissions (FULL ACCESS)" },

  Permission{ PermissionRisk::High, permission::user::all,
              "All user permissions (FULL ACCESS)" },

  Permission{ PermissionRisk::High, permission::role::all,
              "All role permissions (FULL ACCESS)" },

  Permission{ PermissionRisk::High, permission::server::app::all,
              "Full server application control (CRITICAL)" },

  Permission{ PermissionRisk::High, permission::server::app::shutdown,
              "Shutdown the server application (CRITICAL)" },

  Permission{ PermissionRisk::High, permission::server::app::restart,
              "Restart the server application (CRITICAL)" },

  Permission{ PermissionRisk::High, permission::match::update_as_god,
              "Force update match state (GOD MODE)" },

  Permission{ PermissionRisk::High, permission::server::game::disconnect_all,
              "Disconnect all game clients" },

  // ================== MEDIUM RISK ==================
  Permission{ PermissionRisk::Medium, permission::admin::create,
              "Create a new admin account" },

  Permission{ PermissionRisk::Medium, permission::admin::del,
              "Delete an admin account" },

  Permission{ PermissionRisk::Medium, permission::admin::update,
              "Update admin account information" },

  Permission{ PermissionRisk::Medium, permission::user::ban,
              "Ban a user account" },

  Permission{ PermissionRisk::Medium, permission::user::unban,
              "Unban a user account" },

  Permission{ PermissionRisk::Medium, permission::user::reset_password,
              "Reset user password" },

  Permission{ PermissionRisk::Medium, permission::usergroup::assign_role,
              "Assign role to a usergroup" },

  Permission{ PermissionRisk::Medium, permission::role::add_permission,
              "Add permission to a role" },

  Permission{ PermissionRisk::Medium, permission::role::remove_permission,
              "Remove permission from a role" },

  Permission{ PermissionRisk::Medium, permission::server::game::maintenance,
              "Put game server into maintenance mode" },

  Permission{ PermissionRisk::Medium, permission::server::game::disconnect_one,
              "Disconnect a single game client" },

  Permission{ PermissionRisk::Medium, permission::match::kick_member,
              "Kick a player from a match" },

  Permission{ PermissionRisk::Medium, permission::map::approve,
              "Approve a custom map" },

  Permission{ PermissionRisk::Medium, permission::map::make_official,
              "Mark a map as official" },

  // ================== LOW RISK ==================
  Permission{ PermissionRisk::Low, permission::admin::view,
              "View admin list" },

  Permission{ PermissionRisk::Low, permission::usergroup::all,
              "All usergroup permissions" },

  Permission{ PermissionRisk::Low, permission::usergroup::create,
              "Create a usergroup" },

  Permission{ PermissionRisk::Low, permission::usergroup::del,
              "Delete a usergroup" },

  Permission{ PermissionRisk::Low, permission::usergroup::view,
              "View usergroup list" },

  Permission{ PermissionRisk::Low, permission::usergroup::add_user,
              "Add user to a usergroup" },

  Permission{ PermissionRisk::Low, permission::usergroup::remove_user,
              "Remove user from a usergroup" },

  Permission{ PermissionRisk::Low, permission::user::create,
              "Create a user account" },

  Permission{ PermissionRisk::Low, permission::user::del,
              "Delete a user account" },

  Permission{ PermissionRisk::Low, permission::user::view,
              "View user information" },

  Permission{ PermissionRisk::Low, permission::user::update,
              "Update user information" },

  Permission{ PermissionRisk::Low, permission::user::assign_role,
              "Assign role to a user" },

  Permission{ PermissionRisk::Low, permission::role::create,
              "Create a role" },

  Permission{ PermissionRisk::Low, permission::role::del,
              "Delete a role" },

  Permission{ PermissionRisk::Low, permission::role::view,
              "View role list" },

  Permission{ PermissionRisk::Low, permission::role::update,
              "Update role information" },

  Permission{ PermissionRisk::Low, permission::server::admin::all,
              "All server admin permissions" },

  Permission{ PermissionRisk::Low, permission::server::admin::view_logs,
              "View server admin logs" },

  Permission{ PermissionRisk::Low, permission::server::game::all,
              "All game server permissions" },

  Permission{ PermissionRisk::Low, permission::server::game::activate,
              "Activate game server" },

  Permission{ PermissionRisk::Low, permission::server::game::deactivate,
              "Deactivate game server" },

  Permission{ PermissionRisk::Low, permission::server::game::view_logs,
              "View game server logs" },

  Permission{ PermissionRisk::Low, permission::match::all,
              "All match permissions" },

  Permission{ PermissionRisk::Low, permission::match::create,
              "Create a match" },

  Permission{ PermissionRisk::Low, permission::match::update,
              "Update match settings" },

  Permission{ PermissionRisk::Low, permission::match::start,
              "Start a match" },

  Permission{ PermissionRisk::Low, permission::match::restart,
              "Restart a match" },

  Permission{ PermissionRisk::Low, permission::match::pause,
              "Pause a match" },

  Permission{ PermissionRisk::Low, permission::match::resume,
              "Resume a match" },

  Permission{ PermissionRisk::Low, permission::match::add_member,
              "Add player to a match" },

  Permission{ PermissionRisk::Low, permission::match::replay,
              "Replay a match" },

  Permission{ PermissionRisk::Low, permission::map::all,
              "All map permissions" },

  Permission{ PermissionRisk::Low, permission::map::create,
              "Create a map" },

  Permission{ PermissionRisk::Low, permission::map::del,
              "Delete a map" },

  Permission{ PermissionRisk::Low, permission::map::view,
              "View map list" },

  Permission{ PermissionRisk::Low, permission::map::update,
              "Update map information" },

  Permission{ PermissionRisk::Low, permission::map::file_export,
              "Export map file" },

  Permission{ PermissionRisk::Low, permission::map::file_import,
              "Import map file" },
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_HPP
// -----------------------------------------------------------------------------
