*This project has been created as part of the 42 curriculum by zchauve, mgrossen.*

# push_swap

> Because Swap_push doesn't feel as natural.

---

## Description

**push_swap** is an algorithmic project: given a list of distinct integers, the program
computes and prints the **shortest possible sequence of operations** that sorts them,
using only two stacks (`a` and `b`) and a restricted instruction set.

At start, stack `a` holds the integers (first argument = top of the stack) and stack `b`
is empty. At the end, `a` must be sorted in ascending order (smallest on top) and `b`
must be empty.

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` / `ss` | Swap the first two elements of `a` / `b` / both |
| `pa` / `pb` | Push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both upward (first becomes last) |
| `rra` / `rrb` / `rrr` | Reverse-rotate `a` / `b` / both (last becomes first) |

The goal of the project is to experience **algorithmic complexity** concretely. Our
program embeds **four strategies**, each with a complexity class measured in
**number of push_swap operations generated** (not in CPU time of a classical
array-based sort):

| Flag | Strategy | Complexity (ops) |
|------|----------|------------------|
| `--simple` | Min-extraction (selection sort adaptation) | O(n²) |
| `--medium` | Chunk-based sorting with √n chunks | O(n√n) |
| `--complex` | LSD radix sort (binary, on normalized indices) | O(n log n) |
| `--adaptive` *(default)* | Chooses an internal method based on the measured **disorder** | depends on regime |

Before any move, the program computes the **disorder** of stack `a`: the ratio of
inverted pairs (`a[i] > a[j]` with `i < j`) over the total number of pairs. It is `0`
for a sorted stack and `1` for a fully reversed one.

### Features

- Four selectable strategies (`--simple`, `--medium`, `--complex`, `--adaptive`)
- Disorder metric computed before sorting
- `--bench` mode printing metrics on `stderr`
- Full input validation (`Error\n` on `stderr`)
- Bonus: our own `checker` program

---

## Instructions

### Compilation

```bash
make          # builds push_swap (and libft)
make bonus    # builds the checker
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror`, and the Makefile does not relink.

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers...>
```

- Without any argument, the program prints nothing and gives the prompt back.
- Operations are printed on `stdout`, one per line, separated only by `\n`.
- With `--bench`, metrics are printed on `stderr` after sorting.
- On invalid input (non-integer, out of `int` range, duplicate), it prints `Error\n` on `stderr`.

### Examples

```bash
# Default (adaptive) strategy
$> ./push_swap 2 1 3 6 5 8

# Count operations
$> ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Force a strategy and verify the result
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK

# Benchmark on 500 random numbers
$> shuf -i 0-9999 -n 500 > args.txt
$> ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
OK
$> cat bench.txt
[bench] disorder:  49.93%
[bench] strategy:  Adaptive / O(n√n)
[bench] total_ops: <...>
[bench] sa: 0  sb: 0  ss: 0  pa: <...>  pb: <...>
[bench] ra: <...>  rb: <...>  rr: 0  rra: 0  rrb: <...>  rrr: 0

# Error handling
$> ./push_swap 0 one 2 3
Error
$> ./push_swap 3 2 3
Error
```

### Bonus: checker

