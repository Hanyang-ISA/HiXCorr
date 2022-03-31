// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: view_ms1_cmds.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "view_ms1_cmds.pb.h"

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

namespace pb {

namespace {

const ::google::protobuf::Descriptor* ViewMS1Command_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ViewMS1Command_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_view_5fms1_5fcmds_2eproto() {
  protobuf_AddDesc_view_5fms1_5fcmds_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "view_ms1_cmds.proto");
  GOOGLE_CHECK(file != NULL);
  ViewMS1Command_descriptor_ = file->message_type(0);
  static const int ViewMS1Command_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewMS1Command, load_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewMS1Command, bucket_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewMS1Command, min_mz_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewMS1Command, max_mz_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewMS1Command, min_rtime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewMS1Command, max_rtime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewMS1Command, write_matrix_),
  };
  ViewMS1Command_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ViewMS1Command_descriptor_,
      ViewMS1Command::default_instance_,
      ViewMS1Command_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewMS1Command, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ViewMS1Command, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ViewMS1Command));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_view_5fms1_5fcmds_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ViewMS1Command_descriptor_, &ViewMS1Command::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_view_5fms1_5fcmds_2eproto() {
  delete ViewMS1Command::default_instance_;
  delete ViewMS1Command_reflection_;
}

void protobuf_AddDesc_view_5fms1_5fcmds_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023view_ms1_cmds.proto\022\002pb\"\212\001\n\016ViewMS1Com"
    "mand\022\014\n\004load\030\001 \001(\t\022\016\n\006bucket\030\002 \001(\001\022\016\n\006mi"
    "n_mz\030\003 \001(\001\022\016\n\006max_mz\030\004 \001(\001\022\021\n\tmin_rtime\030"
    "\005 \001(\001\022\021\n\tmax_rtime\030\006 \001(\001\022\024\n\014write_matrix"
    "\030\007 \001(\tB\002H\001", 170);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "view_ms1_cmds.proto", &protobuf_RegisterTypes);
  ViewMS1Command::default_instance_ = new ViewMS1Command();
  ViewMS1Command::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_view_5fms1_5fcmds_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_view_5fms1_5fcmds_2eproto {
  StaticDescriptorInitializer_view_5fms1_5fcmds_2eproto() {
    protobuf_AddDesc_view_5fms1_5fcmds_2eproto();
  }
} static_descriptor_initializer_view_5fms1_5fcmds_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ViewMS1Command::kLoadFieldNumber;
const int ViewMS1Command::kBucketFieldNumber;
const int ViewMS1Command::kMinMzFieldNumber;
const int ViewMS1Command::kMaxMzFieldNumber;
const int ViewMS1Command::kMinRtimeFieldNumber;
const int ViewMS1Command::kMaxRtimeFieldNumber;
const int ViewMS1Command::kWriteMatrixFieldNumber;
#endif  // !_MSC_VER

ViewMS1Command::ViewMS1Command()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ViewMS1Command::InitAsDefaultInstance() {
}

ViewMS1Command::ViewMS1Command(const ViewMS1Command& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ViewMS1Command::SharedCtor() {
  _cached_size_ = 0;
  load_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  bucket_ = 0;
  min_mz_ = 0;
  max_mz_ = 0;
  min_rtime_ = 0;
  max_rtime_ = 0;
  write_matrix_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ViewMS1Command::~ViewMS1Command() {
  SharedDtor();
}

void ViewMS1Command::SharedDtor() {
  if (load_ != &::google::protobuf::internal::kEmptyString) {
    delete load_;
  }
  if (write_matrix_ != &::google::protobuf::internal::kEmptyString) {
    delete write_matrix_;
  }
  if (this != default_instance_) {
  }
}

void ViewMS1Command::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ViewMS1Command::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ViewMS1Command_descriptor_;
}

const ViewMS1Command& ViewMS1Command::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_view_5fms1_5fcmds_2eproto();
  return *default_instance_;
}

ViewMS1Command* ViewMS1Command::default_instance_ = NULL;

ViewMS1Command* ViewMS1Command::New() const {
  return new ViewMS1Command;
}

