# EECS 482 — Introduction to Operating Systems (FA26, Peter Chen)

Skill: `trellis`. Everything below is class-specific input to it.

## State
Repo: `Aarosunn/Trellis` · path: `classes/eecs482/state.md` · tool: GitHub MCP (`get_file_contents` / `create_or_update_file`).
If the tool is absent, ask me to paste `state.md`. Never search past chats for it.

## Knowledge
- `syllabus.md` — schedule + readings by week.
- `ospp-chNN.pdf` — Anderson & Dahlin, *Operating Systems: Principles and Practice* 2e, one file per chapter, exercises at the end of each. Ch 10 not assigned.
- `EECS482LecN.pdf` — Chen's slides. Every "Problem?", "Does this work?", "Possible outputs? Impossible outputs?" on a slide is a probe target. Slides beat textbook when they differ.
- `sp26-mtN-solutions.pdf` — Berkeley CS162 Spring 2026 midterms 1–3 with solutions. **Calibration only.** Same textbook lineage; use them for question *form* and difficulty, not topic coverage.
- Lab pre-lab / HW questions when posted — in-house practice, highest priority when present.
- Project handouts — for terminology and spec understanding only (see Projects).

## Exam profile
- Two exams, 30% each. Midterm **Oct 26, 5:00–6:50 pm** (scope: weeks 1–8 — threads, concurrency, address spaces). Final **Dec 15, 10:30–12:20** (cumulative + scheduling, file systems, networking, distributed).
- In person, own laptop, Safe Exam Browser → **typed answers**. Assume closed book unless the course page says otherwise.
- Question forms, from CS162 and Chen's slides:
  1. **True/False + explain in ≤2 sentences.** No explanation → no credit. Distractor space: a claim that's true under one assumption (uniprocessor, Hoare semantics, same address space) and false under the course's default.
  2. **Choose-all-that-apply** with a one-line reason per option.
  3. **Interleaving reasoning**: "what outputs are possible / impossible", "which context-switch point breaks this and how", "give a schedule that produces X".
  4. **Fix-the-code**: numbered lines of a lock / monitor / thread routine; identify the race, the busy-wait, the missing wait loop, the premature free; rewrite ≤ 5 lines.
  5. **Write the monitor**: readers-writers, bounded buffer, fair lock, barrier — state variables, one lock, CVs, `while` around every wait. Short, ≤ 25 lines, C++-ish pseudocode.
  6. **Numeric** (post-midterm): page-table size, TLB/miss cost, scheduling response/turnaround, disk/RAID throughput. Show arithmetic.
  7. **Short justification**: why design X over Y, 2–3 sentences.
- Tiers: T2-heavy. T0/T1 = interleaving prediction and T/F. T2 = fix-the-code, switch-point analysis. T3 = write the monitor / numeric with justification.
- 482 vs CS162 content filter: **no Pintos, no futex, no POSIX signal/fork/exec API trivia, no GDB, no x86 ring/CPL details** unless a 482 slide covers it. Concurrency in 482 is the course's C++ thread library model: `mutex`, `cv` with Mesa semantics, `thread`, `yield`.

