*This activity has been created as part of the 42 curriculum by lherpet, ytrabels.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using only two stacks (`a` and `b`) and a restricted set of operations, while minimizing the total number of operations used.

The project explores algorithmic complexity in a concrete way: the same input sorted by different strategies can produce wildly different operation counts. The program selects a strategy automatically based on how disordered the input is, or lets you force one explicitly.

## Instructions

### Compilation

```bash
make
```

This produces the `push_swap` binary. Standard Makefile rules are available: `make`, `make clean`, `make fclean`, `make re`.

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <integers...>
./push_swap --bench [--simple | --medium | --complex] <integers...>
```

**Strategy flags (optional):**

| Flag | Algorithm | Complexity |
|------|-----------|------------|
| `--simple` | Insertion sort | O(n²) |
| `--medium` | Chunk-based sort | O(n√n) |
| `--complex` | Radix sort | O(n log n) |
| `--adaptive` | Auto-select based on disorder | varies |

If no flag is given, the adaptive strategy is used by default.

**Benchmark mode (`--bench`):** Prints to stderr the disorder percentage, strategy used, total operation count, and per-operation breakdown. The operation stream on stdout remains usable with a checker.

### Examples

```bash
# Sort 6 numbers (adaptive, default)
./push_swap 2 1 3 6 5 8

# Force O(n²) insertion sort
./push_swap --simple 5 4 3 2 1

# Force radix sort and verify with checker
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG

# Benchmark on 500 numbers
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
cat bench.txt
```

### Error handling

The program prints `Error` to stderr and exits if:
- Any argument is not a valid integer
- An integer is outside the `int` range
- Duplicate values are present

## Algorithms

### Disorder metric

Before sorting, the program computes a **disorder score** between 0 and 1. It counts the number of "inversions" (pairs where a larger value appears before a smaller one) divided by the total number of pairs. A score of 0 means already sorted; 1 means fully reversed.

This metric drives the adaptive strategy selection.

### Simple — Insertion sort — O(n²)

For each step, the minimum value remaining in stack `a` is located, rotated to the top (choosing the shortest rotation direction), and pushed to `b`. Once all elements are in `b`, they are pushed back to `a`.

**Justification:** Simple and correct. Each element requires at most O(n) rotations to reach the top, and we repeat this n times → O(n²) total operations. Efficient only for small or nearly sorted inputs.

### Medium — Chunk-based sort — O(n√n)

The value range is divided into ~√n chunks (5 chunks for n≤100, 11 for n>500). Elements are pushed to `b` chunk by chunk. Within each chunk, elements below the chunk midpoint are immediately rotated to the bottom of `b` (placing smaller values deeper). After all pushes, `insertion_max` pulls elements back to `a` in descending order by always finding and rotating the maximum to the top of `b`.

**Justification:** Each chunk push pass scans O(n) elements, done √n times → O(n√n) push operations. The pull-back phase is also O(n√n) in the worst case.

### Complex — Radix sort — O(n log n)

Values are first normalised to contiguous ranks [1..n]. Then a bitwise LSD radix sort is applied: for each bit position (from LSB to MSB, log₂n bits total), elements with bit=0 are pushed to `b`, elements with bit=1 stay in `a` via rotate, then all of `b` is pushed back to `a`. After log₂n passes the stack is sorted.

**Justification:** log₂n passes, each O(n) → O(n log n) total operations. Predictable and input-independent performance.

### Adaptive — disorder-driven selection

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 20% | Insertion sort | O(n) effective (few inversions) |
| 20% – 50% | Chunk-based sort | O(n√n) |
| ≥ 50% | Radix sort | O(n log n) |

**Threshold rationale:**
- Below 20% disorder, the list is nearly sorted. Insertion sort's inner loop almost never needs to scan far, making it behave close to O(n) in practice.
- Between 20% and 50%, the list has moderate disorder. Chunk sort handles this range efficiently without the overhead of a full bitwise sort.
- Above 50%, the list is heavily shuffled. Radix sort's consistent O(n log n) behaviour and independence from element distribution make it the best choice.

A special case: for exactly 3 elements, a dedicated `sort_three` function handles all 5 non-trivial permutations with at most 2 operations.

## Performance

| Input size | Target (pass) | Target (good) | Target (excellent) |
|------------|--------------|---------------|--------------------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

## Resources

- [Sorting algorithms visualised](https://visualgo.net/en/sorting)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Big-O cheat sheet](https://www.bigocheatsheet.com/)
- Knuth, D. E. — *The Art of Computer Programming, Vol. 3: Sorting and Searching*

**Use of AI:** Claude (Anthropic) was used to help write and review this README. All algorithmic choices, thresholds, and code were designed and implemented by the team; AI was not used to generate any C source code.

## Contributors

| Login | Contributions |
|-------|--------------|
| `lherpet` | Chunk-based sort, radix sort, benchmark system, operations, normalisation |
| `ytrabels` | Insertion sort, parsing, list utilities, 3-element sort, main entry point |
