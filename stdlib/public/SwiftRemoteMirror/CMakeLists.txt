# libswiftRemoteMirror.dylib should not have runtime dependencies; it's
# always built as a shared library.
set(SWIFT_REMOTE_MIRROR_TARGETS "${SWIFT_SDKS}")
list(REMOVE_ITEM SWIFT_REMOTE_MIRROR_TARGETS "BAREMETAL")

if((SWIFT_BUILD_DYNAMIC_STDLIB OR SWIFT_BUILD_REMOTE_MIRROR)
  AND (NOT "${SWIFT_REMOTE_MIRROR_TARGETS}" STREQUAL ""))

  add_swift_target_library(swiftRemoteMirror
                    SHARED TARGET_LIBRARY DONT_EMBED_BITCODE NOSWIFTRT
                    SwiftRemoteMirror.cpp
                    LINK_LIBRARIES
                      swiftReflection
                    C_COMPILE_FLAGS
                      ${SWIFT_RUNTIME_CXX_FLAGS} -DswiftRemoteMirror_EXPORTS
                    LINK_FLAGS
                      ${SWIFT_RUNTIME_LINK_FLAGS}
                    INSTALL_IN_COMPONENT
                      swift-remote-mirror
                      TARGET_SDKS "${SWIFT_REMOTE_MIRROR_TARGETS}")
endif()
