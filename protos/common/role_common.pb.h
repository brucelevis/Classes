// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/role_common.proto

#ifndef PROTOBUF_common_2frole_5fcommon_2eproto__INCLUDED
#define PROTOBUF_common_2frole_5fcommon_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protos {
namespace common {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_common_2frole_5fcommon_2eproto();
void protobuf_AssignDesc_common_2frole_5fcommon_2eproto();
void protobuf_ShutdownFile_common_2frole_5fcommon_2eproto();

class Role;

// ===================================================================

class Role : public ::google::protobuf::Message {
 public:
  Role();
  virtual ~Role();

  Role(const Role& from);

  inline Role& operator=(const Role& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Role& default_instance();

  void Swap(Role* other);

  // implements Message ----------------------------------------------

  Role* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Role& from);
  void MergeFrom(const Role& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 roleId = 1;
  inline bool has_roleid() const;
  inline void clear_roleid();
  static const int kRoleIdFieldNumber = 1;
  inline ::google::protobuf::int32 roleid() const;
  inline void set_roleid(::google::protobuf::int32 value);

  // optional string roleName = 2;
  inline bool has_rolename() const;
  inline void clear_rolename();
  static const int kRoleNameFieldNumber = 2;
  inline const ::std::string& rolename() const;
  inline void set_rolename(const ::std::string& value);
  inline void set_rolename(const char* value);
  inline void set_rolename(const char* value, size_t size);
  inline ::std::string* mutable_rolename();
  inline ::std::string* release_rolename();
  inline void set_allocated_rolename(::std::string* rolename);

  // optional int32 roleLv = 3;
  inline bool has_rolelv() const;
  inline void clear_rolelv();
  static const int kRoleLvFieldNumber = 3;
  inline ::google::protobuf::int32 rolelv() const;
  inline void set_rolelv(::google::protobuf::int32 value);

  // optional int32 roleNation = 4;
  inline bool has_rolenation() const;
  inline void clear_rolenation();
  static const int kRoleNationFieldNumber = 4;
  inline ::google::protobuf::int32 rolenation() const;
  inline void set_rolenation(::google::protobuf::int32 value);

  // optional int32 vip = 17;
  inline bool has_vip() const;
  inline void clear_vip();
  static const int kVipFieldNumber = 17;
  inline ::google::protobuf::int32 vip() const;
  inline void set_vip(::google::protobuf::int32 value);

  // optional int32 combat = 16;
  inline bool has_combat() const;
  inline void clear_combat();
  static const int kCombatFieldNumber = 16;
  inline ::google::protobuf::int32 combat() const;
  inline void set_combat(::google::protobuf::int32 value);

  // optional int32 thumb = 20;
  inline bool has_thumb() const;
  inline void clear_thumb();
  static const int kThumbFieldNumber = 20;
  inline ::google::protobuf::int32 thumb() const;
  inline void set_thumb(::google::protobuf::int32 value);

  // optional string fbId = 5;
  inline bool has_fbid() const;
  inline void clear_fbid();
  static const int kFbIdFieldNumber = 5;
  inline const ::std::string& fbid() const;
  inline void set_fbid(const ::std::string& value);
  inline void set_fbid(const char* value);
  inline void set_fbid(const char* value, size_t size);
  inline ::std::string* mutable_fbid();
  inline ::std::string* release_fbid();
  inline void set_allocated_fbid(::std::string* fbid);

  // optional int32 roleExp = 10;
  inline bool has_roleexp() const;
  inline void clear_roleexp();
  static const int kRoleExpFieldNumber = 10;
  inline ::google::protobuf::int32 roleexp() const;
  inline void set_roleexp(::google::protobuf::int32 value);

  // optional int32 nextExp = 12;
  inline bool has_nextexp() const;
  inline void clear_nextexp();
  static const int kNextExpFieldNumber = 12;
  inline ::google::protobuf::int32 nextexp() const;
  inline void set_nextexp(::google::protobuf::int32 value);

  // optional int32 roleCoin = 11;
  inline bool has_rolecoin() const;
  inline void clear_rolecoin();
  static const int kRoleCoinFieldNumber = 11;
  inline ::google::protobuf::int32 rolecoin() const;
  inline void set_rolecoin(::google::protobuf::int32 value);

  // optional int32 roleGold = 14;
  inline bool has_rolegold() const;
  inline void clear_rolegold();
  static const int kRoleGoldFieldNumber = 14;
  inline ::google::protobuf::int32 rolegold() const;
  inline void set_rolegold(::google::protobuf::int32 value);

  // optional int32 roleFood = 15;
  inline bool has_rolefood() const;
  inline void clear_rolefood();
  static const int kRoleFoodFieldNumber = 15;
  inline ::google::protobuf::int32 rolefood() const;
  inline void set_rolefood(::google::protobuf::int32 value);

  // optional int32 roleFCoin = 18;
  inline bool has_rolefcoin() const;
  inline void clear_rolefcoin();
  static const int kRoleFCoinFieldNumber = 18;
  inline ::google::protobuf::int32 rolefcoin() const;
  inline void set_rolefcoin(::google::protobuf::int32 value);

  // optional int32 roleAction = 13;
  inline bool has_roleaction() const;
  inline void clear_roleaction();
  static const int kRoleActionFieldNumber = 13;
  inline ::google::protobuf::int32 roleaction() const;
  inline void set_roleaction(::google::protobuf::int32 value);

  // optional int32 actionLimit = 19;
  inline bool has_actionlimit() const;
  inline void clear_actionlimit();
  static const int kActionLimitFieldNumber = 19;
  inline ::google::protobuf::int32 actionlimit() const;
  inline void set_actionlimit(::google::protobuf::int32 value);

  // optional fixed64 actionTime = 21;
  inline bool has_actiontime() const;
  inline void clear_actiontime();
  static const int kActionTimeFieldNumber = 21;
  inline ::google::protobuf::uint64 actiontime() const;
  inline void set_actiontime(::google::protobuf::uint64 value);

  // optional int32 interval = 23;
  inline bool has_interval() const;
  inline void clear_interval();
  static const int kIntervalFieldNumber = 23;
  inline ::google::protobuf::int32 interval() const;
  inline void set_interval(::google::protobuf::int32 value);

  // optional int32 newerStep = 24;
  inline bool has_newerstep() const;
  inline void clear_newerstep();
  static const int kNewerStepFieldNumber = 24;
  inline ::google::protobuf::int32 newerstep() const;
  inline void set_newerstep(::google::protobuf::int32 value);

  // optional bool mobileShop = 25;
  inline bool has_mobileshop() const;
  inline void clear_mobileshop();
  static const int kMobileShopFieldNumber = 25;
  inline bool mobileshop() const;
  inline void set_mobileshop(bool value);

  // optional int32 inviteFriend = 26;
  inline bool has_invitefriend() const;
  inline void clear_invitefriend();
  static const int kInviteFriendFieldNumber = 26;
  inline ::google::protobuf::int32 invitefriend() const;
  inline void set_invitefriend(::google::protobuf::int32 value);

  // optional bool firstLogin = 27;
  inline bool has_firstlogin() const;
  inline void clear_firstlogin();
  static const int kFirstLoginFieldNumber = 27;
  inline bool firstlogin() const;
  inline void set_firstlogin(bool value);

  // @@protoc_insertion_point(class_scope:protos.common.Role)
 private:
  inline void set_has_roleid();
  inline void clear_has_roleid();
  inline void set_has_rolename();
  inline void clear_has_rolename();
  inline void set_has_rolelv();
  inline void clear_has_rolelv();
  inline void set_has_rolenation();
  inline void clear_has_rolenation();
  inline void set_has_vip();
  inline void clear_has_vip();
  inline void set_has_combat();
  inline void clear_has_combat();
  inline void set_has_thumb();
  inline void clear_has_thumb();
  inline void set_has_fbid();
  inline void clear_has_fbid();
  inline void set_has_roleexp();
  inline void clear_has_roleexp();
  inline void set_has_nextexp();
  inline void clear_has_nextexp();
  inline void set_has_rolecoin();
  inline void clear_has_rolecoin();
  inline void set_has_rolegold();
  inline void clear_has_rolegold();
  inline void set_has_rolefood();
  inline void clear_has_rolefood();
  inline void set_has_rolefcoin();
  inline void clear_has_rolefcoin();
  inline void set_has_roleaction();
  inline void clear_has_roleaction();
  inline void set_has_actionlimit();
  inline void clear_has_actionlimit();
  inline void set_has_actiontime();
  inline void clear_has_actiontime();
  inline void set_has_interval();
  inline void clear_has_interval();
  inline void set_has_newerstep();
  inline void clear_has_newerstep();
  inline void set_has_mobileshop();
  inline void clear_has_mobileshop();
  inline void set_has_invitefriend();
  inline void clear_has_invitefriend();
  inline void set_has_firstlogin();
  inline void clear_has_firstlogin();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* rolename_;
  ::google::protobuf::int32 roleid_;
  ::google::protobuf::int32 rolelv_;
  ::google::protobuf::int32 rolenation_;
  ::google::protobuf::int32 vip_;
  ::google::protobuf::int32 combat_;
  ::google::protobuf::int32 thumb_;
  ::std::string* fbid_;
  ::google::protobuf::int32 roleexp_;
  ::google::protobuf::int32 nextexp_;
  ::google::protobuf::int32 rolecoin_;
  ::google::protobuf::int32 rolegold_;
  ::google::protobuf::int32 rolefood_;
  ::google::protobuf::int32 rolefcoin_;
  ::google::protobuf::int32 roleaction_;
  ::google::protobuf::int32 actionlimit_;
  ::google::protobuf::uint64 actiontime_;
  ::google::protobuf::int32 interval_;
  ::google::protobuf::int32 newerstep_;
  ::google::protobuf::int32 invitefriend_;
  bool mobileshop_;
  bool firstlogin_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(22 + 31) / 32];

