# TEACH mode: how new material gets taught

The resolved tension: silence-first says no explanation before an attempt, but genuinely
new material offers nothing to attempt FROM. Resolution: "attempt first" means "commit
to a guess first," not "solve first." Guessing before exposure measurably improves
retention of the correction even when the guess is wrong — that is the pretesting
effect, and it is why step 1 below is never skipped.

## The sequence

1. **Predict.** State the concept's name and ask what the learner would guess it does /
   why it might exist, before showing anything. Thirty seconds. Wrong guesses are
   doing their job.

2. **Compressed explanation + minimal example.** Teach it properly — mechanism, purpose,
   the distilled version of what the source spends pages on. Then ONE minimal example:
   the smallest snippet that shows the thing actually working. Code-first for
   programming material. This is a real explanation, not a riddle — TEACH mode is
   where Trellis earns the "cut the fluff, keep the substance" job. What it is NOT:
   the source's full prose, its three paragraphs of throat-clearing, or its five
   examples where one suffices.

3. **Immediate completion attempt.** A near-identical problem with 1–3 steps blanked,
   right now — not after a reading gap. Silence-first and the hint ladder apply from
   this point on.

4. **Demanded self-explanation.** Pick the step with the most going on (highest element
   interactivity, not the first step) and require: why does this step follow from the
   previous one? Spontaneous self-explanation is usually too shallow to help;
   demanding it is what makes example study work.

5. **Near-transfer check.** Same schema, different surface. If it lands, the concept is
   `taught`, review_after +3d. If it doesn't, one more worked cycle, then stop —
   a concept that won't land in two cycles gets logged as stagnant and revisited
   fresh next session rather than ground down now.

6. **Source prose is opt-in.** Afterward: "the full section is at <url> if you want the
   long version." Offered once, never pushed, never required to proceed.

## Trigger context changed

TEACH used to fire on a first-pass low score. It now fires only when a PRACTICE item's
next review also fails (see `references/loop.md`'s Routing section) — two real tests,
not one guess-driven placement. Two consequences:

- **Scope narrows.** Explain the specific point that's still failing, not the whole
  section — the learner already read the source and worked the exercises once.
- **Skip step 1 (Predict).** Guessing before exposure only pays off when exposure
  hasn't happened yet. By the time TEACH fires here, it has — twice. Go straight to
  step 2.

The original full sequence (Predict included) still applies wherever TEACH fires on
genuinely first-touch material — mid-task triage's "blocking" explanations, a `/branch`
tangent, or the rare case the learner asks to be taught something cold.

## Fading

Support level is set by history, not mood:

| Recent history on this concept/schema | Format |
|---|---|
| First exposure, or prior TEACH that didn't land | Full sequence above |
| Prior TEACH landed | Completion problem only (skip step 2) |
| Two clean completions | Unsupported problem |

Worked examples help novices and actively hurt learners who already hold the schema —
keeping support flat as mastery rises is how tutoring goes stale. Fade on evidence.

## What TEACH never does

- Paste or closely paraphrase the source section (the compressed explanation is
  Trellis's own words, grounded in the fetched content)
- Give a second example before the learner has attempted the first
- Answer the completion problem when the learner stalls — that's the hint ladder's job,
  at its prices
- Treat "makes sense" as landing — the near-transfer check is the evidence
