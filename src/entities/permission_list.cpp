/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/17 17:09
  filename:  ElefantBlaster/ElefantBlasterCommon/entities/permission_list.cpp

  purpose:   Implementation file for permission list
*********************************************************************/


// -----------------------------------------------------------------------------
#include "entities/permission_list.hpp"
#include "permission_list.hpp"
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

bool HasPermission(const std::set<std::string> permissions,
                   const std::string_view permission) {
  std::string to_verify_perm(permission);

  if (to_verify_perm.empty() || permissions.size() == 0) {
    return false;
  }

  for (const auto& perm : permissions) {
    if (perm == to_verify_perm) {
      return true;
    }

    if (perm.length() > 1 && perm.back() == '*') {
      std::string prefix_perm = perm.substr(0, perm.size() - 1);

      if (to_verify_perm.compare(0, prefix_perm.size(), prefix_perm) == 0) {
        return true;
      }
    }
  }

  return false;
}
// -----------------------------------------------------------------------------