  friend void  protobuf_AddDesc_common_2frole_5fcommon_2eproto();
  friend void protobuf_AssignDesc_common_2frole_5fcommon_2eproto();
  friend void protobuf_ShutdownFile_common_2frole_5fcommon_2eproto();

  void InitAsDefaultInstance();
  static Role* default_instance_;
};
// ===================================================================


// ===================================================================

// Role

// required int32 roleId = 1;
inline bool Role::has_roleid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Role::set_has_roleid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Role::clear_has_roleid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Role::clear_roleid() {
  roleid_ = 0;
  clear_has_roleid();
}
inline ::google::protobuf::int32 Role::roleid() const {
  return roleid_;
}
inline void Role::set_roleid(::google::protobuf::int32 value) {
  set_has_roleid();
  roleid_ = value;
}

// optional string roleName = 2;
inline bool Role::has_rolename() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Role::set_has_rolename() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Role::clear_has_rolename() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Role::clear_rolename() {
  if (rolename_ != &::google::protobuf::internal::kEmptyString) {
    rolename_->clear();
  }
  clear_has_rolename();
}
inline const ::std::string& Role::rolename() const {
  return *rolename_;
}
inline void Role::set_rolename(const ::std::string& value) {
  set_has_rolename();
  if (rolename_ == &::google::protobuf::internal::kEmptyString) {
    rolename_ = new ::std::string;
  }
  rolename_->assign(value);
}
inline void Role::set_rolename(const char* value) {
  set_has_rolename();
  if (rolename_ == &::google::protobuf::internal::kEmptyString) {
    rolename_ = new ::std::string;
  }
  rolename_->assign(value);
}
inline void Role::set_rolename(const char* value, size_t size) {
  set_has_rolename();
  if (rolename_ == &::google::protobuf::internal::kEmptyString) {
    rolename_ = new ::std::string;
  }
  rolename_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Role::mutable_rolename() {
  set_has_rolename();
  if (rolename_ == &::google::protobuf::internal::kEmptyString) {
    rolename_ = new ::std::string;
  }
  return rolename_;
}
inline ::std::string* Role::release_rolename() {
  clear_has_rolename();
  if (rolename_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = rolename_;
    rolename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Role::set_allocated_rolename(::std::string* rolename) {
  if (rolename_ != &::google::protobuf::internal::kEmptyString) {
    delete rolename_;
  }
  if (rolename) {
    set_has_rolename();
    rolename_ = rolename;
  } else {
    clear_has_rolename();
    rolename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 roleLv = 3;
inline bool Role::has_rolelv() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Role::set_has_rolelv() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Role::clear_has_rolelv() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Role::clear_rolelv() {
  rolelv_ = 0;
  clear_has_rolelv();
}
inline ::google::protobuf::int32 Role::rolelv() const {
  return rolelv_;
}
inline void Role::set_rolelv(::google::protobuf::int32 value) {
  set_has_rolelv();
  rolelv_ = value;
}

// optional int32 roleNation = 4;
inline bool Role::has_rolenation() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Role::set_has_rolenation() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Role::clear_has_rolenation() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Role::clear_rolenation() {
  rolenation_ = 0;
  clear_has_rolenation();
}
inline ::google::protobuf::int32 Role::rolenation() const {
  return rolenation_;
}
inline void Role::set_rolenation(::google::protobuf::int32 value) {
  set_has_rolenation();
  rolenation_ = value;
}

// optional int32 vip = 17;
inline bool Role::has_vip() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Role::set_has_vip() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Role::clear_has_vip() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Role::clear_vip() {
  vip_ = 0;
  clear_has_vip();
}
inline ::google::protobuf::int32 Role::vip() const {
  return vip_;
}
inline void Role::set_vip(::google::protobuf::int32 value) {
  set_has_vip();
  vip_ = value;
}

// optional int32 combat = 16;
inline bool Role::has_combat() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Role::set_has_combat() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Role::clear_has_combat() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Role::clear_combat() {
  combat_ = 0;
  clear_has_combat();
}
inline ::google::protobuf::int32 Role::combat() const {
  return combat_;
}
inline void Role::set_combat(::google::protobuf::int32 value) {
  set_has_combat();
  combat_ = value;
}

// optional int32 thumb = 20;
inline bool Role::has_thumb() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Role::set_has_thumb() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Role::clear_has_thumb() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Role::clear_thumb() {
  thumb_ = 0;
  clear_has_thumb();
}
inline ::google::protobuf::int32 Role::thumb() const {
  return thumb_;
}
inline void Role::set_thumb(::google::protobuf::int32 value) {
  set_has_thumb();
  thumb_ = value;
}

// optional string fbId = 5;
inline bool Role::has_fbid() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Role::set_has_fbid() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Role::clear_has_fbid() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Role::clear_fbid() {
  if (fbid_ != &::google::protobuf::internal::kEmptyString) {
    fbid_->clear();
  }
  clear_has_fbid();
}
inline const ::std::string& Role::fbid() const {
  return *fbid_;
}
inline void Role::set_fbid(const ::std::string& value) {
  set_has_fbid();
  if (fbid_ == &::google::protobuf::internal::kEmptyString) {
    fbid_ = new ::std::string;
  }
  fbid_->assign(value);
}
inline void Role::set_fbid(const char* value) {
  set_has_fbid();
  if (fbid_ == &::google::protobuf::internal::kEmptyString) {
    fbid_ = new ::std::string;
  }
  fbid_->assign(value);
}
inline void Role::set_fbid(const char* value, size_t size) {
  set_has_fbid();
  if (fbid_ == &::google::protobuf::internal::kEmptyString) {
    fbid_ = new ::std::string;
  }
  fbid_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Role::mutable_fbid() {
  set_has_fbid();
  if (fbid_ == &::google::protobuf::internal::kEmptyString) {
    fbid_ = new ::std::string;
  }
  return fbid_;
}
inline ::std::string* Role::release_fbid() {
  clear_has_fbid();
  if (fbid_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = fbid_;
    fbid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Role::set_allocated_fbid(::std::string* fbid) {
  if (fbid_ != &::google::protobuf::internal::kEmptyString) {
    delete fbid_;
  }
  if (fbid) {
    set_has_fbid();
    fbid_ = fbid;
  } else {
    clear_has_fbid();
    fbid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 roleExp = 10;
inline bool Role::has_roleexp() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Role::set_has_roleexp() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Role::clear_has_roleexp() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Role::clear_roleexp() {
  roleexp_ = 0;
  clear_has_roleexp();
}
inline ::google::protobuf::int32 Role::roleexp() const {
  return roleexp_;
}
inline void Role::set_roleexp(::google::protobuf::int32 value) {
  set_has_roleexp();
  roleexp_ = value;
}

// optional int32 nextExp = 12;
inline bool Role::has_nextexp() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void Role::set_has_nextexp() {
  _has_bits_[0] |= 0x00000200u;
}
inline void Role::clear_has_nextexp() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void Role::clear_nextexp() {
  nextexp_ = 0;
  clear_has_nextexp();
}
inline ::google::protobuf::int32 Role::nextexp() const {
  return nextexp_;
}
inline void Role::set_nextexp(::google::protobuf::int32 value) {
  set_has_nextexp();
  nextexp_ = value;
}

// optional int32 roleCoin = 11;
inline bool Role::has_rolecoin() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void Role::set_has_rolecoin() {
  _has_bits_[0] |= 0x00000400u;
}
inline void Role::clear_has_rolecoin() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void Role::clear_rolecoin() {
  rolecoin_ = 0;
  clear_has_rolecoin();
}
inline ::google::protobuf::int32 Role::rolecoin() const {
  return rolecoin_;
}
inline void Role::set_rolecoin(::google::protobuf::int32 value) {
  set_has_rolecoin();
  rolecoin_ = value;
}

// optional int32 roleGold = 14;
inline bool Role::has_rolegold() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void Role::set_has_rolegold() {
  _has_bits_[0] |= 0x00000800u;
}
inline void Role::clear_has_rolegold() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void Role::clear_rolegold() {
  rolegold_ = 0;
  clear_has_rolegold();
}
inline ::google::protobuf::int32 Role::rolegold() const {
  return rolegold_;
}
inline void Role::set_rolegold(::google::protobuf::int32 value) {
  set_has_rolegold();
  rolegold_ = value;
}

// optional int32 roleFood = 15;
inline bool Role::has_rolefood() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void Role::set_has_rolefood() {
  _has_bits_[0] |= 0x00001000u;
}
inline void Role::clear_has_rolefood() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void Role::clear_rolefood() {
  rolefood_ = 0;
  clear_has_rolefood();
}
inline ::google::protobuf::int32 Role::rolefood() const {
  return rolefood_;
}
inline void Role::set_rolefood(::google::protobuf::int32 value) {
  set_has_rolefood();
  rolefood_ = value;
}

// optional int32 roleFCoin = 18;
inline bool Role::has_rolefcoin() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void Role::set_has_rolefcoin() {
  _has_bits_[0] |= 0x00002000u;
}
inline void Role::clear_has_rolefcoin() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void Role::clear_rolefcoin() {
  rolefcoin_ = 0;
  clear_has_rolefcoin();
}
inline ::google::protobuf::int32 Role::rolefcoin() const {
  return rolefcoin_;
}
inline void Role::set_rolefcoin(::google::protobuf::int32 value) {
  set_has_rolefcoin();
  rolefcoin_ = value;
}

// optional int32 roleAction = 13;
inline bool Role::has_roleaction() const {
  return (_has_bits_[0] & 0x00004000u) != 0;
}
inline void Role::set_has_roleaction() {
  _has_bits_[0] |= 0x00004000u;
}
inline void Role::clear_has_roleaction() {
  _has_bits_[0] &= ~0x00004000u;
}
inline void Role::clear_roleaction() {
  roleaction_ = 0;
  clear_has_roleaction();
}
inline ::google::protobuf::int32 Role::roleaction() const {
  return roleaction_;
}
inline void Role::set_roleaction(::google::protobuf::int32 value) {
  set_has_roleaction();
  roleaction_ = value;
}

// optional int32 actionLimit = 19;
inline bool Role::has_actionlimit() const {
  return (_has_bits_[0] & 0x00008000u) != 0;
}
inline void Role::set_has_actionlimit() {
  _has_bits_[0] |= 0x00008000u;
}
inline void Role::clear_has_actionlimit() {
  _has_bits_[0] &= ~0x00008000u;
}
inline void Role::clear_actionlimit() {
  actionlimit_ = 0;
  clear_has_actionlimit();
}
inline ::google::protobuf::int32 Role::actionlimit() const {
  return actionlimit_;
}
inline void Role::set_actionlimit(::google::protobuf::int32 value) {
  set_has_actionlimit();
  actionlimit_ = value;
}

// optional fixed64 actionTime = 21;
inline bool Role::has_actiontime() const {
  return (_has_bits_[0] & 0x00010000u) != 0;
}
inline void Role::set_has_actiontime() {
  _has_bits_[0] |= 0x00010000u;
}
inline void Role::clear_has_actiontime() {
  _has_bits_[0] &= ~0x00010000u;
}
inline void Role::clear_actiontime() {
  actiontime_ = GOOGLE_ULONGLONG(0);
  clear_has_actiontime();
}
inline ::google::protobuf::uint64 Role::actiontime() const {
  return actiontime_;
}
inline void Role::set_actiontime(::google::protobuf::uint64 value) {
  set_has_actiontime();
  actiontime_ = value;
}

// optional int32 interval = 23;
inline bool Role::has_interval() const {
  return (_has_bits_[0] & 0x00020000u) != 0;
}
inline void Role::set_has_interval() {
  _has_bits_[0] |= 0x00020000u;
}
inline void Role::clear_has_interval() {
  _has_bits_[0] &= ~0x00020000u;
}
inline void Role::clear_interval() {
  interval_ = 0;
  clear_has_interval();
}
inline ::google::protobuf::int32 Role::interval() const {
  return interval_;
}
inline void Role::set_interval(::google::protobuf::int32 value) {
  set_has_interval();
  interval_ = value;
}

// optional int32 newerStep = 24;
inline bool Role::has_newerstep() const {
  return (_has_bits_[0] & 0x00040000u) != 0;
}
inline void Role::set_has_newerstep() {
  _has_bits_[0] |= 0x00040000u;
}
inline void Role::clear_has_newerstep() {
  _has_bits_[0] &= ~0x00040000u;
}
inline void Role::clear_newerstep() {
  newerstep_ = 0;
  clear_has_newerstep();
}
inline ::google::protobuf::int32 Role::newerstep() const {
  return newerstep_;
}
inline void Role::set_newerstep(::google::protobuf::int32 value) {
  set_has_newerstep();
  newerstep_ = value;
}

// optional bool mobileShop = 25;
inline bool Role::has_mobileshop() const {
  return (_has_bits_[0] & 0x00080000u) != 0;
}
inline void Role::set_has_mobileshop() {
  _has_bits_[0] |= 0x00080000u;
}
inline void Role::clear_has_mobileshop() {
  _has_bits_[0] &= ~0x00080000u;
}
inline void Role::clear_mobileshop() {
  mobileshop_ = false;
  clear_has_mobileshop();
}
inline bool Role::mobileshop() const {
  return mobileshop_;
}
inline void Role::set_mobileshop(bool value) {
  set_has_mobileshop();
  mobileshop_ = value;
}

// optional int32 inviteFriend = 26;
inline bool Role::has_invitefriend() const {
  return (_has_bits_[0] & 0x00100000u) != 0;
}
inline void Role::set_has_invitefriend() {
  _has_bits_[0] |= 0x00100000u;
}
inline void Role::clear_has_invitefriend() {
  _has_bits_[0] &= ~0x00100000u;
}
inline void Role::clear_invitefriend() {
  invitefriend_ = 0;
  clear_has_invitefriend();
}
inline ::google::protobuf::int32 Role::invitefriend() const {
  return invitefriend_;
}
inline void Role::set_invitefriend(::google::protobuf::int32 value) {
  set_has_invitefriend();
  invitefriend_ = value;
}

// optional bool firstLogin = 27;
inline bool Role::has_firstlogin() const {
  return (_has_bits_[0] & 0x00200000u) != 0;
}
inline void Role::set_has_firstlogin() {
  _has_bits_[0] |= 0x00200000u;
}
inline void Role::clear_has_firstlogin() {
  _has_bits_[0] &= ~0x00200000u;
}
inline void Role::clear_firstlogin() {
  firstlogin_ = false;
  clear_has_firstlogin();
}
inline bool Role::firstlogin() const {
  return firstlogin_;
}
inline void Role::set_firstlogin(bool value) {
  set_has_firstlogin();
  firstlogin_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace common
}  // namespace protos

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_common_2frole_5fcommon_2eproto__INCLUDED