void ViewMS1Command::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_load()) {
      if (load_ != &::google::protobuf::internal::kEmptyString) {
        load_->clear();
      }
    }
    bucket_ = 0;
    min_mz_ = 0;
    max_mz_ = 0;
    min_rtime_ = 0;
    max_rtime_ = 0;
    if (has_write_matrix()) {
      if (write_matrix_ != &::google::protobuf::internal::kEmptyString) {
        write_matrix_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ViewMS1Command::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string load = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_load()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->load().data(), this->load().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(17)) goto parse_bucket;
        break;
      }

      // optional double bucket = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_bucket:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &bucket_)));
          set_has_bucket();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(25)) goto parse_min_mz;
        break;
      }

      // optional double min_mz = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_min_mz:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &min_mz_)));
          set_has_min_mz();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(33)) goto parse_max_mz;
        break;
      }

      // optional double max_mz = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_max_mz:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &max_mz_)));
          set_has_max_mz();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(41)) goto parse_min_rtime;
        break;
      }

      // optional double min_rtime = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_min_rtime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &min_rtime_)));
          set_has_min_rtime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(49)) goto parse_max_rtime;
        break;
      }

      // optional double max_rtime = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_max_rtime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &max_rtime_)));
          set_has_max_rtime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_write_matrix;
        break;
      }

      // optional string write_matrix = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_write_matrix:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_write_matrix()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->write_matrix().data(), this->write_matrix().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
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

void ViewMS1Command::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional string load = 1;
  if (has_load()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->load().data(), this->load().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->load(), output);
  }

  // optional double bucket = 2;
  if (has_bucket()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->bucket(), output);
  }

  // optional double min_mz = 3;
  if (has_min_mz()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->min_mz(), output);
  }

  // optional double max_mz = 4;
  if (has_max_mz()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->max_mz(), output);
  }

  // optional double min_rtime = 5;
  if (has_min_rtime()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(5, this->min_rtime(), output);
  }

  // optional double max_rtime = 6;
  if (has_max_rtime()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(6, this->max_rtime(), output);
  }

  // optional string write_matrix = 7;
  if (has_write_matrix()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->write_matrix().data(), this->write_matrix().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      7, this->write_matrix(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ViewMS1Command::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional string load = 1;
  if (has_load()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->load().data(), this->load().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->load(), target);
  }

  // optional double bucket = 2;
  if (has_bucket()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->bucket(), target);
  }

  // optional double min_mz = 3;
  if (has_min_mz()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->min_mz(), target);
  }

  // optional double max_mz = 4;
  if (has_max_mz()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->max_mz(), target);
  }

  // optional double min_rtime = 5;
  if (has_min_rtime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, this->min_rtime(), target);
  }

  // optional double max_rtime = 6;
  if (has_max_rtime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(6, this->max_rtime(), target);
  }

  // optional string write_matrix = 7;
  if (has_write_matrix()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->write_matrix().data(), this->write_matrix().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->write_matrix(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ViewMS1Command::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string load = 1;
    if (has_load()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->load());
    }

    // optional double bucket = 2;
    if (has_bucket()) {
      total_size += 1 + 8;
    }

    // optional double min_mz = 3;
    if (has_min_mz()) {
      total_size += 1 + 8;
    }

    // optional double max_mz = 4;
    if (has_max_mz()) {
      total_size += 1 + 8;
    }

    // optional double min_rtime = 5;
    if (has_min_rtime()) {
      total_size += 1 + 8;
    }

    // optional double max_rtime = 6;
    if (has_max_rtime()) {
      total_size += 1 + 8;
    }

    // optional string write_matrix = 7;
    if (has_write_matrix()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->write_matrix());
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

void ViewMS1Command::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ViewMS1Command* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ViewMS1Command*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ViewMS1Command::MergeFrom(const ViewMS1Command& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_load()) {
      set_load(from.load());
    }
    if (from.has_bucket()) {
      set_bucket(from.bucket());
    }
    if (from.has_min_mz()) {
      set_min_mz(from.min_mz());
    }
    if (from.has_max_mz()) {
      set_max_mz(from.max_mz());
    }
    if (from.has_min_rtime()) {
      set_min_rtime(from.min_rtime());
    }
    if (from.has_max_rtime()) {
      set_max_rtime(from.max_rtime());
    }
    if (from.has_write_matrix()) {
      set_write_matrix(from.write_matrix());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ViewMS1Command::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ViewMS1Command::CopyFrom(const ViewMS1Command& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ViewMS1Command::IsInitialized() const {

  return true;
}

void ViewMS1Command::Swap(ViewMS1Command* other) {
  if (other != this) {
    std::swap(load_, other->load_);
    std::swap(bucket_, other->bucket_);
    std::swap(min_mz_, other->min_mz_);
    std::swap(max_mz_, other->max_mz_);
    std::swap(min_rtime_, other->min_rtime_);
    std::swap(max_rtime_, other->max_rtime_);
    std::swap(write_matrix_, other->write_matrix_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ViewMS1Command::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ViewMS1Command_descriptor_;
  metadata.reflection = ViewMS1Command_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb

// @@protoc_insertion_point(global_scope)