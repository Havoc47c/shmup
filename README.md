# shmup
Simple shoot em up game using sfml.

Learning Objectives:
1. Exploration.
    1.1. Make various design decisions, accumulate technical debt, and learn from
         the painful experience of having to fix it. Struggle is a good teacher.
         Decisions will not be made willy nilly, but will be made quickly so as
         to keep up momentum and achieve goal 2.
    1.2. Play around with C++17 and try all the new features.
2. Data oriented design.
    1.1. Learn how things like virtual instructions, cache misses, and memory
         contiguity affect performance.
    1.2. Make an incredibly simple system which uses all things virtual and 
         relies on large amounts of pointer indirection.
    1.3. After badly performing system is built, attempt to design a DoD system,
         which outperforms the previous system. Design various versions to see
         performance trade-offs.
