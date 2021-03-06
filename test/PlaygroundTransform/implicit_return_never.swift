// RUN: %empty-directory(%t)
// RUN: cp %s %t/main.swift
// RUN: %target-build-swift -Xfrontend -playground -Xfrontend -disable-playground-transform -o %t/main %t/main.swift
// RUN: %target-codesign %t/main
// RUN: ! %target-run %t/main --crash 2>&1 | %FileCheck -check-prefix=CRASH-CHECK %s
// REQUIRES: executable_test

// NOTE: "!" is used above instead of "not --crash" because simctl's exit
// status doesn't reflect whether its child process crashed or not. So "not
// --crash %target-run ..." always fails when testing for the iOS Simulator.
// The more precise solution would be to use a version of 'not' cross-compiled
// for the simulator.

func f() -> Int {
    fatalError()
}

f()
