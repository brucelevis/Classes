// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: task_protocol.proto

#ifndef PROTOBUF_task_5fprotocol_2eproto__INCLUDED
#define PROTOBUF_task_5fprotocol_2eproto__INCLUDED

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
#include "common/task_common.pb.h"
#include "common/role_common.pb.h"
#include "common/prize_common.pb.h"
// @@protoc_insertion_point(includes)

namespace protos {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_task_5fprotocol_2eproto();
void protobuf_AssignDesc_task_5fprotocol_2eproto();
void protobuf_ShutdownFile_task_5fprotocol_2eproto();

class TaskListRequest;
class TaskListResponse;
class TaskNotice;
class PrizeRequest;
class PrizeResponse;

// ===================================================================

class TaskListRequest : public ::google::protobuf::Message {
 public:
  TaskListRequest();
  virtual ~TaskListRequest();

  TaskListRequest(const TaskListRequest& from);

  inline TaskListRequest& operator=(const TaskListRequest& from) {
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
  static const TaskListRequest& default_instance();

  void Swap(TaskListRequest* other);

  // implements Message ----------------------------------------------

  TaskListRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TaskListRequest& from);
  void MergeFrom(const TaskListRequest& from);
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

  // optional int32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:protos.TaskListRequest)
 private:
  inline void set_has_type();
  inline void clear_has_type();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_task_5fprotocol_2eproto();
  friend void protobuf_AssignDesc_task_5fprotocol_2eproto();
  friend void protobuf_ShutdownFile_task_5fprotocol_2eproto();

  void InitAsDefaultInstance();
  static TaskListRequest* default_instance_;
};
// -------------------------------------------------------------------

class TaskListResponse : public ::google::protobuf::Message {
 public:
  TaskListResponse();
  virtual ~TaskListResponse();

  TaskListResponse(const TaskListResponse& from);

  inline TaskListResponse& operator=(const TaskListResponse& from) {
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
  static const TaskListResponse& default_instance();

  void Swap(TaskListResponse* other);

  // implements Message ----------------------------------------------

  TaskListResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TaskListResponse& from);
  void MergeFrom(const TaskListResponse& from);
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

  // repeated .protos.common.Task taskList = 1;
  inline int tasklist_size() const;
  inline void clear_tasklist();
  static const int kTaskListFieldNumber = 1;
  inline const ::protos::common::Task& tasklist(int index) const;
  inline ::protos::common::Task* mutable_tasklist(int index);
  inline ::protos::common::Task* add_tasklist();
  inline const ::google::protobuf::RepeatedPtrField< ::protos::common::Task >&
      tasklist() const;
  inline ::google::protobuf::RepeatedPtrField< ::protos::common::Task >*
      mutable_tasklist();

  // optional bool dailyTips = 2;
  inline bool has_dailytips() const;
  inline void clear_dailytips();
  static const int kDailyTipsFieldNumber = 2;
  inline bool dailytips() const;
  inline void set_dailytips(bool value);

  // optional bool mainTips = 3;
  inline bool has_maintips() const;
  inline void clear_maintips();
  static const int kMainTipsFieldNumber = 3;
  inline bool maintips() const;
  inline void set_maintips(bool value);

  // @@protoc_insertion_point(class_scope:protos.TaskListResponse)
 private:
  inline void set_has_dailytips();
  inline void clear_has_dailytips();
  inline void set_has_maintips();
  inline void clear_has_maintips();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::protos::common::Task > tasklist_;
  bool dailytips_;
  bool maintips_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_task_5fprotocol_2eproto();
  friend void protobuf_AssignDesc_task_5fprotocol_2eproto();
  friend void protobuf_ShutdownFile_task_5fprotocol_2eproto();

  void InitAsDefaultInstance();
  static TaskListResponse* default_instance_;
};
// -------------------------------------------------------------------

class TaskNotice : public ::google::protobuf::Message {
 public:
  TaskNotice();
  virtual ~TaskNotice();

  TaskNotice(const TaskNotice& from);

  inline TaskNotice& operator=(const TaskNotice& from) {
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
  static const TaskNotice& default_instance();

  void Swap(TaskNotice* other);

  // implements Message ----------------------------------------------

  TaskNotice* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TaskNotice& from);
  void MergeFrom(const TaskNotice& from);
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

  // required int32 param = 1;
  inline bool has_param() const;
  inline void clear_param();
  static const int kParamFieldNumber = 1;
  inline ::google::protobuf::int32 param() const;
  inline void set_param(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:protos.TaskNotice)
 private:
  inline void set_has_param();
  inline void clear_has_param();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 param_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_task_5fprotocol_2eproto();
  friend void protobuf_AssignDesc_task_5fprotocol_2eproto();
  friend void protobuf_ShutdownFile_task_5fprotocol_2eproto();

