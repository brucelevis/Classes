// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/prop_common.proto

#ifndef PROTOBUF_common_2fprop_5fcommon_2eproto__INCLUDED
#define PROTOBUF_common_2fprop_5fcommon_2eproto__INCLUDED

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
void  protobuf_AddDesc_common_2fprop_5fcommon_2eproto();
void protobuf_AssignDesc_common_2fprop_5fcommon_2eproto();
void protobuf_ShutdownFile_common_2fprop_5fcommon_2eproto();

class Prop;

// ===================================================================

class Prop : public ::google::protobuf::Message {
 public:
  Prop();
  virtual ~Prop();

  Prop(const Prop& from);

  inline Prop& operator=(const Prop& from) {
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
  static const Prop& default_instance();

  void Swap(Prop* other);

  // implements Message ----------------------------------------------

  Prop* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Prop& from);
  void MergeFrom(const Prop& from);
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

  // optional int32 AddType = 1;
  inline bool has_addtype() const;
  inline void clear_addtype();
  static const int kAddTypeFieldNumber = 1;
  inline ::google::protobuf::int32 addtype() const;
  inline void set_addtype(::google::protobuf::int32 value);

  // optional int32 AddVal = 2;
  inline bool has_addval() const;
  inline void clear_addval();
  static const int kAddValFieldNumber = 2;
  inline ::google::protobuf::int32 addval() const;
  inline void set_addval(::google::protobuf::int32 value);

  // optional int32 param = 3;
  inline bool has_param() const;
  inline void clear_param();
  static const int kParamFieldNumber = 3;
  inline ::google::protobuf::int32 param() const;
  inline void set_param(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:protos.common.Prop)
 private:
  inline void set_has_addtype();
  inline void clear_has_addtype();
  inline void set_has_addval();
  inline void clear_has_addval();
  inline void set_has_param();
  inline void clear_has_param();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 addtype_;
  ::google::protobuf::int32 addval_;
  ::google::protobuf::int32 param_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_common_2fprop_5fcommon_2eproto();
  friend void protobuf_AssignDesc_common_2fprop_5fcommon_2eproto();
  friend void protobuf_ShutdownFile_common_2fprop_5fcommon_2eproto();

  void InitAsDefaultInstance();
  static Prop* default_instance_;
};
// ===================================================================


// ===================================================================

// Prop

// optional int32 AddType = 1;
inline bool Prop::has_addtype() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Prop::set_has_addtype() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Prop::clear_has_addtype() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Prop::clear_addtype() {
  addtype_ = 0;
  clear_has_addtype();
}
inline ::google::protobuf::int32 Prop::addtype() const {
  return addtype_;
}
inline void Prop::set_addtype(::google::protobuf::int32 value) {
  set_has_addtype();
  addtype_ = value;
}

// optional int32 AddVal = 2;
inline bool Prop::has_addval() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Prop::set_has_addval() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Prop::clear_has_addval() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Prop::clear_addval() {
  addval_ = 0;
  clear_has_addval();
}
inline ::google::protobuf::int32 Prop::addval() const {
  return addval_;
}
inline void Prop::set_addval(::google::protobuf::int32 value) {
  set_has_addval();
  addval_ = value;
}

// optional int32 param = 3;
inline bool Prop::has_param() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Prop::set_has_param() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Prop::clear_has_param() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Prop::clear_param() {
  param_ = 0;
  clear_has_param();
}
inline ::google::protobuf::int32 Prop::param() const {
  return param_;
}
inline void Prop::set_param(::google::protobuf::int32 value) {
  set_has_param();
  param_ = value;
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

#endif  // PROTOBUF_common_2fprop_5fcommon_2eproto__INCLUDED
