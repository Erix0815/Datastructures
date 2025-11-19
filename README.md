# Datastructures (in C)

<a href="">
  <img alt="GitHub branch check runs" src="https://img.shields.io/github/actions/workflow/status/Erix0815/Datastructures/cmake.yml?branch=main&logo=cmake&logoSize=auto&label=Unittests"></a>
<a href="https://erix0815.github.io/Datastructures/">
  <img alt="Website" src="https://img.shields.io/website?url=https%3A%2F%2Ferix0815.github.io%2FDatastructures%2F&up_message=online&down_message=offline&logo=github&logoSize=auto&label=GH-Pages"></a>

Never had a Datastructures-lecture in uni, so I did it myself :)

## Requirements

- `cmake` & `make`
- a C compiler
- `clang-format` & `clang-tidy` 
- `doxygen`

## Makefile

|   target|usage                          |
|--------:|:------------------------------|
|   `demo`|build and run the current demo |
|   `test`|build and execute all unittests|
|  `build`|build the library              |
|    `doc`|generate documantation         |
|    `fmt`|format all code                |
|  `clean`|delete files ignored by git    |
|`install`|build and install the library  |
| `remove`|uninstall the library          |

## Usage

After installing the library you can include it using `#include <mostly-trees/mostly-trees.hpp>`.
Dont forget to also link the library when compiling (e.g.: `-l mostly-trees`).