## Traps (build distractors from these)
- "possible" ≠ "will happen": any interleaving of atomic steps counts; load/store are atomic, `x += 1` is not
- check-then-act is not atomic — a note is not a lock (Too Much Milk #0–#2)
- `while (!cond) cv.wait(lock)`, never `if` — Mesa semantics, spurious/late wakeups
- wait must release the lock atomically and reacquire before returning; signal/broadcast with the lock held (course convention)
- signal vs broadcast: wrong one → lost wakeup or thundering herd
- busy-wait vs block: spinning consumes the CPU the other thread needs; correct but wrong
- lock hold time: minimize, but never release mid-invariant
- deadlock needs all four conditions; break one; lock ordering is the usual fix
- per-thread (stack, PC, registers) vs shared (heap, globals, code); pointer *values* into the heap are shared, addresses of locals are not
- unblocked ≠ running: I/O completion puts the thread on the ready queue
- process ≠ program; thread ≠ process; one address space per process, many threads
- disabling interrupts ≠ mutual exclusion on a multiprocessor
- context switch saves registers + address-space root; things in memory don't need saving
- heap is contiguous in virtual memory, not physical

## Visual rule
ASCII is fine and expected: thread timelines, interleavings as numbered step columns, stack/heap diagrams, page-table layouts, queue pictures. Monitor code in fenced C++ blocks with numbered lines when the question refers to lines.

## Projects
Explain handouts, terminology, and general C++/POSIX syntax on request. **No project design, no project code, no debugging of project code** unless I say "project help ok" in that chat. Default: redirect to the underlying node. Never accept pasted handout text for solution work — honor code.

## Node list — threads & concurrency (weeks 1–6, midterm scope part 1)

| node | ceiling | source |
|---|---|---|
| os-roles | T1 | lec 1: abstraction + resource management; who calls whom |
| process-thread-addrspace | T1 | lec 2 |
| per-thread-vs-shared | T2 | lec 2; CS162 MT1 2d |
| interleaving-outcomes | T2 | lec 2–3: possible / impossible outputs |
| atomicity | T2 | lec 2–3 |
| critical-section | T2 | lec 3 |
| too-much-milk | T2 | lec 3: why #0–#2 fail, why #3 works, why #3 is bad |
| lock | T3 | lec 3, ch 5 |
| lock-granularity | T2 | lec 3: hold time vs correctness |
| cv-wait-loop | T3 | ch 5 |
| monitor-pattern | T3 | ch 5: state vars + one lock + CVs |
| signal-vs-broadcast | T2 | ch 5 |
| semaphore | T2 | ch 5 |
| producer-consumer | T3 | ch 5 |
| reader-writer | T3 | ch 5; CS162 MT1 P5 |
| deadlock | T3 | ch 6.5: 4 conditions, prevention, avoidance, detection |
| thread-impl | T3 | ch 4: TCB, ready queue, context switch, yield, create/delete |
| lock-impl | T2 | ch 5.7: disable interrupts, test-and-set, spin vs block |
| user-vs-kernel-threads | T2 | ch 4.7–4.8 |
| scheduling-basics | T2 | ch 7: FIFO, SJF, RR, MLFQ; response vs turnaround |

Address spaces (ch 8–9, 11–12), scheduling detail, file systems (ch 13–14), networking, distributed: added by `cut` when the chapter is uploaded.

## Skip
1.3 history (T0 only) · 2.10 VMs · 6.1–6.3, 6.6 unless a slide covers them · 7.3–7.6 unless a slide covers them · project logistics slides · EECS 408 material · Pintos / futex / GDB / POSIX API content in the CS162 exams.

## Calendar
```
week   dates        topic                       readings (OSPP)
1      08/31        Introduction                1–1.1, 1.3, 2–2.1, 4–4.2, 4.9
2      09/07        Threads & concurrency       5–5.4
3      09/14        Threads & concurrency       5.5–5.6, 5.8
4      09/21        Threads & concurrency       4.3–4.8
5      09/28        Threads & concurrency       5.7, 6.4–6.5, 7
6      10/05        Threads & concurrency       —
7      10/12        Address spaces              8, 9–9.5, 9.7
8      10/19        Address spaces              —
MIDTERM 10/26 5:00–6:50 pm                      + 2.2–2.9, 3–3.3 assigned this week
9      11/02        Address spaces              11–12
10     11/09        CPU scheduling; file systems 13–14, 3.4–3.5
11     11/16        File systems                —
12     11/23        File systems; networking    —
13     11/30        Distributed systems         —
14     12/07        Case studies                —
FINAL  12/15 10:30 am–12:20 pm
```
Projects: P1 concurrent program (individual), P2 thread manager, P3 virtual memory manager, P4 multi-threaded network file system. Last autograder submission 12/13.
`prime` with no topic → next week's readings. `exam` with no topic → next exam's scope.
