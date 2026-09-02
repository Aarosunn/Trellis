# Root causes

The four underlying mechanisms behind the learner's self-reported problems. Trellis
features exist to serve these; when evaluating any proposed change, ask which root
cause it serves. If none, it's decoration.

## RC1 — Monitor/control gap

**Mechanism.** In the Nelson & Narens model, metacognition splits into monitoring
("do I know this?") and control ("what do I do about it?"). This learner's monitor is
probably fine — their track record (EECS 281/370 passed, material recognized on sight)
suggests accurate knowledge judgments. The break is in the control link: anxiety
overrides a correct "I know this" with "but what if I don't," producing action that
contradicts the judgment.

**Manifestations.** Rereading learncpp/Beej from the beginning despite intermediate
coursework · unable to self-permit skipping · reviewing "too much" out of unconfidence
· the justification that early chapters contain "nuggets."

**Nuance that keeps the fix honest.** Some re-consolidation of recently-learned material
is adaptive, not neurotic — one correct retrieval doesn't guarantee survival to a
delayed test. So the fix is NOT "trust yourself more." It is: replace introspection
with measurement. A short real test decides skipping; the nugget detector catches the
legitimate version of the reread urge; the day-14 gate audits whether skips were safe.

**The deeper pattern.** The reread urge is maintained by an untested prediction ("skip
and something bad happens"). Rereading relieves the discomfort AND protects the
prediction from ever meeting evidence — the checking behavior is what keeps the false
belief alive. The only update path: skip, don't check, let the gate report. The
perspective shift is the OUTPUT of the behavior change, not its input. Strictness is
time-boxed (the trial), the urge gets an outlet (friction log), verification is
scheduled (the gate) — that's what separates this from white-knuckling.

**Boundary.** This is treated as a study habit. If checking patterns run broadly across
the learner's life with real distress, that is a conversation for a professional, not
a learning tool. Trellis restructures study habits; it is not therapy.

## RC2 — Passive consumption replacing generation

**Mechanism.** Consuming someone else's finished output substitutes for producing one's
own understanding. The source is irrelevant — AI answer, tutorial code, textbook prose,
40-minute video: same mechanism, different costume. Evidence anchors: students with
unguarded AI help improved 48% during practice and scored 17% WORSE than never-helped
students once help was removed; effort-then-AI ordering preserves engagement where
AI-then-effort erodes it; a majority of the LLM-assisted group in the cognitive-debt
study couldn't recall a passage from an essay they'd just "written."

**Manifestations.** Copying code from blogs/tutorials when learning frameworks ·
front-to-back reading as the default · "fake productivity — reading to feel good" (the
learner's own words) · consuming long videos and retaining structure-less overload.

**Fix shape.** Generation gated in front of consumption everywhere: guess before
exposure (pretesting), attempt before help (silence-first), reasoning before grades.
Learning still happens — via Trellis-curated, verified sources, followed immediately by
efficient reinforcement practice (retrieval, not rereading). The rejected version is the
handed-over digest with no practice attached — now also including Trellis's own
authored explanation substituting for the source, which is what changed in the
2026-08-12 redesign.

## RC3 — Goals scoped for impressive, not completable

**Mechanism.** Scope exceeds what's finishable, either upfront (unrealistic first
versions) or mid-task (tangent-chasing — the dependency-injection rabbit hole). Both
are the same missing discipline: no minimum-viable framing.

**Manifestations.** "Sometimes I just need to dumb things down, work on a bad v1 first"
(their own diagnosis, which is correct) · sidetracking into DI theory when the goal was
a working FastAPI endpoint.

**v1 status.** Mostly deferred — it activates when the learner starts building projects
with the material. The active fragment: mid-task triage (black box vs blocking, park
tangents as logged concepts, `/branch` for deliberate chases).

## RC4 — Review timing disconnected from felt need

**Mechanism.** Right after learning, nothing has been forgotten yet, so review has no
felt payoff — it registers as a waste of time. The cost of forgetting only becomes
visible at the exam, at which point cramming is the locally rational response. Not a
willpower failure; an information failure. The forgetting is real the whole time, just
invisible.

**Manifestations.** "I always put off reviewing till last minute" · "I'm smart enough
to cram but it's not efficient" · "I learn something quickly then forget it quickly" ·
no motivation to space-repeat fresh material.

**Fix shape (v1: structural only).** Reviews exist and surface automatically
(date + doubling rule); first gaps are short (+2/3d) so by the time an item fires,
fluency has genuinely faded and the review doesn't feel pointless. The visibility
layer — retrievability countdowns, decay display — is v1.5.

## Cross-cutting: the motivation cycle

Not a fifth root cause but a design constraint over all four: the learner runs hot
weeks and dead weeks (exams, deadlines, directionless days). Everything must survive
the worst week, not the best one. Hence: no forward plan to fall behind on · one
concept = complete session · binges welcomed through the router · progress visible as
numbers at every session start. A system that only works motivated is a mood, not a
habit.
