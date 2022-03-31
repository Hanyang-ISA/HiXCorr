// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: results.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "results.pb.h"

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

const ::google::protobuf::Descriptor* Match_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Match_reflection_ = NULL;
const ::google::protobuf::Descriptor* Stats_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Stats_reflection_ = NULL;
const ::google::protobuf::Descriptor* Results_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Results_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_results_2eproto() {
  protobuf_AddDesc_results_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "results.proto");
  GOOGLE_CHECK(file != NULL);
  Match_descriptor_ = file->message_type(0);
  static const int Match_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Match, xcorr_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Match, peptide_),
  };
  Match_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Match_descriptor_,
      Match::default_instance_,
      Match_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Match, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Match, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Match));
  Stats_descriptor_ = file->message_type(1);
  static const int Stats_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Stats, count_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Stats, sum_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Stats, sum_squares_),
  };
  Stats_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Stats_descriptor_,
      Stats::default_instance_,
      Stats_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Stats, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Stats, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Stats));
  Results_descriptor_ = file->message_type(2);
  static const int Results_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, spectrum_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, charge_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, matches_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, spectrum_index_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, stats_),
  };
  Results_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Results_descriptor_,
      Results::default_instance_,
      Results_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Results));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_results_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Match_descriptor_, &Match::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Stats_descriptor_, &Stats::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Results_descriptor_, &Results::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_results_2eproto() {
  delete Match::default_instance_;
  delete Match_reflection_;
  delete Stats::default_instance_;
  delete Stats_reflection_;
  delete Results::default_instance_;
  delete Results_reflection_;
}

void protobuf_AddDesc_results_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::pb::protobuf_AddDesc_peptides_2eproto();
  ::pb::protobuf_AddDesc_spectrum_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rresults.proto\022\002pb\032\016peptides.proto\032\016spe"
    "ctrum.proto\"4\n\005Match\022\r\n\005xcorr\030\001 \001(\001\022\034\n\007p"
    "eptide\030\002 \001(\0132\013.pb.Peptide\"8\n\005Stats\022\r\n\005co"
    "unt\030\001 \001(\005\022\013\n\003sum\030\002 \001(\001\022\023\n\013sum_squares\030\003 "
    "\001(\001\"\207\001\n\007Results\022\036\n\010spectrum\030\001 \001(\0132\014.pb.S"
    "pectrum\022\016\n\006charge\030\002 \001(\005\022\032\n\007matches\030\003 \003(\013"
    "2\t.pb.Match\022\026\n\016spectrum_index\030\004 \001(\005\022\030\n\005s"
    "tats\030\005 \001(\0132\t.pb.StatsB\002H\001", 305);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "results.proto", &protobuf_RegisterTypes);
  Match::default_instance_ = new Match();
  Stats::default_instance_ = new Stats();
  Results::default_instance_ = new Results();
  Match::default_instance_->InitAsDefaultInstance();
  Stats::default_instance_->InitAsDefaultInstance();
  Results::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_results_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_results_2eproto {
  StaticDescriptorInitializer_results_2eproto() {
    protobuf_AddDesc_results_2eproto();
  }
} static_descriptor_initializer_results_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Match::kXcorrFieldNumber;
const int Match::kPeptideFieldNumber;
#endif  // !_MSC_VER

Match::Match()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Match::InitAsDefaultInstance() {
  peptide_ = const_cast< ::pb::Peptide*>(&::pb::Peptide::default_instance());
}

Match::Match(const Match& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Match::SharedCtor() {
  _cached_size_ = 0;
  xcorr_ = 0;
  peptide_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Match::~Match() {
  SharedDtor();
}

void Match::SharedDtor() {
  if (this != default_instance_) {
    delete peptide_;
  }
}

void Match::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Match::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Match_descriptor_;
}

const Match& Match::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_results_2eproto();
  return *default_instance_;
}

Match* Match::default_instance_ = NULL;

Match* Match::New() const {
  return new Match;
}

void Match::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    xcorr_ = 0;
    if (has_peptide()) {
      if (peptide_ != NULL) peptide_->::pb::Peptide::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Match::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional double xcorr = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &xcorr_)));
          set_has_xcorr();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_peptide;
        break;
      }

      // optional .pb.Peptide peptide = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_peptide:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_peptide()));
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

