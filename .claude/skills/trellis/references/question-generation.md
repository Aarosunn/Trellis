# Question generation: testing understanding, not recognition

The failure mode this file exists to prevent: generated questions regress to the mean of
every tutorial quiz on the topic, and a learner who has read those tutorials answers from
pattern recognition without understanding. Flashcard-style cue-matching creates an
illusion of competence — change the wording and the "knowledge" vanishes. Quiz questions
inherit the same disease when they take canonical forms.

## Rules

1. **Ban canonical forms.** Never ask a question whose surface shape appears in common
   tutorials for the topic. No "what does this swap function print", no "is this
   pass-by-value or reference" on the textbook example, no fizzbuzz-shaped anything.
   If you can imagine the question on a top-10 blog post for the topic, discard it.

2. **Generate by transformation, not by topic.** Pick a transfer vector, then apply it:
   - **Novel surface** — same principle, unbloggable context. Pointer arithmetic inside
     a ring buffer; RAII in a file-handle pool; integer promotion inside a checksum.
   - **Violated expectation** — code that LOOKS like the canonical example but differs
     in one load-bearing detail. Punishes recognition, rewards actually reading.
   - **Inverted direction** — give the output, ask for an input that produces it; give
     the symptom, ask for the class of bug; give the constraint, ask what design it forces.
   - **Composition** — combine two concepts from the ledger that tutorials never pair.
     This is also where interleaving enters v1 for free: prefer pairing the current
     concept with a previously-resolved confusable neighbor.

3. **Application over definition.** Every question should require DOING something with
   the concept — predict, construct, diagnose, decide — never reciting what it is.

4. **Require the why.** For anything non-trivial, the answer isn't complete until the
   learner explains the reasoning. Grade the model, not the token. Right answer with
   "it's always X in these" reasoning scores below a wrong answer with a sound model
   and one arithmetic slip.

5. **Predict-then-run is the trump card (coding).** The most reliably novel question is
   the learner's own code from this or a prior session: "what does it print if I change
   this line?" Zero chance of prior exposure. Use it whenever session code exists.

6. **Difficulty calibration.** The learner has taken EECS 281 (data structures &
   algorithms) and EECS 370 (computer organization) at Michigan. Questions on early
   material should be quick but non-trivial — testing the C++-specific edges they may
   not know, not the programming concepts they certainly do. Question count per label
   follows from this same calibration: 1 question for a narrow/simple label, up to 3 for
   a label with several distinct C++-specific edges worth checking — never pad to a flat
   number just to hit 2–3.

7. **Extension questions, now allowed.** A real read of the source now always precedes
   the quiz (see `session` step 3 in SKILL.md), so the old boundary — stay within the
   current chapter's literal text plus already-resolved concepts — no longer needs to
   be absolute. ~1 question per set may reach beyond the chapter if it's reachable by
   reasoning from the learner's CS background (EECS 281/370) or a logical extension of
   the mechanism just read. This is not a license to fabricate: requiring a fact that
   isn't inferable from either source is still banned — that's the exact failure logged
   repeatedly before (forward-referencing unresolved chapters, inventing error text,
   assuming unstated tooling). The line is reasoning vs. requiring memorized trivia
   nobody gave the learner. Baseline difficulty on every question, not just extension
   ones, should sit at the top of rule 6's calibration band — the reading pass removes
   the excuse for softballs.

8. **Further reading, on an extension-question miss only.** If the learner is curious,
   offer one pointer to further reading via the existing `/branch` mechanic — opt-in,
   never required to close the item. Misses on standard (non-extension) questions get
   the normal nugget/PRACTICE/review path instead, no pointer.

## Feedback loop

When the learner says a question "felt recognized, not reasoned" — believe them, log
`{"type":"friction","note":"canonical question on <concept>"}`, and regenerate that
question with a different transfer vector on the spot. Recurring reports on the same
vector mean stop using that vector for that topic area.

## Honest limitation

No protocol makes generation reliably novel forever. Some questions will still smell
canonical. The feedback loop above is the mechanism, not perfection. Do not defend a
question the learner flags; replace it.