  void InitAsDefaultInstance();
  static TaskNotice* default_instance_;
};
// -------------------------------------------------------------------

class PrizeRequest : public ::google::protobuf::Message {
 public:
  PrizeRequest();
  virtual ~PrizeRequest();

  PrizeRequest(const PrizeRequest& from);

  inline PrizeRequest& operator=(const PrizeRequest& from) {
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
  static const PrizeRequest& default_instance();

  void Swap(PrizeRequest* other);

  // implements Message ----------------------------------------------

  PrizeRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PrizeRequest& from);
  void MergeFrom(const PrizeRequest& from);
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

  // required int32 taskId = 1;
  inline bool has_taskid() const;
  inline void clear_taskid();
  static const int kTaskIdFieldNumber = 1;
  inline ::google::protobuf::int32 taskid() const;
  inline void set_taskid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:protos.PrizeRequest)
 private:
  inline void set_has_taskid();
  inline void clear_has_taskid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 taskid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_task_5fprotocol_2eproto();
  friend void protobuf_AssignDesc_task_5fprotocol_2eproto();
  friend void protobuf_ShutdownFile_task_5fprotocol_2eproto();

  void InitAsDefaultInstance();
  static PrizeRequest* default_instance_;
};
// -------------------------------------------------------------------

class PrizeResponse : public ::google::protobuf::Message {
 public:
  PrizeResponse();
  virtual ~PrizeResponse();

  PrizeResponse(const PrizeResponse& from);

  inline PrizeResponse& operator=(const PrizeResponse& from) {
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
  static const PrizeResponse& default_instance();

  void Swap(PrizeResponse* other);

  // implements Message ----------------------------------------------

  PrizeResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PrizeResponse& from);
  void MergeFrom(const PrizeResponse& from);
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

  // required int32 result = 1;
  inline bool has_result() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline ::google::protobuf::int32 result() const;
  inline void set_result(::google::protobuf::int32 value);

  // optional .protos.common.Role role = 2;
  inline bool has_role() const;
  inline void clear_role();
  static const int kRoleFieldNumber = 2;
  inline const ::protos::common::Role& role() const;
  inline ::protos::common::Role* mutable_role();
  inline ::protos::common::Role* release_role();
  inline void set_allocated_role(::protos::common::Role* role);

  // repeated .protos.common.Prize prizes = 3;
  inline int prizes_size() const;
  inline void clear_prizes();
  static const int kPrizesFieldNumber = 3;
  inline const ::protos::common::Prize& prizes(int index) const;
  inline ::protos::common::Prize* mutable_prizes(int index);
  inline ::protos::common::Prize* add_prizes();
  inline const ::google::protobuf::RepeatedPtrField< ::protos::common::Prize >&
      prizes() const;
  inline ::google::protobuf::RepeatedPtrField< ::protos::common::Prize >*
      mutable_prizes();

  // @@protoc_insertion_point(class_scope:protos.PrizeResponse)
 private:
  inline void set_has_result();
  inline void clear_has_result();
  inline void set_has_role();
  inline void clear_has_role();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::protos::common::Role* role_;
  ::google::protobuf::RepeatedPtrField< ::protos::common::Prize > prizes_;
  ::google::protobuf::int32 result_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_task_5fprotocol_2eproto();
  friend void protobuf_AssignDesc_task_5fprotocol_2eproto();
  friend void protobuf_ShutdownFile_task_5fprotocol_2eproto();

  void InitAsDefaultInstance();
  static PrizeResponse* default_instance_;
};
// ===================================================================


// ===================================================================

// TaskListRequest

// optional int32 type = 1;
inline bool TaskListRequest::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TaskListRequest::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TaskListRequest::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TaskListRequest::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 TaskListRequest::type() const {
  return type_;
}
inline void TaskListRequest::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// -------------------------------------------------------------------

// TaskListResponse

