// RUN: %target-build-swift -emit-module -emit-library %S/Inputs/public_var_private_setter.swift
// RUN: %target-build-swift -I . -L . -lpublic_var_private_setter %s -o use_public_var_private_setter

// Baremetal is not supported, as target-build-swift currently tries to perform
// final linking, even with -emit-module
// UNSUPPORTED: OS=none-eabi

import public_var_private_setter

class Class: BaseClass {}
