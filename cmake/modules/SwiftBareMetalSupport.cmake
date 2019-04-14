set(arm-none-eabi-gcc ${SWIFT_BAREMETAL_TOOLCHAIN_PATH}/bin/arm-none-eabi-gcc)


function(_swift_baremetal_gcc_flags_for_arch arch var)
  set(flags)
  list(APPEND flags "-march=${SWIFT_SDK_BAREMETAL_ARCH_${arch}_ALT_SPELLING}" "-fno-rtti" "-fno-exceptions")
  set(${var} ${flags} PARENT_SCOPE)
endfunction()


function(_swift_baremetal_gcc_find program var)
  execute_process(
    COMMAND ${arm-none-eabi-gcc} -print-prog-name=${program}
    OUTPUT_STRIP_TRAILING_WHITESPACE
    OUTPUT_VARIABLE path)
  set(${var} ${path} PARENT_SCOPE)
endfunction()


function (swift_baremetal_include_for_arch arch var)
  _swift_baremetal_gcc_flags_for_arch(${arch} gccflags)

  string(REPLACE ";" " " gccflags_ss "${gccflags}")
  execute_process(COMMAND
    bash -c "echo | ${arm-none-eabi-gcc} -xc++ ${gccflags_ss} -E -Wp,-v - 2>&1 1>/dev/null \
      | grep '^ ' | sed 's/^ //g' | paste -sd\; -"
    OUTPUT_STRIP_TRAILING_WHITESPACE
    OUTPUT_VARIABLE includes)

  set(${var} ${includes} PARENT_SCOPE)
endfunction()


function(swift_baremetal_swift_compile_flags var)
  set(${var}
    "-Xcc" "-D_BAREMETAL"
    "-Xfrontend" "-disable-reflection-metadata"
    "-Xfrontend" "-assume-single-threaded"
    "-enforce-exclusivity=none"
    "-Xfrontend" "-metadata-sections"
    "-Xcc" "-isystem${SWIFT_BAREMETAL_TOOLCHAIN_PATH}/arm-none-eabi/include"
    PARENT_SCOPE)
endfunction()


function(swift_baremetal_c_compile_flags var)
  set(${var}
    "-D_BAREMETAL" "-D_GNU_SOURCE"
    "-D_POSIX_THREADS" "-D_POSIX_READER_WRITER_LOCKS" "-D_UNIX98_THREAD_MUTEX_ATTRIBUTES"
    "-fdata-sections" "-ffunction-sections"
    "-fno-rtti" "-fno-exceptions"
    "-I${CMAKE_SOURCE_DIR}/stdlib/public/stubs-baremetal/include"
    PARENT_SCOPE)
endfunction()


function(swift_baremetal_lib_for_arch arch var)
  _swift_baremetal_gcc_flags_for_arch(${arch} gccflags)

  string(REPLACE ";" " " gccflags_ss "${gccflags}")
  execute_process(COMMAND
    bash -c "${arm-none-eabi-gcc} ${gccflags_ss} -print-search-dirs | grep libraries | sed 's/libraries: =//g' | sed 's/:/;/g'"
    OUTPUT_STRIP_TRAILING_WHITESPACE
    OUTPUT_VARIABLE paths)
  set(${var} ${paths} PARENT_SCOPE)
endfunction()
