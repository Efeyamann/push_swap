# push_swap

An algorithmic project that sorts a stack of numbers using a limited set of operations, following the rules of the **42 push_swap** project.

## Overview

The `push_swap` project is part of the 42 curriculum and focuses on sorting algorithms, stack manipulation, and algorithmic efficiency. The goal is to sort a stack of numbers with the fewest possible moves using only specific operations.

## Features

- Implements an efficient sorting algorithm for a stack of numbers.
- Uses a limited set of operations:
  - `sa` → Swap the first two elements of stack A.
  - `sb` → Swap the first two elements of stack B.
  - `ss` → Perform `sa` and `sb` simultaneously.
  - `pa` → Push the top element from stack B to stack A.
  - `pb` → Push the top element from stack A to stack B.
  - `ra` → Rotate stack A upwards.
  - `rb` → Rotate stack B upwards.
  - `rr` → Perform `ra` and `rb` simultaneously.
  - `rra` → Reverse rotate stack A.
  - `rrb` → Reverse rotate stack B.
  - `rrr` → Perform `rra` and `rrb` simultaneously.
