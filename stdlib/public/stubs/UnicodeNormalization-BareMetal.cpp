#if defined(_BAREMETAL)

#include "../SwiftShims/UnicodeShims.h"
#include "swift/Runtime/Debug.h"
#include <stdint.h>
#include <cassert>


/// Convert the unicode string to uppercase. This function will return the
/// required buffer length as a result. If this length does not match the
/// 'DestinationCapacity' this function must be called again with a buffer of
/// the required length to get an uppercase version of the string.
int32_t
swift::_swift_stdlib_unicode_strToUpper(uint16_t *Destination,
                                        int32_t DestinationCapacity,
                                        const uint16_t *Source,
                                        int32_t SourceLength) {
  swift::fatalError(0, "unicode support not implemented");
}

/// Convert the unicode string to lowercase. This function will return the
/// required buffer length as a result. If this length does not match the
/// 'DestinationCapacity' this function must be called again with a buffer of
/// the required length to get a lowercase version of the string.
int32_t
swift::_swift_stdlib_unicode_strToLower(uint16_t *Destination,
                                        int32_t DestinationCapacity,
                                        const uint16_t *Source,
                                        int32_t SourceLength) {
  swift::fatalError(0, "unicode support not implemented");
}

void swift::__swift_stdlib_ubrk_close(
    swift::__swift_stdlib_UBreakIterator *bi) {
  swift::fatalError(0, "unicode support not implemented");
}

swift::__swift_stdlib_UBreakIterator *swift::__swift_stdlib_ubrk_open(
    swift::__swift_stdlib_UBreakIteratorType type, const char *locale,
    const __swift_stdlib_UChar *text, int32_t textLength,
    __swift_stdlib_UErrorCode *status) {
  swift::fatalError(0, "unicode support not implemented");
}

int32_t
swift::__swift_stdlib_ubrk_preceding(swift::__swift_stdlib_UBreakIterator *bi,
                                     int32_t offset) {
  swift::fatalError(0, "unicode support not implemented");
}

int32_t
swift::__swift_stdlib_ubrk_following(swift::__swift_stdlib_UBreakIterator *bi,
                                     int32_t offset) {
  swift::fatalError(0, "unicode support not implemented");
}

void swift::__swift_stdlib_ubrk_setText(
    swift::__swift_stdlib_UBreakIterator *bi, const __swift_stdlib_UChar *text,
    __swift_int32_t textLength, __swift_stdlib_UErrorCode *status) {
  swift::fatalError(0, "unicode support not implemented");
}

void swift::__swift_stdlib_ubrk_setUText(
    swift::__swift_stdlib_UBreakIterator *bi, __swift_stdlib_UText *text,
    __swift_stdlib_UErrorCode *status) {
  swift::fatalError(0, "unicode support not implemented");
}

SWIFT_RUNTIME_STDLIB_API swift::__swift_stdlib_UText *
swift::__swift_stdlib_utext_openUTF8(__swift_stdlib_UText *ut,
                              const char *s, int64_t len,
                              __swift_stdlib_UErrorCode *status) {
  swift::fatalError(0, "unicode support not implemented");
}

SWIFT_RUNTIME_STDLIB_API swift::__swift_stdlib_UText *
swift::__swift_stdlib_utext_openUChars(__swift_stdlib_UText *ut,
                                       const __swift_stdlib_UChar *s,
                                       int64_t len,
                                       __swift_stdlib_UErrorCode *status) {
  swift::fatalError(0, "unicode support not implemented");
}

swift::__swift_stdlib_UBool swift::__swift_stdlib_unorm2_hasBoundaryBefore(
    const __swift_stdlib_UNormalizer2 *ptr, __swift_stdlib_UChar32 char32) {
  swift::fatalError(0, "unicode support not implemented");
}
const swift::__swift_stdlib_UNormalizer2 *
swift::__swift_stdlib_unorm2_getNFCInstance(__swift_stdlib_UErrorCode *err) {
  swift::fatalError(0, "unicode support not implemented");
}

int32_t swift::__swift_stdlib_unorm2_normalize(
    const __swift_stdlib_UNormalizer2 *norm, const __swift_stdlib_UChar *src,
    __swift_int32_t len, __swift_stdlib_UChar *dst, __swift_int32_t capacity,
    __swift_stdlib_UErrorCode *err) {
  swift::fatalError(0, "unicode support not implemented");
}

__swift_int32_t swift::__swift_stdlib_unorm2_spanQuickCheckYes(
    const __swift_stdlib_UNormalizer2 *norm, const __swift_stdlib_UChar *ptr,
    __swift_int32_t len, __swift_stdlib_UErrorCode *err) {
  swift::fatalError(0, "unicode support not implemented");
}

swift::__swift_stdlib_UBool
swift::__swift_stdlib_u_hasBinaryProperty(__swift_stdlib_UChar32 c,
                                          __swift_stdlib_UProperty p) {
  swift::fatalError(0, "unicode support not implemented");
}

void
swift::__swift_stdlib_u_charAge(__swift_stdlib_UChar32 c,
                                __swift_stdlib_UVersionInfo versionInfo) {
  swift::fatalError(0, "unicode support not implemented");
}

__swift_int32_t
swift::__swift_stdlib_u_getIntPropertyValue(__swift_stdlib_UChar32 c,
                                            __swift_stdlib_UProperty p) {
  swift::fatalError(0, "unicode support not implemented");
}

__swift_int32_t swift::__swift_stdlib_u_charName(
    __swift_stdlib_UChar32 code, __swift_stdlib_UCharNameChoice nameChoice,
    char *buffer, __swift_int32_t bufferLength,
    __swift_stdlib_UErrorCode *pErrorCode) {
  swift::fatalError(0, "unicode support not implemented");
}

__swift_int32_t swift::__swift_stdlib_u_strToLower(
    __swift_stdlib_UChar *dest, __swift_int32_t destCapacity,
    const __swift_stdlib_UChar *src, __swift_int32_t srcLength,
    const char *locale, __swift_stdlib_UErrorCode *pErrorCode) {
  swift::fatalError(0, "unicode support not implemented");
}

__swift_int32_t swift::__swift_stdlib_u_strToTitle(
    __swift_stdlib_UChar *dest, __swift_int32_t destCapacity,
    const __swift_stdlib_UChar *src, __swift_int32_t srcLength,
    __swift_stdlib_UBreakIterator *titleIter, const char *locale,
    __swift_stdlib_UErrorCode *pErrorCode) {
  swift::fatalError(0, "unicode support not implemented");
}

__swift_int32_t swift::__swift_stdlib_u_strToUpper(
    __swift_stdlib_UChar *dest, __swift_int32_t destCapacity,
    const __swift_stdlib_UChar *src, __swift_int32_t srcLength,
    const char *locale, __swift_stdlib_UErrorCode *pErrorCode) {
  swift::fatalError(0, "unicode support not implemented");
}

double swift::__swift_stdlib_u_getNumericValue(__swift_stdlib_UChar32 c) {
  swift::fatalError(0, "unicode support not implemented");
}

#endif /* defined(_BAREMETAL) */
