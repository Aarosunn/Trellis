# Interview track: DSA + system design under a deadline

A second loop, distinct from the learncpp/Beej sequential loop. Read this fully when a
session targets `dsa.*`, `lc.*`, or `sdp.*` IDs.

Why it exists at all: recruiting is an **external deadline** (late September 2026).
Everywhere else Trellis picks lazily and refuses forward plans, because a plan you fall
behind on becomes a debt object that kills motivation. A deadline changes that
calculus — RC4 is literally "defer review until the exam makes the cost visible, then
cram," and a cadence is the correct answer to RC4. See roadmap.md's settled-decisions
section for the exception and its limits.

## The deadline and the budget

Recruiting opens late September 2026. Track started 2026-07-30. ~8 weeks.

**Weekly quota — slot types, never weekday assignments:**

| Slots | Type |
|---|---|
| 4 | problem (one new problem + one due re-attempt) |
| 1 | DSA concept (only for patterns ranked rocky) |
| 1 | system design |

6 interview slots/week. learncpp is **deliberately outside this quota** — ad hoc,
low stakes, whenever the learner feels like it. Do not schedule it, do not count it,
do not nag about it.

**What "quota not calendar" means mechanically:** there is no assigned content per
weekday. A missed day accumulates nothing — there is no backlog object, only a weekly
count that got hit or didn't. Never tell the learner they are "behind on Tuesday's
topic." That sentence recreates the rejected pattern.

Total ≈ 34 problems, 8 concept slots, 8 system design slots. State the volume tradeoff
honestly if it comes up: 34 problems is thin coverage and buys derivation skill instead
of recognition coverage. It does **not** provide a safety net for drawing a common
question they haven't seen. That was a chosen tradeoff, not an oversight.

## Ranking pass (replaces the placement quiz here)

Run once, at track start. The learner rates each concept 1–5 on *implementation*
confidence, not theory. One number each, no quizzing.

This deviates from the placement-quiz default for a documented reason: RC1 says this
learner's *monitoring* is accurate and it is the control link that breaks, so a
self-rating is unusually trustworthy here. 22 placement quizzes before any learning
starts would also be its own procrastination ritual.

But it is **not** self-certification, because the failure mode being targeted —
"I know the theory, not the implementation" — is by definition an illusion-of-competence
zone. Evidence from 2026-07-29: predicted 2/3 on learncpp.0.13, scored 1/3.
Overconfidence shows up precisely on sort-of-know material.

So: **the rank sets teach depth; the problem is the check.**

- Ranked 1–2 (rocky) → gets a DSA concept slot before problems.
- Ranked 3+ → straight to problems, no reteach.
- Stalls on implementation during a problem → that is the teach signal, earned by
  evidence. Demote the rank, log it, schedule a concept slot.

**What a concept slot is, now:** not Trellis teaching the technique inline. Trellis
names the technique and points to 1–2 resources — searched and verified at the time the
slot fires (never a stale hardcoded list, never guessed from memory), an article plus
optionally one video capped at 30 minutes. The learner consumes independently, then
goes straight into the problem slot as the check, unchanged. If the search can't turn
up something solid, say so plainly rather than pointing to something mediocre.

Log as `{"type":"concept","id":"dsa.two-pointers","kind":"skill","self_rank":2}`.

Relevant calibration fact, surface it once and then drop it: 281 finished ~March 2026
(4 months before track start), not years ago. Verified recent coursework. The learner
described this as "ages" and asked to be retaught everything — that is RC1 setting
depth by anxiety rather than evidence. Reteach the rocky ones. Do not sweep all 22.

## The six moves (the generative set)

The learner's goal is explicit: derive solutions to unseen problems, not recognize seen
ones. So techniques are organized by underlying move, not as a catalog to match against.

| Move | Techniques it generates |
|---|---|
| Remember instead of recompute | hashing, prefix sums / difference arrays, memoization |
| Exploit order or monotonicity | two pointers, binary search *including on the answer*, sorting as preprocessing |
| Update incrementally, don't rebuild | sliding window, rolling state |
| Explore state space systematically | DFS, BFS, backtracking (DFS + undo), topological sort, Dijkstra |
| Maintain partial order cheaply | heap (top-k, streaming), monotonic stack (next-greater, deferred decisions), union-find |
| Prove the local choice is safe | greedy + exchange argument, interval scheduling |

Plus **DP** (state, transition, base case — memoized recursion before tabulation) and
**bitmask** (state compression, not tricks).

Underneath sits a fluency layer that is not "patterns" and must become automatic:
arrays/strings in place, hash map/set, linked-list pointer surgery, stack/queue/deque,
heap, BST (`std::map`/`set`), adjacency-list graphs.

When pointing to a resource for a technique, prefer one that frames it as *a move
applied to a data shape*. The test of understanding is "what redundancy does this
kill," never "what is this called."

## Problem slots

**Source pool:** NeetCode 150, used as a quality filter with its grouping **stripped**.
The pool is curated; its organization is the enemy. Never surface which pattern a
problem belongs to, and never work a pattern's problems consecutively.

**Two hard delivery rules:**

1. **Unlabeled.** Never name the pattern, technique, or move up front. "This is a
   sliding window problem" ends the reasoning before it starts. If asked directly what
   pattern it is, that is a hint request — price it (rung 1 at minimum).
2. **Interleaved.** Consecutive problems deliberately cross moves. Blocked practice
   (several sliding-window problems in a row) is the single most reliable way to build
   the match reflex the learner is trying not to build.

### The derivation gate

Before any code, the learner produces:

1. The brute force, and **specifically what it recomputes** — the wasted work named
   concretely, not "it's O(n²)."
2. What would have to be true for something cheaper to exist (an invariant, an ordering,
   a reusable partial result).
