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
- **Interleaving as explicit scheduling** once enough resolved concepts exist to mix.
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

## App phase (only if the skill proves itself and outgrows the terminal)

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
- Teaching compressed + practice-gated, never digest-without-practice.
- Source order over dependency graphs at reference-site scale.
