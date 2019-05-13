set(SWIFT_REFLECTION_TEST_TARGETS "${SWIFT_SDKS}")
list(REMOVE_ITEM SWIFT_REFLECTION_TEST_TARGETS "BAREMETAL")

if(NOT "${SWIFT_REFLECTION_TEST_TARGETS}" STREQUAL "")
  add_swift_target_executable(swift-reflection-test BUILD_WITH_STDLIB
    swift-reflection-test.c
    overrides.c
    LINK_FAT_LIBRARIES
      swiftRemoteMirror
    TARGET_SDKS
      "${SWIFT_REFLECTION_TEST_TARGETS}")
endif()
