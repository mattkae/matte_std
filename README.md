# Matte Standard Library
A collection of self-written files that I tend to include in every C++ project. This list grows while I work on small side projects, but the modules included are:

- Logger that provides streaming to files and line number reporting
- Mathlib mostly for 3D thing
- Fixed Array implementation
- Hashmap, mostly for strings
- Stack for anything
- Standard tiny types header
- Half-baked string and string builder implementation

## Installation
```sh
make
sudo make install
```

## Usage
```sh
g++ -o <your_exe> <your_cpp_file.cpp> -lmatte
```

```cpp
#include <matte.h>

int main() {
    Logger::initialize({});
    logger_info("Hello world");
    return 0;
}
```