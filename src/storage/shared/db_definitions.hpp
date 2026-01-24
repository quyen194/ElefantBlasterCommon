/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/21 05:18
  filename:  ElefantBlaster/ElefantBlasterCommon/storage/shared/db_definitions.hpp

  purpose:   Common definitions for database
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_STORAGE_SHARED_DB_DEFINITIONS_HPP
#define ELEFANT_BLASTER_COMMON_STORAGE_SHARED_DB_DEFINITIONS_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <cstdint>
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

namespace _SortBy {
  enum T : uint32_t {
    kNone,
    kAsc,
    kDesc,
  };
}
typedef _SortBy::T SortBy;
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_STORAGE_SHARED_DB_DEFINITIONS_HPP
// -----------------------------------------------------------------------------
