// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protocol.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "protocol.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace protos {

namespace {

const ::google::protobuf::Descriptor* Protocol_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Protocol_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_protocol_2eproto() {
  protobuf_AddDesc_protocol_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "protocol.proto");
  GOOGLE_CHECK(file != NULL);
  Protocol_descriptor_ = file->message_type(0);
  static const int Protocol_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Protocol, protocoltype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Protocol, data_),
  };
  Protocol_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Protocol_descriptor_,
      Protocol::default_instance_,
      Protocol_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Protocol, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Protocol, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Protocol));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_protocol_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Protocol_descriptor_, &Protocol::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_protocol_2eproto() {
  delete Protocol::default_instance_;
  delete Protocol_reflection_;
}

void protobuf_AddDesc_protocol_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016protocol.proto\022\006protos\".\n\010Protocol\022\024\n\014"
    "protocolType\030\001 \002(\005\022\014\n\004data\030\002 \001(\014B0\n\036anvi"
    "n.server.gameserver.protosB\014BaseProtocol"
    "H\001", 122);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "protocol.proto", &protobuf_RegisterTypes);
  Protocol::default_instance_ = new Protocol();
  Protocol::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_protocol_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_protocol_2eproto {
  StaticDescriptorInitializer_protocol_2eproto() {
    protobuf_AddDesc_protocol_2eproto();
  }
} static_descriptor_initializer_protocol_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Protocol::kProtocolTypeFieldNumber;
const int Protocol::kDataFieldNumber;
#endif  // !_MSC_VER

Protocol::Protocol()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Protocol::InitAsDefaultInstance() {
}

Protocol::Protocol(const Protocol& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Protocol::SharedCtor() {
  _cached_size_ = 0;
  protocoltype_ = 0;
  data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Protocol::~Protocol() {
  SharedDtor();
}

void Protocol::SharedDtor() {
  if (data_ != &::google::protobuf::internal::kEmptyString) {
    delete data_;
  }
  if (this != default_instance_) {
  }
}

void Protocol::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Protocol::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Protocol_descriptor_;
}

const Protocol& Protocol::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_protocol_2eproto();
  return *default_instance_;
}

Protocol* Protocol::default_instance_ = NULL;

Protocol* Protocol::New() const {
  return new Protocol;
}

void Protocol::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    protocoltype_ = 0;
    if (has_data()) {
      if (data_ != &::google::protobuf::internal::kEmptyString) {
        data_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Protocol::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 protocolType = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &protocoltype_)));
          set_has_protocoltype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_data;
        break;
      }

      // optional bytes data = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Protocol::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 protocolType = 1;
  if (has_protocoltype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->protocoltype(), output);
  }

  // optional bytes data = 2;
  if (has_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->data(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Protocol::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 protocolType = 1;
  if (has_protocoltype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->protocoltype(), target);
  }

  // optional bytes data = 2;
  if (has_data()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->data(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Protocol::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 protocolType = 1;
    if (has_protocoltype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->protocoltype());
    }

    // optional bytes data = 2;
    if (has_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->data());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Protocol::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Protocol* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Protocol*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Protocol::MergeFrom(const Protocol& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_protocoltype()) {
      set_protocoltype(from.protocoltype());
    }
    if (from.has_data()) {
      set_data(from.data());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Protocol::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Protocol::CopyFrom(const Protocol& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Protocol::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void Protocol::Swap(Protocol* other) {
  if (other != this) {
    std::swap(protocoltype_, other->protocoltype_);
    std::swap(data_, other->data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Protocol::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Protocol_descriptor_;
  metadata.reflection = Protocol_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protos

// @@protoc_insertion_point(global_scope)
