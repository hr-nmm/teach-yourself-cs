# Ch-6: Under the C: Diving into Assembly Language

- Before the invention of compilers, Assembly lang was the closest a programmer gets to coding at the ma­chine level without writing code directly in 1s and 0s.

- Compiler translates human-readable syntax into machine code(0's and 1's) using :

  - PL rules.
  - OS specifications.
  - ISA of the machine.

- Why should we learn assembly?
  1. Higher-Level Abstraction Hides Valuable Program Details.
  2. Computers(like washing machine,coffee machine, embedded systems) are too resource constrained for compilers(due to small processors) and hence cannot execute compiled code written by high level langs, thus programmed by assembly.
  3. For Finding Vulnerabilities in systems, and reverse engineering malicious code.
  4. There are some components of a computer system that just cannot be optimized sufficiently by compilers and require handwritten assembly.
