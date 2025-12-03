#!/usr/bin/env bash
set -eo pipefail

echo "Building binary..."
gcc -std=c11 -O2 -Wall calculator.c -lm -o calculator

failures=0

run_case() {
  op="$1"; a="$2"; b="$3"; expect="$4"; desc="$5"
  out=$(printf "%s\n%s %s\n" "$op" "$a" "$b" | ./calculator 2>&1)
  if echo "$out" | grep -F -- "$expect" >/dev/null; then
    echo "ok - $desc"
  else
    echo "FAIL - $desc"
    echo "  got: $out"
    echo "  expected to contain: $expect"
    failures=$((failures+1))
  fi
}

run_case + 5 3 "= 8.00" "addition"
run_case - 5 3 "= 2.00" "subtraction"
run_case '*' 5 3 "= 15.00" "multiplication"
run_case / 5 2 "= 2.50" "division"
run_case % 5 2 "= 1.00" "modulus"
run_case ^ 2 3 "= 8.00" "power"

# division by zero
out=$(printf "/\n5 0\n" | ./calculator 2>&1) || true
if echo "$out" | grep -F "Error! Division by zero." >/dev/null; then
  echo "ok - division by zero"
else
  echo "FAIL - division by zero"
  failures=$((failures+1))
fi

# invalid operator
out=$(printf "x\n5 3\n" | ./calculator 2>&1) || true
if echo "$out" | grep -F "Error! Operator is not correct." >/dev/null; then
  echo "ok - invalid operator"
else
  echo "FAIL - invalid operator"
  failures=$((failures+1))
fi

if [ "$failures" -eq 0 ]; then
  echo "ALL TESTS PASSED"
  exit 0
else
  echo "$failures test(s) failed"
  exit 2
fi
