# The full technique catalog

Everything discussed in Trellis's design, including techniques deliberately NOT in v1
and techniques evaluated and rejected. Status codes: **v1** (active now) ·
**deferred** (planned, see roadmap.md) · **experiment** (thin evidence, test-on-self
material) · **rejected** (evaluated, declined, reason given).

When the learner asks to learn about any of these, teach it properly — and suggest
`/branch <technique-name>` for a deep dive so the main session stays clean.

## Active in v1

| Technique | What it is | Root cause |
|---|---|---|
| Placement / test-out testing | A short real test decides skipping, not self-judgment | RC1 |
| Prediction / postdiction calibration | Guess score before, log actual after, track the gap | RC1 |
| Blind restatement | Claims rewritten as neutral questions before grading; kills the sycophancy channel (agreement rises with expressed confidence; question-framing suppresses it better than "don't be sycophantic" instructions) | all |
| Silence-first | No help before an attempt artifact; effort-then-AI ordering preserves retention, AI-then-effort erodes it | RC2 |
| Priced hint ladder | Help is never refused, always visible and logged | RC2 |
| Worked-example fading | Example → completion → unsupported, gated on evidence (expertise reversal: examples help novices, hurt those with the schema) | RC2 |
| Demanded self-explanation | Forced "why does step N follow" — spontaneous self-explanation is too shallow to work | RC2 |
| Pretesting / prediction before exposure | Wrong guesses before new material improve retention of the correction | RC2 |
| Grade reasoning, not answers | Pattern-matched correct < principled wrong | RC1, RC2 |
| Novel-question generation protocol | Transfer vectors instead of canonical quiz forms (see question-generation.md) | RC2 |
| Predict-then-run | Predict code output before executing, every time; free continuous calibration | RC1, RC2 |
| Nugget capture | Quiz misses logged verbatim as review items — replaces reread-for-nuggets | RC1 |
| Mid-task triage (black box vs blocking) | Park tangents as logged concepts; `/branch` for real chases | RC3 |
| Simple spaced review | Date field + doubling rule; retrieval practice and distributed practice are the two highest-evidence techniques in the literature (meta-analysis of 242 studies, ~169k participants) | RC4 |
| Friction logging | Complaints become data lines, addressed at review time with evidence | meta |
| Dashboard-first visible progress | Three counts before anything; skipped counts as progress | RC1, motivation |
| Minimum viable session | One concept = complete session; survives exam weeks | motivation |

## Deferred (see roadmap.md)

| Technique | What it is | Why deferred |
|---|---|---|
| FSRS (Free Spaced Repetition Scheduler) | Per-item forgetting-curve model (difficulty/stability/retrievability) | Needs ~1000+ reviews before personalization is real; below that it's population defaults. v1 log format captures everything it needs; drop-in swap at v1.5 |
| Unaided gates | Weekly closed-book test, no Trellis, no search | Day-14 gate is in the trial plan; recurring gates are v1.5 |
| Interleaving (as a feature) | Deliberate mixing of confusable schema families | Falls out of the composition transfer-vector for free in v1; explicit scheduling later |
| Trajectory notes | Trellis's running log about the learner's patterns | Needs sessions to exist first |
| Retrievability countdown | Show decaying recall probability to make forgetting visible | RC4 motivational layer, v1.5 |
| Advance organizers / auto-primers | Short structural overview before new material; helps when no prior knowledge exists, adds little when it does | Cheap once graph exists; v1.5 |
| Guided / skeletal notes | Bounded fill-in template during video/lecture consumption | v1 sources are text |
| Source / video triage | Check a resource's topic list against mastery before spending time | Video-era feature; needs transcript tooling (youtube-transcript-api) or Gemini video-native fallback |
| Two-week technique experiments | One variable per fortnight, adherence + outcome logged | The v1 trial IS the first one |
| Minimum-viable goal scoping | Rewrite goals to smallest version exercising the skill | RC3 activates when project-building starts |
| Concept dependency edges | Explicit prerequisite graph | Source ordering suffices at v1 scale |
| Structure-mapping across examples | Noticing when example 2 teaches example 1's schema | Video-consumption skill; later |

## Experiments (thin direct evidence — test on yourself, don't assume)

| Technique | Honest status |
|---|---|
| Zettelkasten / atomic linked notes | Direct evidence rests largely on one prolific person; the working parts (own-words generation, elaborative linking) are well-supported independently. Run as a two-week experiment if curious |
| Feynman explain-to-nobody | Popular, plausible via the generation effect, little direct study |
| Method of loci / memory palace | Genuinely effective for ordered lists (trained novices +20 words recall in controlled studies); wrong tool for conceptual understanding |
| Dual coding | Well-supported for facts (verbal+visual ≈ two retrieval paths, d 0.5–1.0); underused for code; worth trying on memory-heavy material |

## Rejected

| Technique | Why rejected |
|---|---|
| Rereading | Lowest-utility technique in the Dunlosky ranking; the learner's primary comfort behavior; the thing placement testing exists to replace |
| Highlighting / underlining | Among the weakest techniques on record despite being the most common |
| Summarization as a default | Low utility ranking; and a handed-over summary recreates passive consumption |
| Full AI summarization of sources | More AI assistance in note-taking measurably reduces cognitive engagement; a good digest manufactures the fluency illusion on purpose. (Trellis's TEACH compression differs: it precedes immediate forced practice) |
| Keyword mnemonics / imagery for text | Low utility for this material |
| SQLite for state | Right tool for query-heavy apps; wrong for a skill whose intelligence is Claude reading text. JSONL: git-friendly, hand-fixable, interruption-safe. Migrate if the app phase arrives |
| Rigid forward schedule | A plan you can fall behind on generates guilt on exam weeks; the lazy per-session pick can't be fallen behind on |
