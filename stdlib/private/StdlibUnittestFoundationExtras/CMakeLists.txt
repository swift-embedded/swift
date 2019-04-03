add_swift_target_library(swiftStdlibUnittestFoundationExtras ${SWIFT_STDLIB_LIBRARY_BUILD_TYPES} IS_STDLIB
  # This file should be listed the first.  Module name is inferred from the
  # filename.
  StdlibUnittestFoundationExtras.swift
  UnavailableFoundationMethodThunks.mm

  SWIFT_MODULE_DEPENDS Foundation StdlibUnittest
  INSTALL_IN_COMPONENT stdlib-experimental
  TARGET_SDKS OSX IOS IOS_SIMULATOR TVOS TVOS_SIMULATOR WATCHOS WATCHOS_SIMULATOR
  )

