# Minimal Calculator

A simple interactive calculator implemented in C, with a web interface option.

## Features

- Supports basic arithmetic operations: `+`, `-`, `*`, `/`, `%` (modulus), `^` (power)
- Interactive command-line interface
- Web interface available in the `web/` directory

## Build and Run

### Command Line Version

```bash
# Build
make build
# or manually
gcc -std=c11 -O2 -Wall calculator.c -o calculator -lm

# Run
make run
# or
./calculator
```

### Web Version

The `web/` directory contains a Flask-based web calculator.

```bash
cd web
pip install -r requirements.txt
python app.py
```

## Testing

Run the test suite:

```bash
make test
```

## Usage

For the CLI version:
- Enter an operator (+, -, *, /, %, ^)
- Enter two numbers
- Result is displayed with two decimal places

## Contributing

Feel free to open issues or pull requests.

## License

This project is open source. See LICENSE for details.
