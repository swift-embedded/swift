# Swift for Embedded Systems [![Build Status](https://jenkins.dragomirecky.com/job/swift-embedded/job/swift/badge/icon)](https://jenkins.dragomirecky.com/job/swift-embedded/job/swift/)

This is a fork of the [apple/swift](https://github.com/apple/swift) repository, enabling Swift to be used on bare metal.

<img align="right" width="300px" src="https://user.fm/files/v2-a0064b7c4454e814827266d1166a54b0/podklad_oprava_lower_quality.jpg" />

This fork adds support for a new "baremetal" platform to the toolchain, currently focusing on the thumbv7-m and thumbv7-em architectures. Support for the new platforms was also added to the [Swift Package Manager](https://github.com/apple/swift-package-manager) and [sourcekit-lsp](https://github.com/apple/sourcekit-lsp) (both those tools are built and shipped as part of the "baremetal toolchain").

> This project is in an early phase, and there is still a lot to work on. Also, if you want to know more about the process of porting Swift to embedded systems, feel free to check out my thesis [Swift for Embedded Systems](https://dspace.cvut.cz/bitstream/handle/10467/82498/F8-DP-2019-Dragomirecky-Alan-thesis.pdf).

## Supported Boards

The toolchain itself should be able to target any microcontroller using one of the architectures mentioned above. However, any practical embedded application is going to require a package providing access to hardware peripherals. I am currently focusing on supporting the STM32F4 family of microcontrollers – the [stm32](https://github.com/swift-embedded/stm32) Swift package provides access to the basic hardware peripherals of those microcontrollers, such as UART, SPI or GPIO.

Also, to make building an embedded application as simple as possible, I have created the [cross](https://github.com/swift-embedded/cross) command-line utility. It handles all the things as setting up a linker script or using the right compiler flags, making compiling an app a simple one-liner – `swift run cross build` (currently supporting the [NUCLEO-F439ZI](https://www.st.com/en/evaluation-tools/nucleo-f439zi.html) only).



## Getting Started

1. Download the latest build of the toolchain from [here](https://jenkins.dragomirecky.com/job/swift-embedded/job/swift) and untar it to one of `/Library/Developer/Toolchains/` or `~/Library/Developer/Toolchains/`:

    ```bash
    $ sudo tar -xzf swift-LOCAL-YYYY-MM-DD-a-osx.tar.gz -C /
    ... or ...
    $ tar -xzf swift-LOCAL-YYYY-MM-DD-a-osx.tar.gz -C ~/
    ```

2. Activate the toolchain with:

    ```bash
    export TOOLCHAINS=baremetal-toolchain.YYYYMMDD
    ```

3. Check that `swift` and other command-line utilities now reference the newly downloaded toolchain.

    ```bash
    $ xcrun -f swift
    /Library/Developer/Toolchains/swift-LOCAL-2019-10-10-a.xctoolchain/usr/bin/swift
    ```
    
4. Done! Now, have a look at some examples in the [swift-embedded/examples](https://github.com/swift-embedded/examples) repository.


