#!/usr/bin/env bash
# usage: run_tests.sh <problem-dir> [--hidden] [--ref]
#   --hidden  also run .hidden/tests
#   --ref     test .hidden/ref.cpp instead of attempt.cpp
set -u
dir=${1:?usage: run_tests.sh <problem-dir> [--hidden] [--ref]}; shift
src=$dir/attempt.cpp
sets=("$dir/tests/visible")
for a in "$@"; do
  case $a in
    --hidden) sets+=("$dir/.hidden/tests") ;;
    --ref) src=$dir/.hidden/ref.cpp ;;
  esac
done

bin=$(mktemp); got=$(mktemp); trap 'rm -f "$bin" "$got"' EXIT
g++ -std=c++20 -O2 -Wall -o "$bin" "$src" || { echo "COMPILE FAIL"; exit 1; }

pass=0; total=0
for s in "${sets[@]}"; do
  for f in "$s"/*.in; do
    [[ -e $f ]] || continue
    total=$((total + 1))
    timeout 5 "$bin" < "$f" > "$got" 2>/dev/null
    if diff -q "$got" "${f%.in}.out" > /dev/null; then
      pass=$((pass + 1)); echo "PASS ${f#"$dir"/}"
    else
      echo "FAIL ${f#"$dir"/}"; diff "$got" "${f%.in}.out" | head -6 | sed 's/^/    /'
    fi
  done
done
echo "$pass/$total passed"
[[ $pass == "$total" ]]