// repeated .protos.common.Task taskList = 1;
inline int TaskListResponse::tasklist_size() const {
  return tasklist_.size();
}
inline void TaskListResponse::clear_tasklist() {
  tasklist_.Clear();
}
inline const ::protos::common::Task& TaskListResponse::tasklist(int index) const {
  return tasklist_.Get(index);
}
inline ::protos::common::Task* TaskListResponse::mutable_tasklist(int index) {
  return tasklist_.Mutable(index);
}
inline ::protos::common::Task* TaskListResponse::add_tasklist() {
  return tasklist_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protos::common::Task >&
TaskListResponse::tasklist() const {
  return tasklist_;
}
inline ::google::protobuf::RepeatedPtrField< ::protos::common::Task >*
TaskListResponse::mutable_tasklist() {
  return &tasklist_;
}

// optional bool dailyTips = 2;
inline bool TaskListResponse::has_dailytips() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TaskListResponse::set_has_dailytips() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TaskListResponse::clear_has_dailytips() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TaskListResponse::clear_dailytips() {
  dailytips_ = false;
  clear_has_dailytips();
}
inline bool TaskListResponse::dailytips() const {
  return dailytips_;
}
inline void TaskListResponse::set_dailytips(bool value) {
  set_has_dailytips();
  dailytips_ = value;
}

// optional bool mainTips = 3;
inline bool TaskListResponse::has_maintips() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void TaskListResponse::set_has_maintips() {
  _has_bits_[0] |= 0x00000004u;
}
inline void TaskListResponse::clear_has_maintips() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void TaskListResponse::clear_maintips() {
  maintips_ = false;
  clear_has_maintips();
}
inline bool TaskListResponse::maintips() const {
  return maintips_;
}
inline void TaskListResponse::set_maintips(bool value) {
  set_has_maintips();
  maintips_ = value;
}

// -------------------------------------------------------------------

// TaskNotice

// required int32 param = 1;
inline bool TaskNotice::has_param() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TaskNotice::set_has_param() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TaskNotice::clear_has_param() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TaskNotice::clear_param() {
  param_ = 0;
  clear_has_param();
}
inline ::google::protobuf::int32 TaskNotice::param() const {
  return param_;
}
inline void TaskNotice::set_param(::google::protobuf::int32 value) {
  set_has_param();
  param_ = value;
}

// -------------------------------------------------------------------

// PrizeRequest

// required int32 taskId = 1;
inline bool PrizeRequest::has_taskid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PrizeRequest::set_has_taskid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PrizeRequest::clear_has_taskid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PrizeRequest::clear_taskid() {
  taskid_ = 0;
  clear_has_taskid();
}
inline ::google::protobuf::int32 PrizeRequest::taskid() const {
  return taskid_;
}
inline void PrizeRequest::set_taskid(::google::protobuf::int32 value) {
  set_has_taskid();
  taskid_ = value;
}

// -------------------------------------------------------------------

// PrizeResponse

// required int32 result = 1;
inline bool PrizeResponse::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PrizeResponse::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PrizeResponse::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PrizeResponse::clear_result() {
  result_ = 0;
  clear_has_result();
}
inline ::google::protobuf::int32 PrizeResponse::result() const {
  return result_;
}
inline void PrizeResponse::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
}

// optional .protos.common.Role role = 2;
inline bool PrizeResponse::has_role() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PrizeResponse::set_has_role() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PrizeResponse::clear_has_role() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PrizeResponse::clear_role() {
  if (role_ != NULL) role_->::protos::common::Role::Clear();
  clear_has_role();
}
inline const ::protos::common::Role& PrizeResponse::role() const {
  return role_ != NULL ? *role_ : *default_instance_->role_;
}
inline ::protos::common::Role* PrizeResponse::mutable_role() {
  set_has_role();
  if (role_ == NULL) role_ = new ::protos::common::Role;
  return role_;
}
inline ::protos::common::Role* PrizeResponse::release_role() {
  clear_has_role();
  ::protos::common::Role* temp = role_;
  role_ = NULL;
  return temp;
}
inline void PrizeResponse::set_allocated_role(::protos::common::Role* role) {
  delete role_;
  role_ = role;
  if (role) {
    set_has_role();
  } else {
    clear_has_role();
  }
}

// repeated .protos.common.Prize prizes = 3;
inline int PrizeResponse::prizes_size() const {
  return prizes_.size();
}
inline void PrizeResponse::clear_prizes() {
  prizes_.Clear();
}
inline const ::protos::common::Prize& PrizeResponse::prizes(int index) const {
  return prizes_.Get(index);
}
inline ::protos::common::Prize* PrizeResponse::mutable_prizes(int index) {
  return prizes_.Mutable(index);
}
inline ::protos::common::Prize* PrizeResponse::add_prizes() {
  return prizes_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protos::common::Prize >&
PrizeResponse::prizes() const {
  return prizes_;
}
inline ::google::protobuf::RepeatedPtrField< ::protos::common::Prize >*
PrizeResponse::mutable_prizes() {
  return &prizes_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protos

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_task_5fprotocol_2eproto__INCLUDED
