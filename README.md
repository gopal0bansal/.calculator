#include <stdio.h>

int main() {
    # Minimal Calculator (C)

    This repository contains a minimal interactive calculator implemented in `calculator.c`.

    Build

    ```sh
    make build
    ```

    Run

    ```sh
    make run
    # or
    ./calculator
    ```

    Supported operators: `+`, `-`, `*`, `/`, `%` (modulus via `fmod`), `^` (power via `pow`).

    Testing

    Run the provided tests:

    ```sh
    make test
    ```

    Notes

    - The program reads an operator (single char) then two numbers. It prints results with two decimal places.
    - Avoid editing both `README.md` and `calculator.c` simultaneously unless you intend to update docs.
