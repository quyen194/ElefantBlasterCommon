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
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

bool HasPermission(const std::set<std::string>& permissions_list,
                   const std::string_view permission) {
  if (permission.empty() || permissions_list.empty()) {
    return false;
  }

  for (const auto& perm : permissions_list) {
    if (perm == permission) {
      return true;
    }

    if (perm.length() > 1 && perm.back() == '*') {
      if (!permission.compare(0, perm.size() - 1, perm, 0, perm.size() - 1)) {
        return true;
      }
    }
  }

  return false;
}
// -----------------------------------------------------------------------------
