#include <stdio.h>
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

Supported operators:
- Binary: `+`, `-`, `*`, `/`, `%` (modulus via `fmod`), `^` (power via `pow`).
- Unary: `sqrt` (or `s`) and `fact`/`factorial` (or `!`).

CLI mode

You can run the program non-interactively:

```sh
# binary operator: op num1 num2
./calculator ^ 2 3
# unary operator: op num1
./calculator sqrt 9
./calculator fact 5
```

Testing

Run the provided tests:

```sh
make test
```

Notes

- The program reads an operator (symbol or spelled name) then one or two numbers depending on operator. It prints results with two decimal places.
- Avoid editing both `README.md` and `calculator.c` simultaneously unless you intend to update docs.
