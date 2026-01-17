/********************************************************************
  Copyright 2026, Cong Quyen Knight. All rights reserved

  project:   Aries Games: Elefant Blaster
  author:    quyen19492
  email:     quyen19492@gmail.com

  created:   2026/01/07 16:13
  filename:  ElefantBlaster/ElefantBlasterCommon/network/shared/msg_manager.hpp

  purpose:   Message manager for handling message buffers
*********************************************************************/


// -----------------------------------------------------------------------------
#ifndef ELEFANT_BLASTER_COMMON_NETWORK_SHARED_MSG_MANAGER_HPP
#define ELEFANT_BLASTER_COMMON_NETWORK_SHARED_MSG_MANAGER_HPP
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#include <cstdint>
#include <cstring>

#include <aries_base/definitions/macro.hpp>
#include <aries_base/utils/bytes.hpp>

#include "network/shared/msg_header.hpp"
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
#define POS_MAGIC_NUMBER 0
#define POS_PROTOCOL_VERSION 2
#define POS_SIZE 4
#define POS_HEAD_CODE 6
#define POS_SUB_CODE 7
#define POS_BODY 8
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
using namespace aries_base;
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message format: FF6F AAAA BBCC DD EE
// FF6F - Magic Number
//        FF - Low Byte
//        6F - High Byte
// AABB - Protocol Version
//        AA - Low Byte
//        BB - High Byte
// CCDD - Size
//        CC - Low Byte
//        DD - High Byte
// EE   - Message Type Head Code
// FF   - Message Type Sub Code
class MessageManager {
 public:
  MessageManager() {
    msg_ = nullptr;
    total_length_ = 0;
    processed_length_ = 0;
  }
  MessageManager(const uint8_t *msg, uint32_t length) {
    Init(msg, length);
  }
  virtual ~MessageManager() {}

  void Init(const uint8_t *msg, uint32_t length) {
    EXPECT_NN0(msg);
    EXPECT_NZ0(length);
    msg_ = (uint8_t *)msg;
    total_length_ = length;
    processed_length_ = 0;
  }

  // length = buff length
  bool isfull() {
    return size() && (processed_length_ + size() <= total_length_);
  }

  // change the pointer to next message
  bool next() {
    if (size() && isfull()) {
      processed_length_ += size();
      return true;
    } else {
      return false;
    }
  }

  // edit messages
  // remove current message
  // after remove, current message is next message, so should not call next()
  bool remove_current_message() {
    // nếu msg hiện tại đã bị removed
    HOPE_LT1(processed_length_, total_length_, false);
    size_t msg_len = size();
    // nếu msg hiện tại ko đầy đủ
    if (msg_len > msg_length_left()) {
      return false;
    }
    // nếu sau msg hiện tại vẫn còn dữ liệu
    if (msg_len < msg_length_left()) {
      memmove(&msg_[processed_length_],
              &msg_[processed_length_ + msg_len],
              total_length_ - processed_length_ - msg_len);
    } else {
      memset(&msg_[processed_length_], 0, msg_len);
    }
    total_length_ -= msg_len;
    return true;
  }

  // after add, current message is next message, so should not call next()
  bool insert_message_after_current(uint32_t max_length,
                                    const uint8_t* message,
                                    uint32_t length) {
    HOPE_LE1(total_length_ + length, max_length, false);
    // case msg hiện tại đã bị removed và ko còn dữ liệu thêm
    if (processed_length_ >= total_length_) {
      memcpy(&msg_[processed_length_], message, length);
      processed_length_ += length;
      total_length_ += length;
      return true;
    }
    // case msg hiện tại thiếu dữ liệu
    size_t msg_len = size();
    if (msg_len > msg_length_left()) {
      return false;
    }
    // case msg hiện tại đủ dữ liệu và là msg cuối
    if (msg_len == msg_length_left()) {
      memcpy(&msg_[processed_length_ + msg_len], message, length);
      processed_length_ += msg_len + length;
      total_length_ += length;
      return true;
    }
    // case msg hiện tại ko phải là msg cuối
    // lưu dữ liệu sau msg hiện tại
    utils::bytes tmpbuff =
        utils::ToBytes(&msg_[processed_length_ + msg_len],
                       total_length_ - (processed_length_ + msg_len));
    // chèn dữ liệu mới vào sau msg hiện tại
    memcpy(&msg_[processed_length_ + msg_len], message, length);
    // nối dữ liệu đã lưu vào sau dữ liệu mới
    memcpy(&msg_[processed_length_ + msg_len + length],
           &tmpbuff[0],
           tmpbuff.size());
    processed_length_ += msg_len + length;
    total_length_ += length;

    return true;
  }

  //  could call next() as normal
  bool insert_message_before_current(uint32_t max_length,
                                     const uint8_t* message,
                                     uint32_t length) {
    EXPECT_LE1(total_length_ + length, max_length, false);
    // case msg hiện tại đã bị removed và ko còn dữ liệu thêm
    if (processed_length_ >= total_length_) {
      memcpy(&msg_[processed_length_], message, length);
      processed_length_ += length;
      total_length_ += length;
      return true;
    }
    // case msg hiện tại vẫn còn
    // lưu msg hiện tại + dữ liệu phía sau msg hiện tại
    utils::bytes tmpbuff = utils::ToBytes(&msg_[processed_length_],
                                          total_length_ - processed_length_);
    // chèn dữ liệu mới vào vị trí msg hiện tại
    memcpy(&msg_[processed_length_], message, length);
    // nối dữ liệu đã lưu vào sau dữ liệu mới
    memcpy(&msg_[processed_length_ + length], &tmpbuff[0], tmpbuff.size());
    total_length_ += length;
    processed_length_ += length;
    return true;
  }

  // sử dụng khi thêm msg nhưng muốn process lại msg đó
  void dec_processed_length(uint32_t len) {
    processed_length_ -= len;
  }

  // get information
  uint32_t processed_length() {
    return processed_length_;
  }

  uint32_t msg_length_left() {
    return total_length_ - processed_length_;
  }

  uint16_t magic_number() {
    return MAKE_WORD(data()[POS_MAGIC_NUMBER], data()[POS_MAGIC_NUMBER + 1]);
  }

  uint16_t protocol_version() {
    return MAKE_WORD(data()[POS_PROTOCOL_VERSION], data()[POS_PROTOCOL_VERSION + 1]);
  }

  // current msg length
  uint32_t size() {
    if (total_length_ - processed_length_ < 8) {
      return 0;
    }
    return MAKE_WORD(data()[POS_SIZE], data()[POS_SIZE + 1]);
  }

  uint8_t head() {
    return body()[0];
  }

  uint8_t sub() {
    return body()[1];
  }

  uint8_t *body() {
    return &data()[POS_BODY];
  }

  uint8_t *data() { return &msg_[processed_length_]; }
  // all data
  uint8_t *data_all() { return msg_; }
  size_t data_all_len() { return total_length_; }

  template <typename T>
  const T obj() {
    return reinterpret_cast<T>(data());
  }

 private:
  static inline uint16_t CODE() { return MAGIC_NUMBER; }

 private:
  uint8_t *msg_;  // point to first byte of message
  uint32_t total_length_;
  uint32_t processed_length_;

 private:
  DISALLOW_COPY_AND_ASSIGN(MessageManager);
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif  // ELEFANT_BLASTER_COMMON_NETWORK_SHARED_MSG_MANAGER_HPP
// -----------------------------------------------------------------------------
