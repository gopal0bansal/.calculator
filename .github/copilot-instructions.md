<!-- Copilot / AI agent instructions for the minimal calculator repo -->
# Copilot Instructions — .calculator

This repository is a minimal single-file C program. The guidance below is focused on making small, safe contributions and being immediately productive.

- Project Summary: Single C source file at `calculator.c` implementing a simple interactive calculator using `stdio`.
- Build: compile with `gcc calculator.c -o calculator` (recommended flags: `-std=c11 -O2 -Wall`).
- Run: execute `./calculator` and follow stdin prompts.

Key Observations
- There is no build system (Makefile/CMake), no tests, and no CI configured.
- `README.md` currently contains the same C source as `calculator.c` (likely accidental). Do not assume README contains project docs.

What the agent should do first
- Prefer small, reversible changes. Suggest creating a `Makefile` when adding build automation.
- If editing `README.md`, ensure the file becomes documentation (explain build and run). Do not delete the source accidentally.
- Do not introduce external dependencies; keep changes self-contained C or simple tooling.

Coding patterns in this repo (examples)
- Input handling: `scanf(" %c", &operator);` and `scanf("%lf %lf", &num1, &num2);` — be careful: `scanf` is used directly and assumes well-formed input.
- Error handling: division-by-zero is checked explicitly; operator validation falls through to a `default` branch that prints an error.

Safe change suggestions
- Add a `Makefile` with targets: `build`, `run`, `clean`, and `fmt` (if formatting is added later). Example `build` target: `gcc -std=c11 -O2 -Wall calculator.c -o calculator`.
- Improve README.md to contain usage, build instructions, and short explanation of behavior (examples of input/expected output).
- When improving input parsing, prefer robust handling (e.g., read a full line with `fgets` then parse) rather than changing global program structure.

Testing & debugging
- No test harness exists. For small behavior changes, add a `tests/` directory with bash-based tests that run the binary with heredoc inputs and assert output (keeps tooling minimal).
- Debug with `gdb ./calculator` or run with `valgrind` for memory checks if you add more stateful code.

Commit / PR guidance
- Keep changes tiny and well-scoped. Use clear commit messages like: `chore: add Makefile` or `fix: handle invalid numeric input`.
- When altering `README.md`, include a short rationale in the PR description because current README contains source code.

Files to reference when making changes
- `calculator.c` — primary program logic (operator switch, I/O).
- `README.md` — currently mirrors source; update to documentation if modified.

When to ask the human
- If you plan to add third-party tooling (formatters, test frameworks), ask before adding to the repo.
- If you want to rework input handling or change the user-facing prompts, confirm desired UX (interactive vs CLI args vs non-interactive tests).

If you update this file
- Preserve these project-specific notes; add any new conventions introduced by future work (Makefile targets, test commands, CI steps).

Thanks — please ask for clarification when changes will affect the user's workflow (build/run/test).
