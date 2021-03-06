set(SWIFT_LIBC_EXTRA_TARGETS "${SWIFT_SDKS}")
list(REMOVE_ITEM SWIFT_LIBC_EXTRA_TARGETS "BAREMETAL")

if(NOT "${SWIFT_LIBC_EXTRA_TARGETS}" STREQUAL "")
  add_swift_target_library(swiftSwiftPrivateLibcExtras ${SWIFT_STDLIB_LIBRARY_BUILD_TYPES} IS_STDLIB
    # This file should be listed the first.  Module name is inferred from the
    # filename.
    SwiftPrivateLibcExtras.swift
    Subprocess.c
    Subprocess.swift
    "${SWIFT_SOURCE_DIR}/stdlib/linker-support/magic-symbols-for-install-name.c"

    TARGET_SDKS "${SWIFT_LIBC_EXTRA_TARGETS}"
    SWIFT_MODULE_DEPENDS SwiftPrivate
    SWIFT_COMPILE_FLAGS
    SWIFT_MODULE_DEPENDS_OSX Darwin
    SWIFT_MODULE_DEPENDS_IOS Darwin
    SWIFT_MODULE_DEPENDS_TVOS Darwin
    SWIFT_MODULE_DEPENDS_WATCHOS Darwin
    SWIFT_MODULE_DEPENDS_LINUX Glibc
    SWIFT_MODULE_DEPENDS_FREEBSD Glibc
    SWIFT_MODULE_DEPENDS_CYGWIN Glibc
    SWIFT_MODULE_DEPENDS_HAIKU Glibc
    SWIFT_MODULE_DEPENDS_WINDOWS MSVCRT WinSDK
    INSTALL_IN_COMPONENT stdlib-experimental
    DARWIN_INSTALL_NAME_DIR "${SWIFT_DARWIN_STDLIB_PRIVATE_INSTALL_NAME_DIR}")
endif()