3. The approach and its complexity, predicted before implementing.

Silence-first applies (contract 1): no hint, no nudge toward a technique, until an
attempt artifact exists. "No idea, my guess is X" is an artifact. "I don't know" is not
— shrink the problem instead of answering it.

Only after the gate: write the code. C++ on first attempt, always.

### After a correct solution

Two mandatory questions. These are the matcher detector — someone who pattern-matched
or recalled a shape cannot answer the second one:

1. Why does this work? (the invariant, stated)
2. **What input breaks it?** (or: what changes if a constraint moves)

### Grading

Contract 4 governs and it is already the anti-pattern-matching mechanism, verbatim:
*right answer + pattern-matched reasoning scores below wrong answer + sound model with
one slipped step*. Solved-by-recognition is not a pass. Say so plainly when it happens.

Log:
```json
{"ts":"...","type":"problem","id":"lc.11","move":"two-pointers","lang":"cpp","derivation":"pass","solved":true,"review_after":"2026-08-06"}
```
`move` is recorded for interleaving bookkeeping and is **never shown to the learner**
before or during a problem.

Intervals: derivation pass + solved → +7d · solved but derivation failed → +3d ·
unsolved → +2d · any rung-3 hint → +2d.

## Dual-language spaced repetition

First attempt is C++. The scheduled re-attempt is **Python**. Same problem, different
language.

This is the anti-memorization mechanism: the pattern is stable but the surface changes,
so recalling the C++ source text does not carry the re-attempt. It also exercises both
languages' idioms, which the learner wants independently.

On a re-attempt: the derivation gate runs again, briefly. If they reproduce the solution
without being able to restate the invariant, that is a fail regardless of whether the
code runs — log a nugget and reset the interval.

```json
{"ts":"...","type":"review","item":"lc.11","lang":"py","grade":3,"self_grade":2,"next":"2026-08-20"}
```

## System design slots

**Source:** System Design Primer (github.com/donnemartin/system-design-primer) — free,
open source, heading-structured, live-fetchable, so `ingest` works unmodified.

Chosen over DDIA deliberately, reversing an earlier recommendation in this same design
session. The reasoning, so it is not relitigated: DDIA is the better book and builds
real first-principles reasoning, but the learner is applying to **intern** roles, wants
breadth over depth, and may not pursue SWE long-term — which collapses DDIA's
payoff horizon to interview value alone, where SDP wins outright. Also 8 slots
*finishes* SDP and leaves DDIA stranded two-thirds through; a completed shallow pass
beats an abandoned deep one (RC3). The learner owns a DDIA PDF; it is optional depth
later, not the spine.

Eight slots, eight coarse concepts (`sdp.1`–`sdp.8`) — deliberately coarse, because a
60-subsection ingest would create a backlog that contradicts the 8-slot plan.

**Delivery — design first, then diff.** SDP's eight worked design questions are its
memorization trap: read "design Twitter" and you have stored an answer, not a method.
So:

1. Learner gets the problem statement only.
2. Learner produces their own design — **3–4 sentences**, not an essay, not a diagram,
   not an implementation. Practice here is a comprehension check, not a build.
3. *Then* the primer's solution is revealed, and they diff it against theirs.
4. The learning is in the diff. Ask what the primer accounted for that they didn't, and
   whether they disagree with any of it.

The reveal in step 3 is the primer's actual text/link, not a Trellis paraphrase — same
curation-not-authoring principle as the DSA concept slots above and the sequential
learncpp track. If a slot needs background before the problem statement even makes
sense (a term the learner hasn't hit yet), point to the relevant SDP page for that too,
rather than explaining it inline.

Practice weight is deliberately low here — the learner asked for consistency over
intensity on system design, and that is accepted. But it is never zero: consuming
system design content without producing a design is RC2 exactly, and it is the highest
feels-productive / lowest-retention material that exists. The 3–4 sentence artifact is
the floor, not negotiable.

Latency numbers and the powers-of-two table are worth rote familiarity — the one place
in this whole track where memorization is the correct goal. Say so, so it doesn't read
as a contradiction.

## Dashboard for this track

Print before anything else, same as the sequential loop. Table first, one row per
status — domain, status, count, topics — then the 3-line quota summary. Topics column
uses topic names, not internal ids (`dsa.*`, `sdp.*`), except `lc.*` problem numbers,
which stay as-is:

| Domain | Status | Count | Topics |
|---|---|---|---|
| Problem | Solved | N | lc.… |
| Problem | Due | N | lc.… (date) |
| Concept | Taught | N | topic names |
| Concept | Due for review | N | topic names |
| Concept | Rocky remaining | N | topic names |
| Sysdesign | Done | N | topic names |
| Sysdesign | Remaining | N | topic names |

```
Trellis — interview track     (week N of 8, ~M weeks to recruiting)
problems: N done · N due     concepts: N rocky remaining     sysdesign: N of 8
this week: problem N/4 · concept N/1 · sysdesign N/1
```

Show the weekly quota as counts hit, never as days missed.

**On-demand calendar view.** General mechanic, see `SKILL.md`'s Standing Behaviors —
applies here unchanged. Example format for this track:
```
07/29  dsa.meta — rocky-rank triage decided (RC1 flag)
07/31  dsa.monotonic-stack — taught
08/01  lc.128 — solved
08/03  dsa.monotonic-stack — due today
08/08  lc.128 — due
```
Does not replace the 3-line quota dashboard above, which still prints first, every
session.

## What is deliberately not here

Codeforces, CSES, company-specific lists, mock interviews, behavioral prep. All were
raised and cut in the design session on 2026-07-29 — scope, not merit. Do not add any
of them before the deadline without a specific named gap. Revisit after late September.
