# Roadmap: what's deferred, and why

Consult this before proposing new features mid-trial. The default answer to "should we
add X now" is no until the day-14 review — v1 exists to generate usage data, and
features added before data are speculation.

## v1 → v1.5 (after the two-week trial, informed by its data)

- **Per-source session filtering (known gap).** The pick logic doesn't automatically
  scope to one source when several are ingested — v1 handles it by asking/being told
  ("session on beej"). Proper fix: a source argument on `session` and per-source
  dashboard counts. Do this when the second source actually lands in week 2.

- **FSRS scheduling.** Swap the doubling rule for the Free Spaced Repetition Scheduler
  once review history is deep enough to matter (~1000 reviews for real per-item fit;
  before that FSRS runs population defaults that the doubling rule matches in
  practice). The ledger already records item/date/grade — this is a function swap,
  zero migration.
- **Recurring unaided gates.** Weekly closed-book tests drawn partly from skipped
  material. The day-14 gate is the prototype; keep whatever format worked.
- **Trajectory notes.** Trellis maintains a short running file about the learner's
  patterns ("third transfer-error on pointer/reference confusion"; "postdictions
  consistently under actual by ~10"). What makes session 30 feel like it remembers
  session 3.
- **Static dashboard.html.** Regenerated after each session from the ledger — counts,
  calibration trend, due list, resolved-over-time. All intelligence spent at write
  time; the file is dumb.
- **`claude -p` batch jobs.** Pre-generate next sessions' quizzes, refresh dashboard,
  ledger stats. CAUTION: verify billing first — there are standing reports of `-p`
  billing as API usage even for Max subscribers with OAuth. Interactive sessions are
  the safe path until confirmed fixed.
- **Retrievability countdown.** Make forgetting visible before the exam does.
- **Auto-primers.** 20-second structural overviews before genuinely new sections
  (advance organizers help precisely when prior knowledge is absent).
- **Second source onboarding polish.** Beej's Guide in week 2 of the trial is the test
  case for how well ingest generalizes.

## v2 — video and beyond

- **Video triage.** Check a video's chapters/description/transcript topics against the
  mastery ledger before the learner spends 40 minutes. Transcript via the
  youtube-transcript-api Python library (free, no key; gray-area ToS; cloud IPs get
  blocked — run locally). Fallback for caption-less or visually-dense videos: Gemini's
  native YouTube URL input (processes up to ~90-minute videos with timestamps) on the
  learner's own Gemini key.
- **Guided-note templates** for video/lecture consumption — bounded fill-in slots, not
  summaries.
- ~~**Interleaving as explicit scheduling**~~ — **promoted 2026-07-29.** Shipped in the
  interview track, where problems arrive unlabeled and deliberately cross patterns.
  Promoted early not on trial data but because the learner named the exact failure mode
  it prevents ("a common trap is falling into pattern matching") as a primary goal.
  Still pending for the sequential learncpp/Beej loop.
- **RC3 activation** — minimum-viable goal scoping, project mode — when the learner
  starts building with the material.

## Publishing (a v2-era decision, gated on trial evidence)

The learner intends to eventually publish Trellis for others. The path is standard —
GitHub repo, MIT license, installable via the skills ecosystem (`npx skills add`,
plugin marketplaces); the SKILL.md format is already the portable open standard and
works across Claude Code, Codex CLI, OpenClaw, and others without modification. The
real work is generalization, not packaging:

1. **Onboarding interview — the gating feature.** Personalization is currently
   hardcoded (EECS-calibrated quizzes; root-causes.md is this learner's specific
   diagnosis). Publishable Trellis needs a first-run flow that elicits a new user's
   background and failure patterns and writes THEIR root-causes file and calibration
   profile. This is also the differentiator: existing tutor skills ship generic
   pedagogy; none diagnose the user first.
2. **Personal/shippable split.** `state/` and the learner-specific parts of
   root-causes.md are personal; protocol files ship. Mostly a .gitignore plus moving
   personal calibration into state/.
3. **Evidence first.** Don't publish an untested hypothesis — two or three trial
   cycles with friction-log-driven refinements before any release.

## App phase

**Status: promoted to next scoped project, 2026-08-12.** The gate — "skill proves
itself and outgrows the terminal" — was named specifically at the day-14+ review, not
felt vaguely: a recurring complaint (multiturn terminal friction blocking async
answering), not a one-off. Scope for that project, once actually planned: live AI calls
+ persistent state in a claude.ai-hosted artifact (architecture note below is unchanged
and still the deciding constraint), plus a pre-generated question queue — questions for
upcoming due dates generated ahead of time so there's no generation-latency at the
moment of answering. Exact queue mechanism not decided; scope it when the build is
actually planned, not here. Stopgap available now, zero build: run due-review answering
in a separate session/branch so it isn't blocking whatever else is happening in the
main thread.

- **claude.ai artifact app.** The privileged path: artifacts hosted in claude.ai can
  make AI calls where each user authenticates with their own Claude account and usage
  bills to their subscription — no API keys. Plus the artifact key-value storage API
  for persistence. The JSONL ledger maps onto it cleanly.
- **Architecture note (settled, don't relitigate):** a locally-saved HTML file cannot
  route AI calls through a Claude Code session — no such channel exists. Local files
  get either direct API calls (key + separate billing) or zero AI (pre-computed at
  generation). The claude.ai-hosted artifact is where UI + subscription-billed AI
  converge. Until then, the terminal session is the only surface with all three:
  state access, subscription billing, and session context.

## Standing decisions (relitigate only with new evidence)

- JSONL over SQLite while this is a skill.
- Lazy per-session picking over forward schedules, permanently — this one is
  load-bearing for the motivation cycle, not a v1 simplification.
  **Amended 2026-07-29, one exception:** material under a hard external deadline gets a
  *cadence* (weekly slot-type quota), never a *content calendar*. The rejection was
  reasoned about open-ended learning; RC4 is literally "defer until the exam makes the
  cost visible, then cram," and a rhythm is the correct answer to RC4. What stays
  rejected is assigned content per day — that is what becomes a debt object you fall
  behind on. Quota counts hit, never days missed. See `references/interview-track.md`.
- Teaching compressed + practice-gated, never digest-without-practice.
- Source order over dependency graphs at reference-site scale.
- **DDIA rejected as the system design spine (2026-07-29), System Design Primer chosen.**
  DDIA is the better book; that was not the deciding axis. Intern-level rounds are
  SDP-depth, the learner wants breadth over depth, and may not pursue SWE long-term —
  which collapses DDIA's multi-year payoff to interview value alone. Also 8 slots finish
  SDP and strand DDIA two-thirds through. Revisit only if SWE firms up as the path or a
  mock interview exposes a depth gap. The pattern-matching objection to SDP's worked
  designs was real and was answered by delivery (design-first-then-diff), not by source.
- **Cut from the interview track, on scope not merit (2026-07-29):** Codeforces, CSES,
  company-specific question lists, mock interviews, behavioral prep, a pre-study concept
  familiarity spreadsheet. Do not re-add before late September without a named gap.
