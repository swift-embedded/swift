
#include "../SwiftShims/UnicodeShims.h"
#include <stdint.h>
#include <cassert>


int32_t
swift::_swift_stdlib_unicode_strToUpper(uint16_t *Destination,
                                        int32_t DestinationCapacity,
                                        const uint16_t *Source,
                                        int32_t SourceLength) {
    assert(false && "unicode support not implemented");
}

int32_t
swift::_swift_stdlib_unicode_strToLower(uint16_t *Destination,
                                        int32_t DestinationCapacity,
                                        const uint16_t *Source,
                                        int32_t SourceLength) {
    assert(false && "unicode support not implemented");
}

void swift::__swift_stdlib_ubrk_close(
    swift::__swift_stdlib_UBreakIterator *bi) {
    assert(false && "unicode support not implemented");
}


swift::__swift_stdlib_UBreakIterator *swift::__swift_stdlib_ubrk_open(
    swift::__swift_stdlib_UBreakIteratorType type, const char *locale,
    const __swift_stdlib_UChar *text, int32_t textLength,
    __swift_stdlib_UErrorCode *status) {

    assert(false && "unicode support not implemented");
}


int32_t
swift::__swift_stdlib_ubrk_preceding(swift::__swift_stdlib_UBreakIterator *bi,
                                     int32_t offset) {
    assert(false && "unicode support not implemented");
}

int32_t
swift::__swift_stdlib_ubrk_following(swift::__swift_stdlib_UBreakIterator *bi,
                                     int32_t offset) {
    assert(false && "unicode support not implemented");
}

void swift::__swift_stdlib_ubrk_setText(
    swift::__swift_stdlib_UBreakIterator *bi, const __swift_stdlib_UChar *text,
    __swift_int32_t textLength, __swift_stdlib_UErrorCode *status) {
    assert(false && "unicode support not implemented");
}

swift::__swift_stdlib_UBool swift::__swift_stdlib_unorm2_hasBoundaryBefore(
    const __swift_stdlib_UNormalizer2 *ptr, __swift_stdlib_UChar32 char32) {
    assert(false && "unicode support not implemented");
}

const swift::__swift_stdlib_UNormalizer2 *
swift::__swift_stdlib_unorm2_getNFCInstance(__swift_stdlib_UErrorCode *err) {
    assert(false && "unicode support not implemented");
}

int32_t swift::__swift_stdlib_unorm2_normalize(
    const __swift_stdlib_UNormalizer2 *norm, const __swift_stdlib_UChar *src,
    __swift_int32_t len, __swift_stdlib_UChar *dst, __swift_int32_t capacity,
    __swift_stdlib_UErrorCode *err) {
    assert(false && "unicode support not implemented");
}

__swift_int32_t swift::__swift_stdlib_unorm2_spanQuickCheckYes(
    const __swift_stdlib_UNormalizer2 *norm, const __swift_stdlib_UChar *ptr,
    __swift_int32_t len, __swift_stdlib_UErrorCode *err) {
    assert(false && "unicode support not implemented");
}

swift::__swift_stdlib_UBool
swift::__swift_stdlib_u_hasBinaryProperty(__swift_stdlib_UChar32 c,
                                          __swift_stdlib_UProperty p) {
    assert(false && "unicode support not implemented");
}
