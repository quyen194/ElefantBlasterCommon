/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/07 19:48
  filename:  ElefantBlaster/ElefantBlasterCommon/network/shared/msg_header.hpp

  purpose:   Message header definition
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_NETWORK_SHARED_MSG_HEADER_HPP
#define ELEFANT_BLASTER_COMMON_NETWORK_SHARED_MSG_HEADER_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <cstdint>

#include <aries_base/definitions/macro.hpp>
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#define MAGIC_NUMBER 0xFF6E
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

struct MessageHeader {
 public:
  MessageHeader(uint16_t protocol_version, uint8_t _head, uint8_t _sub, uint16_t _size) {
    magic_number_l = LO_WORD(MAGIC_NUMBER);
    magic_number_h = HI_WORD(MAGIC_NUMBER);
    protocol_version_l = LO_WORD(protocol_version);
    protocol_version_h = HI_WORD(protocol_version);
    size_l = LO_WORD(_size);
    size_h = HI_WORD(_size);
    head = _head;
    sub = _sub;
  };

  alignas(1) uint8_t magic_number_l;
  alignas(1) uint8_t magic_number_h;
  alignas(1) uint8_t protocol_version_l;
  alignas(1) uint8_t protocol_version_h;
  alignas(1) uint8_t size_l;
  alignas(1) uint8_t size_h;
  alignas(1) uint8_t head;
  alignas(1) uint8_t sub;
  alignas(1) uint8_t data[1];
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_NETWORK_SHARED_MSG_HEADER_HPP
// -----------------------------------------------------------------------------
