# Trellis

A learning system that routes material through placement quizzes instead of
front-to-back reading. Built as a Claude Code skill. Optimizes for what you can do
without it.

## Setup (5 minutes)

Everything — skill, state, history — lives in this one directory. Nothing goes in
`~/.claude`; the skill is project-scoped and Claude Code discovers it automatically
when you run `claude` from inside this folder.

```bash
# 1. Place this folder anywhere you like and make it a git repo (backup + history)
cd trellis && git init && git add -A && git commit -m "trellis v1"

# 2. Start (always launch claude from inside this directory)
claude
> ingest https://www.learncpp.com/
> session
```

The ledger lives at `state/ledger.jsonl`. Commit it whenever. Plain text — open it,
read it, fix a bad line by hand if ever needed.

## Daily use

- `session` — the whole loop. One concept is a complete session. Rough lengths:
  SKIP ~2–3 min · PRACTICE ~10–15 min · TEACH ~15–30 min. No timer — run it again
  for the next concept, or stop anytime.
- `interview session` — the DSA + system design track (deadline: recruiting, late
  September 2026). Different loop: weekly slot quota, self-ranking instead of placement
  quizzes, problems delivered unlabeled and interleaved, derivation required before
  code, C++ first attempt / Python on the re-attempt. See
  `references/interview-track.md`. learncpp is deliberately **not** part of this quota.
- "what's due" — dashboard only (three counts + next pick).
- "do 7.3 instead" — override the pick.
- Multiple sources coexist in one ledger (IDs are namespaced: `learncpp.1.4`,
  `beejs.6.2`). Once you've ingested more than one, say which you want:
  "session on beej" / "what's due for learncpp".
- "who are you" / "how do you work" — Trellis explains itself from its own docs.
- "off protocol" — drop to normal assistant mode, logged, no judgment.
- `/branch <name>` — chase a tangent in a fork; `/resume` returns to the untouched
  session.
- "iterate mode" — design-partner mode: discuss techniques, root causes, roadmap,
  and modify Trellis from inside Trellis.

## The two-week experiment

This trial has defined success criteria, set before first contact. Fill in the
predictions line NOW, before session one — that's the point.

**Protocol**
- Floor: 4 sessions/week. A 10-minute one-concept session counts fully.
- Week 1: learncpp only. ~~Week 2: add Beej's Guide if the loop feels smooth.~~
  **Superseded 2026-07-29:** the second source is the interview track, not Beej's, and
  learncpp dropped to ad-hoc/low-stakes for the duration. The trial keeps running — the
  day-14 gate below still happens, just on less learncpp material than planned.
- Friction → one log line, keep moving. No mid-trial redesigns. (Exception:
  contract violations — "you hinted before I attempted" — get corrected on the spot.)
- Reread urges → log line, not reread. Strictness is time-boxed to these 14 days;
  the gate below is the audit that makes it trust-until-verified, not blind faith.

**Day 14**
1. Unaided gate: closed-book test, no Trellis, no search, drawn substantially from
   SKIPPED material. This audits whether the skips were safe.
2. Review the friction log together and decide v1.5 changes with data attached.
3. Compare the predictions below against actuals — calibration training at the
   meta level.

**Predictions (fill in before session one)**
```
sessions I will actually complete in 14 days: ____
% of early-chapter concepts that will route SKIP: ____
gate score on skipped material (out of 100): ____
number of reread-urge log lines: ____
```

**What can't fail:** a loop that doesn't work and gets documented not working is a
successful experiment. The only failure mode is generating no data.

## Layout

```
trellis/                            # git repo — run `claude` from here
├── .claude/skills/trellis/         # the skill (project-scoped, auto-discovered)
│   ├── SKILL.md                    # trigger + loop + contracts
│   └── references/
│       ├── loop.md                 # full session protocol + ledger schemas
│       ├── interview-track.md      # DSA + system design loop (deadline-driven)
│       ├── question-generation.md  # anti-pattern-matching protocol
│       ├── teaching.md             # TEACH mode: predict → compressed teach → practice
│       ├── techniques.md           # every technique discussed, incl. deferred/rejected
│       ├── root-causes.md          # RC1–RC4 in full
│       ├── iterate-mode.md         # design-partner mode
│       └── roadmap.md              # v1.5 / v2 / app phase, and settled decisions
├── state/ledger.jsonl              # append-only event log — the single source of truth
└── README.md
```

The skill lives inside the repo, so it's only active when you run `claude` from this
directory — nothing global, nothing in your home directory. That also means the whole
system (rules + state + history) travels as one folder: back it up, sync it, or clone
it to another machine and it just works.

## Honest notes

- Claude's interpretation of the protocol will drift slightly between sessions. One
  sentence ("you're hinting before I attempted") snaps it back; the skill instructs
  acceptance without argument.
- Very long sessions may compact context and get vague about their own history. The
  ledger is append-as-you-go, so nothing real is lost — start a fresh session.
- Some quiz questions will still feel canonical despite the generation protocol. Flag
  them in the moment; they get regenerated and logged.
- The name: "Trellis" — a structure a plant grows on. It doesn't dictate the shape;
  it gives you something to grow against.
