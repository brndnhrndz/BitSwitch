# BitSwitch

CLI application that converts a given integer from one number system to another.

## Setup Instructions

### BASH Shell

1. Clone or download this repository to your local machine.
2. Ensure the necessary standard libraries are installed.
3. Build the project by running `g++ -o bits ./src/main.cpp ./src/externals.cpp` from the project's root directory.
4. Add `export PATH=$PATH:'path/to/executable.exe'` to your shell's `.bashrc` file located in `~`.
5. Run `source .bashrc` from `~`.

It is recommended that you create a `build` directory within the `BitSwitch` root directory to hold your executable. The path to `build` should replace `path/to/executable.exe`.

## Usage

Invoke with:

`$ bits [src] [target]`

where `[src]` denotes the integer being converted, and is of the form `[[prefix][digits]]`.

`[prefix]` is one of:

| Prefix    | Description   |
| :----:    | :----:        |
| `0b`      | Binary        |
| `0o`      | Octal         |
| none      | Decimal       |
| `0x`      | Hexadecimal   |

and `[digits]` is a sequence of one or more digits belonging to the number system denoted by `[prefix]`. For example, the hexadecimal value `ff` is denoted by `0xff`, and the binary value `1111` is denoted by `0b1111`.

Note that *none* here means **no prefix** is required to represent the corresponding number system.

`[target]` denotes the target number system of the conversion, and is one of:

| Target    | Description   |
| :----:    | :----:        |
| `b`       | Binary        |
| `o`       | Octal         |
| `d`       | Decimal       |
| `x`       | Hexadecimal   |

Example:

    $ bits 0xff d
    > 255

    $ bits 255 x
    > 0xff