```bash
$> ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

`checker` reads operations from `stdin` (one per line), applies them to the stack given
as arguments, and prints `OK` if `a` is sorted and `b` is empty, `KO` otherwise, or
`Error` on `stderr` for invalid arguments or unknown instructions.

---

## Algorithms

### Preprocessing: index normalization

Before sorting, every value is replaced by its **rank** (0 to n−1). Ranks keep the same
relative order as the original values, so the sorting problem is unchanged, but they
are easier to work with: chunk boundaries become simple ranges, and radix sort can work
on non-negative integers with only ⌈log₂ n⌉ bits.

### Small inputs (n ≤ 5)

Tiny stacks are handled by dedicated routines, regardless of the strategy:
- **2 elements:** at most one `sa`.
- **3 elements:** a case analysis over the 6 permutations, at most 2 operations.
- **4–5 elements:** push the 1–2 smallest to `b` (via the shortest rotation), sort the
  3 remaining, then `pa` them back. At most ~12 operations.

### 1. Simple — Min extraction (O(n²))

**Idea:** repeatedly find the smallest element of `a`, bring it to the top using the
shortest direction (`ra` if it is in the upper half, `rra` otherwise), and `pb` it.
When `a` is empty (or holds 3 sorted elements), `pa` everything back: `b` holds the
elements in decreasing order from the top, so `a` ends up sorted.

**Complexity (ops):** for each of the n elements, at most ⌊k/2⌋ rotations on a stack of
size k, then one `pb`; plus n `pa` at the end.
Total ≤ Σ(k/2 + 1) + n ≈ n²/4 + 2n → **O(n²)**.
**Space:** O(n) (the two stacks).

**Why:** simple, provably correct, and very cheap when the stack is almost sorted
(the minimum is usually close to the top, so few rotations are needed).

### 2. Medium — Chunk sort (O(n√n))

**Idea:** split the ranks into about √n consecutive ranges (chunks).
1. **Push phase:** scan `a`; when the top element belongs to the current chunk, `pb` it.
   If it is in the lower half of the chunk, follow with `rb` so that `b` stays roughly
   ordered (bigger values on top, smaller ones at the bottom). Otherwise `ra`. When the
   chunk is exhausted, move to the next one.
2. **Pull phase:** repeatedly locate the maximum of `b`, bring it to the top using the
   shortest rotation direction (`rb` / `rrb`), and `pa` it.

**Complexity (ops):**
- Push phase: each chunk requires at most one full pass over `a` (≤ n rotations), and
  there are √n chunks → O(n√n). Plus n `pb` and at most n `rb`.
- Pull phase: thanks to the chunk ordering in `b`, the current maximum is always within
  about one chunk's distance (≈ √n) from the top or bottom, so each `pa` costs O(√n)
  rotations → O(n√n).
- Total: **O(n√n)**.

**Space:** O(n).

**Why √n chunks?** Fewer chunks make the pull phase expensive (the max is further away);
more chunks make the push phase expensive (more passes over `a`). √n balances both costs.

### 3. Complex — LSD radix sort (O(n log n))

**Idea:** sort normalized ranks bit by bit, from the least significant bit. For each bit:
scan the n elements of `a`; if the bit is `0`, `pb`; otherwise `ra`. Then `pa` all
elements of `b` back. After ⌈log₂ n⌉ passes, `a` is sorted (each pass is stable).

**Complexity (ops):** each pass costs exactly n operations (`pb` or `ra`) plus at most n
`pa`, i.e. ≤ 2n per pass, and there are ⌈log₂ n⌉ passes.
Total ≤ 2n·⌈log₂ n⌉ → **O(n log n)**. A pass is skipped entirely if `a` is already sorted.

**Space:** O(n).

**Why:** deterministic, easy to prove correct, and its cost does not depend on the
input order, which makes it a reliable choice for highly disordered input.

### 4. Adaptive (default)

The adaptive strategy measures the disorder **before any move** and picks a method:

| Disorder | Regime | Method used | Required bound | Achieved bound |
|----------|--------|-------------|----------------|----------------|
| `d < 0.2` | Low | Min extraction (simple) | O(n²) | O(n²) |
| `0.2 ≤ d < 0.5` | Medium | Chunk sort (medium) | O(n√n) | O(n√n) |
| `d ≥ 0.5` | High | Radix sort (complex) | O(n log n) | O(n log n) |

If the stack is already sorted (`d = 0`), nothing is printed. Inputs with n ≤ 5 always
use the small-input routines.

**Threshold rationale:**
- **Low (< 0.2):** few inversions means each element is close to its final position, so
  the min-extraction rotations stay short. In practice it beats the generic algorithms
  here, even though its worst-case bound is O(n²).
- **Medium (0.2–0.5):** the input still has structure, and the chunk approach exploits it
  well (fewer wasted rotations during the push phase).
- **High (≥ 0.5):** the input behaves like (or worse than) a random permutation. A
  random permutation has an expected disorder of about 0.5, which is why we use 0.5 as
  the boundary. Here we want the best asymptotic guarantee, so we use radix sort.

<!-- TODO: adjust this paragraph to your own measurements -->
These thresholds were validated experimentally by generating inputs with controlled
disorder and comparing the operation counts of each strategy.

**Complexity argument:** the disorder computation is O(n²) comparisons in time and O(1)
extra space, but produces **zero** push_swap operations, so it does not affect the
operation-count complexity. In each regime, the operation count is bounded by the
bound of the chosen method (see table). Space is O(n) in every regime.

### Measured performance

<!-- TODO: replace with your own averages (e.g. over 100 runs) -->
| Input size | Strategy | Average ops | Max ops | Target (excellent) |
|-----------|----------|-------------|---------|---------------------|
| 100 random | `--adaptive` | `<...>` | `<...>` | < 700 |
| 500 random | `--adaptive` | `<...>` | `<...>` | < 5500 |

---

## Contributions

<!-- TODO: describe each learner's real contributions -->
- **zchauve:** parsing and error handling, stack operations, simple and medium
  strategies, `--bench` mode.
- **mgrossen:** disorder metric, index normalization, complex strategy, adaptive
  selector, checker (bonus), testing scripts.
- **Both:** algorithm design and complexity analysis, threshold tuning, README.

---

## Resources

### References

- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Stack (abstract data type) — Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
- [Inversion (discrete mathematics) — Wikipedia](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))
- *Introduction to Algorithms* (Cormen, Leiserson, Rivest, Stein), chapters on sorting
  and asymptotic analysis.
- [VisuAlgo — sorting visualizations](https://visualgo.net/en/sorting)

### AI usage

<!-- TODO: make this match what you actually did -->
AI tools were used as an assistant, never as a substitute for understanding:
- **Documentation:** drafting the structure and wording of this README, which we then
  reviewed and corrected against our implementation.
- **Explanations:** clarifying complexity arguments (e.g. why √n chunks balance both
  phases) and checking our reasoning.
- **Testing:** suggesting edge cases for parsing (overflow, `-0`, empty strings, signs).

All algorithm code was written, tested, and reviewed by both of us, and we can explain
every part of it.
