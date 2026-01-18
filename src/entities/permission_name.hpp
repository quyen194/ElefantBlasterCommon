/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/16 15:28
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/permission_name.hpp

  purpose:   Header file for permission name
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_NAME_HPP
#define ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_NAME_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <string_view>
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Permission Names
namespace permission {

  namespace self {
    inline constexpr std::string_view all               = "permission.*";
    inline constexpr std::string_view view_high_risk    = "permission.view_high_risk";
    inline constexpr std::string_view view_medium_risk  = "permission.view_medium_risk";
    inline constexpr std::string_view view_low_risk     = "permission.view_low_risk";
    inline constexpr std::string_view update_risk       = "permission.update_risk";
  }

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
#endif  // ELEFANT_BLASTER_COMMON_ENTITIES_PERMISSION_NAME_HPP
// -----------------------------------------------------------------------------
