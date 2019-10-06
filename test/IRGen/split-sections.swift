// TODO: COFF (windows) support
// Check that when compiled without -function-sections or -data-sections, the result contains a single .text and .bss section
// RUN: %target-swiftc_driver -c %s -o %t
// RUN: llvm-readelf -S %t | %FileCheck %s -check-prefix CHECK-%target-object-format
// CHECK-elf-COUNT-1: .text
// CHECK-elf-COUNT-1: .bss
// CHECK-macho-COUNT-1: Name: __text

// Check -function-sections option creates one .text section per function.
// RUN: %target-swiftc_driver -c %s -Xfrontend -function-sections -o %t-fs
// RUN: llvm-readelf -S %t-fs | %FileCheck %s -check-prefix CHECK-FUNCTION-SECTIONS-%target-object-format
// CHECK-FUNCTION-SECTIONS-elf: .text.$s4main13firstFunctionyyF
// CHECK-FUNCTION-SECTIONS-elf: .text.$s4main14secondFunctionyyF
// CHECK-FUNCTION-SECTIONS-macho-COUNT-1: Name: __text
func firstFunction() {}
func secondFunction() {}

// Check -data-sections option creates one .bss section per global variable.
// RUN: %target-swiftc_driver -c %s -Xfrontend -data-sections -o %t-ds
// RUN: llvm-readelf -S %t-ds | %FileCheck %s -check-prefix CHECK-DATA-SECTIONS-%target-object-format
// CHECK-DATA-SECTIONS-elf: .bss.$s4main13firstVariableSivp
// CHECK-DATA-SECTIONS-elf: .bss.$s4main14secondVariableSivp
// CHECK-DATA-SECTIONS-macho-COUNT-1: Name: __text
var firstVariable = 1
var secondVariable = 2
