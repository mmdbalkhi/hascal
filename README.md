
<div align="center">
  <img style="text-align:center" src="hascal-logo.png" height="128px" width="128px">


  # The Hascal Programming Language
  [Website](https://hascal.github.io) |
  [Docs](docs/) |
  [Gitter](https://gitter.im/hascal/community) |
  [LinkedIn](https://linkedin.com/company/hascal-lang)
</div>

**Hascal** is a general-purpose open source programming language that makes it easy to build simple,optimal, reliable, and efficient software.

<!-- > Visit [Hascal's Official Website](https://hascal.github.io) -->
> **NOTE:** Hascal is currently under development.
## Features
- [x] Cross Platform
- [x] Safe
- [x] Easy to learn
- [x] Inspired by Swift, Pascal
- [x] C++ On Back-End
- [x] Fast As C++
- [x] Compatible with C\C++
<!-- - [x] Garbage Collection and Manual Memory Allocation -->

## Examples
Hello World :
```typescript
function main() : int {
    print("Hello World!")
    return 0
}
```
Formatting Strings :
```typescript
function main() : int {
    var name = ReadStr("Enter your name :")
    var fmt_str = format("Hi,",name)
    print(fmt_str)
    return 0
}
```

HTTP Response :
```typescript
use http

function main(): int {
    print(get("google.com"))
    return 0
}
```

System Command :
```typescript
use os

function main() : int {
    system("gcc --version")
    return 0
}
```
> You can see more Hascal examples in [examples folder](https://github.com/hascal/hascal/tree/main/examples).

## Documentation
> You can find Hascal's documentation, [Here](https://github.com/hascal/hascal/tree/main/docs)

## Build from source
> See [build help page](docs/BUILD.md)

## Contributions
Any contribution is welcome :)

![graph](https://contrib.rocks/image?repo=hascal/hascal)

## License
The compiler and the standard libraries are licensed under the **"Boost Software License"**,
Read the [License](https://github.com/hascal/hascal/blob/main/LICENSE) for more details.

## About
Copyright ©2019-2022 **Hascal Foundation**, \
all rights reserved.

[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)
