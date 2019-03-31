set(swift_stubs_baremetal_sources
    atomic.c
    extra.c
    thread.c)
set(swift_stubs_flags
    -Os -g -fno-short-enums
    -fdata-sections -ffunction-sections
    -Wno-discarded-qualifiers -Wno-builtin-declaration-mismatch
    -D_POSIX_READER_WRITER_LOCKS -D_POSIX_THREADS)

foreach(arch IN LISTS SWIFT_SDK_BAREMETAL_ARCHITECTURES)
  set(swift_stubs_baremetal_objects_dir ${CMAKE_CURRENT_BINARY_DIR}/${arch})
  set(swift_stubs_baremetal_objects)

  # create subdir
  add_custom_command_target(objects_dir_target
    COMMAND "${CMAKE_COMMAND}"
    -E make_directory ${swift_stubs_baremetal_objects_dir}
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${arch}
    VERBATIM)

  foreach(source_file ${swift_stubs_baremetal_sources})
    set(full_path ${CMAKE_CURRENT_SOURCE_DIR}/${source_file})
    set(object_path ${swift_stubs_baremetal_objects_dir}/${source_file}-${arch}.o)
    add_custom_command_target(
      unused_var
      COMMAND arm-none-eabi-gcc
      ${swift_stubs_flags} -march=${SWIFT_SDK_BAREMETAL_ARCH_${arch}_ALT_SPELLING} -mthumb
        -c ${full_path}
        -o ${object_path}
      DEPENDS ${full_path} ${objects_dir_target}
      SOURCES ${full_path}
      OUTPUT ${object_path}
      VERBATIM)
    list(APPEND swift_stubs_baremetal_objects ${object_path})
  endforeach()

  set(swift_stubs_baremetal_lib_name
   ${SWIFTSTATICLIB_DIR}/${SWIFT_SDK_BAREMETAL_LIB_SUBDIR}/${arch}/libswiftStdlibStubsBaremetal.a)

  add_custom_command_target(
    library_target
    COMMAND arm-none-eabi-ar q ${swift_stubs_baremetal_lib_name}
    ${swift_stubs_baremetal_objects}
    COMMAND arm-none-eabi-ranlib ${swift_stubs_baremetal_lib_name}
    CUSTOM_TARGET_NAME "swiftStdlibStubsBaremetal-${arch}"
    DEPENDS ${swift_stubs_baremetal_objects}
    OUTPUT ${swift_stubs_baremetal_lib_name}
    ALL
    )

  swift_install_in_component(stdlib
    FILES ${swift_stubs_baremetal_lib_name}
    DESTINATION "lib${LLVM_LIBDIR_SUFFIX}/swift_static/${SWIFT_SDK_BAREMETAL_LIB_SUBDIR}/${arch}"
    )
endforeach()
