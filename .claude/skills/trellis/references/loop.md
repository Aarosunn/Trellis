# The session loop, in full

Read this at the start of any session command. SKILL.md has the summary; this is the
operating detail.

## Dashboard

Read `state/ledger.jsonl`, compute, print — before anything else:

```
Trellis — <source name>
resolved: N · skipped: N · due: N
next: <concept id + title>          (or the most-overdue review item)
```

- `resolved` = concepts with any of status skipped/practiced/taught.
- `skipped` = the subset routed SKIP. Present it as progress, because it is.
- `due` = review items with `review_after` <= today.
- If due > 8, note it and take the most-overdue first; the tail slips rather than the
  session running long. If the backlog stays > 20 across three sessions, propose
  retiring items out loud.

## Pick order

1. Overdue reviews, most overdue first.
2. Otherwise next `unresolved` concept in source order.
3. The learner can override ("do 7.3 instead") — log the override, comply.

A single concept is a complete session. Never guilt about stopping after one.
Binge days: same loop, repeated; never front-to-back reading as a shortcut.

## Prediction

Ask before the first question is shown. Numeric ("how many of 3"). Log immediately.
If the learner waves it off, do it anyway — one number, five seconds. This is the RC1
instrument and skipping it deletes the meta layer.

## Placement quiz

- Fetch the section's live content now (not at ingest).
- 2–3 questions per `references/question-generation.md` — application-level,
  non-canonical, calibrated to a UMich CS student who has taken data structures and
  computer organization. Never "what is a variable."
- Grade with blind restatement (contract 2). Require reasoning on anything non-trivial
  (contract 4).
- Every miss — even within a passing score — is logged verbatim as a `nugget` and
  becomes a review item at +2d. Tell the learner: "that miss is captured, it'll come
  back around." This replaces the reread-for-nuggets habit.

## Routing thresholds

With 3 questions: 3/3 → SKIP · 2/3 → PRACTICE · 0–1 → TEACH.
With 2 questions: 2/2 → SKIP · 1/2 → PRACTICE · 0 → TEACH.
Reasoning quality can demote a numeric pass (pattern-matched 3/3 → PRACTICE, say why).
It never promotes a fail.

## Routes

**SKIP** — mark it, set `review_after` +14d, next concept. Do not summarize the section
"just in case" — that reintroduces the reread by the back door. If the learner asks
what was in it: offer the 10-minute delta pass, timer enforced, surprises written down.

**PRACTICE** — no prose. Source exercises if they exist (learncpp usually has them at
the bottom of lessons; Beej's often doesn't — generate in-style when missing).
Silence-first + hint ladder active. Completion sets `review_after` +7d; heavy hint
usage (any rung 3) sets +2d instead.

**TEACH** — `references/teaching.md` governs. On completion `review_after` +3d.

## Review items (when a due item comes up)

Closed book. Ask, wait, grade with blind restatement. Ask the learner to self-grade
1–4 BEFORE revealing your grade — divergence is calibration data, log both.
Grades: 1 blank/wrong · 2 effortful/incomplete · 3 correct · 4 instant.
Next interval: grade 1 → +1d · 2 → same interval again · 3 → double it · 4 → double it,
and after three consecutive 4s retire the item (say so).
That doubling rule is the whole v1 scheduler. FSRS replaces this function in v1.5 —
the log format already captures everything it needs (item, date, grade).

## Postdiction + close

"Out of 100, how did that session go?" → log. If |predicted − actual| is large, note it
in one sentence without lecturing. Print the updated three counts. Done.

## Ledger schemas

Append-only. One JSON object per line. `ts` ISO-8601. Never rewrite history — if an
entry was wrong, append a correction event.

```json
{"ts":"...","type":"concept","id":"learncpp.1.4","title":"Variable assignment and initialization","kind":"skill","status":"unresolved"}
{"ts":"...","type":"session_start","session":"s0007","predicted":2,"of":3,"concept":"learncpp.1.4"}
{"ts":"...","type":"quiz","concept":"learncpp.1.4","score":3,"of":3,"route":"SKIP"}
{"ts":"...","type":"nugget","concept":"learncpp.1.4","miss":"believed copy-initialization and direct-initialization compile identically"}
{"ts":"...","type":"route","concept":"learncpp.1.4","status":"skipped","review_after":"2026-08-15"}
{"ts":"...","type":"hint","concept":"learncpp.9.2","rung":2}
{"ts":"...","type":"review","item":"learncpp.1.4","grade":3,"self_grade":3,"next":"2026-09-12"}
{"ts":"...","type":"friction","note":"wanted to reread 1.4 after skipping"}
{"ts":"...","type":"off_protocol","note":"asked for straight answer on variadic templates"}
{"ts":"...","type":"session_end","session":"s0007","postdicted":70,"actual":66}
```

IDs are stable (`source.section`). If a section's content meaningfully changes or gets
re-quizzed from scratch, new ID — old history stays truthful.