void Match::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional double xcorr = 1;
  if (has_xcorr()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->xcorr(), output);
  }

  // optional .pb.Peptide peptide = 2;
  if (has_peptide()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->peptide(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Match::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional double xcorr = 1;
  if (has_xcorr()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->xcorr(), target);
  }

  // optional .pb.Peptide peptide = 2;
  if (has_peptide()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->peptide(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Match::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional double xcorr = 1;
    if (has_xcorr()) {
      total_size += 1 + 8;
    }

    // optional .pb.Peptide peptide = 2;
    if (has_peptide()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->peptide());
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

void Match::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Match* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Match*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Match::MergeFrom(const Match& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_xcorr()) {
      set_xcorr(from.xcorr());
    }
    if (from.has_peptide()) {
      mutable_peptide()->::pb::Peptide::MergeFrom(from.peptide());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Match::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Match::CopyFrom(const Match& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Match::IsInitialized() const {

  return true;
}

void Match::Swap(Match* other) {
  if (other != this) {
    std::swap(xcorr_, other->xcorr_);
    std::swap(peptide_, other->peptide_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Match::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Match_descriptor_;
  metadata.reflection = Match_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Stats::kCountFieldNumber;
const int Stats::kSumFieldNumber;
const int Stats::kSumSquaresFieldNumber;
#endif  // !_MSC_VER

Stats::Stats()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Stats::InitAsDefaultInstance() {
}

Stats::Stats(const Stats& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Stats::SharedCtor() {
  _cached_size_ = 0;
  count_ = 0;
  sum_ = 0;
  sum_squares_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Stats::~Stats() {
  SharedDtor();
}

void Stats::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Stats::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Stats::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Stats_descriptor_;
}

const Stats& Stats::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_results_2eproto();
  return *default_instance_;
}

Stats* Stats::default_instance_ = NULL;

Stats* Stats::New() const {
  return new Stats;
}

void Stats::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    count_ = 0;
    sum_ = 0;
    sum_squares_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Stats::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 count = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &count_)));
          set_has_count();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(17)) goto parse_sum;
        break;
      }

      // optional double sum = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_sum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &sum_)));
          set_has_sum();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(25)) goto parse_sum_squares;
        break;
      }

      // optional double sum_squares = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_sum_squares:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &sum_squares_)));
          set_has_sum_squares();
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

void Stats::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 count = 1;
  if (has_count()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->count(), output);
  }

  // optional double sum = 2;
  if (has_sum()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->sum(), output);
  }

  // optional double sum_squares = 3;
  if (has_sum_squares()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->sum_squares(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Stats::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 count = 1;
  if (has_count()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->count(), target);
  }

  // optional double sum = 2;
  if (has_sum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->sum(), target);
  }

  // optional double sum_squares = 3;
  if (has_sum_squares()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->sum_squares(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Stats::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 count = 1;
    if (has_count()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->count());
    }

    // optional double sum = 2;
    if (has_sum()) {
      total_size += 1 + 8;
    }

    // optional double sum_squares = 3;
    if (has_sum_squares()) {
      total_size += 1 + 8;
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

void Stats::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Stats* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Stats*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Stats::MergeFrom(const Stats& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_count()) {
      set_count(from.count());
    }
    if (from.has_sum()) {
      set_sum(from.sum());
    }
    if (from.has_sum_squares()) {
      set_sum_squares(from.sum_squares());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Stats::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Stats::CopyFrom(const Stats& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Stats::IsInitialized() const {

  return true;
}

void Stats::Swap(Stats* other) {
  if (other != this) {
    std::swap(count_, other->count_);
    std::swap(sum_, other->sum_);
    std::swap(sum_squares_, other->sum_squares_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Stats::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Stats_descriptor_;
  metadata.reflection = Stats_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Results::kSpectrumFieldNumber;
const int Results::kChargeFieldNumber;
const int Results::kMatchesFieldNumber;
const int Results::kSpectrumIndexFieldNumber;
const int Results::kStatsFieldNumber;
#endif  // !_MSC_VER

Results::Results()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Results::InitAsDefaultInstance() {
  spectrum_ = const_cast< ::pb::Spectrum*>(&::pb::Spectrum::default_instance());
  stats_ = const_cast< ::pb::Stats*>(&::pb::Stats::default_instance());
}

Results::Results(const Results& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Results::SharedCtor() {
  _cached_size_ = 0;
  spectrum_ = NULL;
  charge_ = 0;
  spectrum_index_ = 0;
  stats_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Results::~Results() {
  SharedDtor();
}

void Results::SharedDtor() {
  if (this != default_instance_) {
    delete spectrum_;
    delete stats_;
  }
}

void Results::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Results::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Results_descriptor_;
}

const Results& Results::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_results_2eproto();
  return *default_instance_;
}

Results* Results::default_instance_ = NULL;

Results* Results::New() const {
  return new Results;
}

void Results::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_spectrum()) {
      if (spectrum_ != NULL) spectrum_->::pb::Spectrum::Clear();
    }
    charge_ = 0;
    spectrum_index_ = 0;
    if (has_stats()) {
      if (stats_ != NULL) stats_->::pb::Stats::Clear();
    }
  }
  matches_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Results::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .pb.Spectrum spectrum = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_spectrum()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_charge;
        break;
      }

      // optional int32 charge = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_charge:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &charge_)));
          set_has_charge();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_matches;
        break;
      }

      // repeated .pb.Match matches = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_matches:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_matches()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_matches;
        if (input->ExpectTag(32)) goto parse_spectrum_index;
        break;
      }

      // optional int32 spectrum_index = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_spectrum_index:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &spectrum_index_)));
          set_has_spectrum_index();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_stats;
        break;
      }

      // optional .pb.Stats stats = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_stats:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_stats()));
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

void Results::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional .pb.Spectrum spectrum = 1;
  if (has_spectrum()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->spectrum(), output);
  }

  // optional int32 charge = 2;
  if (has_charge()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->charge(), output);
  }

  // repeated .pb.Match matches = 3;
  for (int i = 0; i < this->matches_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->matches(i), output);
  }

  // optional int32 spectrum_index = 4;
  if (has_spectrum_index()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->spectrum_index(), output);
  }

  // optional .pb.Stats stats = 5;
  if (has_stats()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->stats(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Results::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional .pb.Spectrum spectrum = 1;
  if (has_spectrum()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->spectrum(), target);
  }

  // optional int32 charge = 2;
  if (has_charge()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->charge(), target);
  }

  // repeated .pb.Match matches = 3;
  for (int i = 0; i < this->matches_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->matches(i), target);
  }

  // optional int32 spectrum_index = 4;
  if (has_spectrum_index()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->spectrum_index(), target);
  }

  // optional .pb.Stats stats = 5;
  if (has_stats()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->stats(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Results::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .pb.Spectrum spectrum = 1;
    if (has_spectrum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->spectrum());
    }

    // optional int32 charge = 2;
    if (has_charge()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->charge());
    }

    // optional int32 spectrum_index = 4;
    if (has_spectrum_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->spectrum_index());
    }

    // optional .pb.Stats stats = 5;
    if (has_stats()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->stats());
    }

  }
  // repeated .pb.Match matches = 3;
  total_size += 1 * this->matches_size();
  for (int i = 0; i < this->matches_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->matches(i));
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

void Results::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Results* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Results*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Results::MergeFrom(const Results& from) {
  GOOGLE_CHECK_NE(&from, this);
  matches_.MergeFrom(from.matches_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_spectrum()) {
      mutable_spectrum()->::pb::Spectrum::MergeFrom(from.spectrum());
    }
    if (from.has_charge()) {
      set_charge(from.charge());
    }
    if (from.has_spectrum_index()) {
      set_spectrum_index(from.spectrum_index());
    }
    if (from.has_stats()) {
      mutable_stats()->::pb::Stats::MergeFrom(from.stats());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Results::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Results::CopyFrom(const Results& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Results::IsInitialized() const {

  return true;
}

void Results::Swap(Results* other) {
  if (other != this) {
    std::swap(spectrum_, other->spectrum_);
    std::swap(charge_, other->charge_);
    matches_.Swap(&other->matches_);
    std::swap(spectrum_index_, other->spectrum_index_);
    std::swap(stats_, other->stats_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Results::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Results_descriptor_;
  metadata.reflection = Results_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb

// @@protoc_insertion_point(global_scope)
