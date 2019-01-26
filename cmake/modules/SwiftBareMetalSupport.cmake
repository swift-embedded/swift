function (swift_baremetal_include_for_arch arch var)
  set(includes)

  if(arch STREQUAL "armv7m")
    list(APPEND includes "-I${SWIFT_BAREMETAL_TOOLCHAIN_PATH}/arm-none-eabi/include/c++/8.2.1/arm-none-eabi")
    list(APPEND includes "-I${SWIFT_BAREMETAL_TOOLCHAIN_PATH}/arm-none-eabi/include/c++/8.2.1")
    list(APPEND includes "-I${SWIFT_BAREMETAL_TOOLCHAIN_PATH}/arm-none-eabi/include")
    list(APPEND includes "-I${SWIFT_BAREMETAL_TOOLCHAIN_PATH}/lib/gcc/arm-none-eabi/8.2.1/include-fixed")
    list(APPEND includes "-isysroot" "${SWIFT_BAREMETAL_TOOLCHAIN_PATH}/arm-none-eabi")
  else()
    message(SEND_ERROR "unknown architecture ${arch} for baremetal")
  endif()

  set(${var} ${includes} PARENT_SCOPE)
endfunction()

function(swift_baremetal_lib_for_arch arch var)
  set(paths)

  if(arch STREQUAL "armv7m")
    list(APPEND paths "${SWIFT_BAREMETAL_TOOLCHAIN_PATH}/arm-none-eabi/lib")
    list(APPEND paths "${SWIFT_BAREMETAL_TOOLCHAIN_PATH}/lib/gcc/arm-none-eabi/8.2.1")
  else()
    message(SEND_ERROR "unknown architecture ${arch} for baremetal")
  endif()

  set(${var} ${paths} PARENT_SCOPE)
endfunction()
