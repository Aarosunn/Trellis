# EECS 215 — Intro to Electronic Circuits (FA26, Terry / Wentzloff)

Skill: `trellis`. Everything below is class-specific input to it.

## State
Repo: `Aarosunn/Trellis` · path: `classes/eecs215/state.md` · tool: GitHub MCP (`get_file_contents` / `create_or_update_file`).
If the tool is absent, ask me to paste `state.md`. Never search past chats for it.

## Knowledge
Chapters, lecture slides, HWs, HW solutions, old exams, and the instructor's Linear Circuit Analysis (MNA) notes. Prior-term HWs (W26) are calibration only; this term's HWs win when both exist.

## Exam profile
- Closed book. Scientific calculator required (complex matrix math recommended for later units). No computer aids.
- 5 problems, multi-part, 10–15 pts each, 2 hours. Numeric answers with units. Method must be shown; "briefly explain each step" is graded.
- Shape: circuit + values → find X. Method often forced ("use nodal, not superposition"). Dependent sources in most problems. Asks for power *supplied by* a source, not just V/I.
- Also: "express in the form …", choose-one-and-justify.
- Difficulty floor = Ulaby end-of-chapter problems = HW. Exam adds a step or a twist, never a new method.
- Weights: MT1 15% · MT2 20% · Final 25%. Exam 1 = 10/13 (ch 1–4) · Exam 2 = 11/10 (ch 5, 6, 12) · Final = 12/17 (all + ch 7, 9, 8).

## Traps (use for distractors)
- power sign: passive sign convention; supplied vs absorbed; Σp = 0 check
- killing sources for R_Th: dependent sources stay → test-source method
- supernode: KVL *inside* the supernode + KCL *around* it; not KCL at the source
- MNA: current through a voltage source is an unknown, not zero
- dependent source: controlling variable's direction/polarity as drawn, not as convenient
- op-amp: v_n = v_p only in linear region with negative feedback; output clips at ±Vcc
- linear range: solve |v_o| ≤ Vcc for the input bounds, both signs
- cascaded op-amps: i_p = i_n = 0 decouples stages — no loading
- source transformation flips which terminal the source points to
- units: nF, mH, kΩ prefixes in arithmetic

## Visual rule
No ASCII schematics. Describe circuits as a netlist in prose: "10 V source, + at node a, − at ground. R1 = 5 Ω between a and b. 2 A source into b." Use standard reference-direction words. One SVG artifact per teach turn only when topology matters and prose fails; label every node.

## Node list (ch 1–4, Exam 1 scope)

| ch | node | ceiling | note |
|---|---|---|---|
| 1 | topology | T1 | node/branch/loop, series/parallel, extraordinary nodes |
| 1 | charge-current | T1 | i = dq/dt, q = ∫i |
| 1 | power-sign | T2 | passive sign convention, supplied vs absorbed, Σp = 0 |
| 1 | sources | T1 | ideal V/I, VCVS/CCVS/VCCS/CCCS, what "kill" means |
| 1 | switch-topology | T1 | circuit for t<0 vs t>0 |
| 2 | kcl | T2 | |
| 2 | kvl | T2 | |
| 2 | combine | T2 | series/parallel, voltage & current dividers |
| 2 | source-transform | T2 | |
| 2 | nonlinear-iv | T1 | ideal diode, piecewise-linear i–v (2-6) |
| 3 | nodal | T3 | classic node-voltage |
| 3 | nodal-dep | T3 | dependent sources in nodal |
| 3 | supernode | T3 | |
| 3 | mna | T3 | modified nodal: V-source currents as unknowns (LCA notes §1–2) |
| 3 | method-choice | T1 | classic nodal vs MNA vs supernode; when each is shortest |
| 3 | superposition | T3 | one independent source at a time; dependents stay |
| 3 | thevenin | T3 | V_oc / I_sc; R_Th by kill; R_Th by test source |
| 3 | norton | T2 | |
| 3 | max-power | T2 | R_L = R_Th, P = V_Th²/4R_Th |
| 3 | bjt-dc | T2 | model as dependent source, solve (3-9) |
| 4 | opamp-model | T2 | A, R_i, R_o; saturation when |A(v_p−v_n)| > Vcc |
| 4 | ideal-rules | T2 | v_p = v_n, i_p = i_n = 0, requires negative feedback |
| 4 | inv | T3 | |
| 4 | noninv | T3 | |
| 4 | summing | T3 | |
| 4 | difference | T3 | |
| 4 | linear-range | T3 | input bounds from ±Vcc |
| 4 | cascade | T3 | stages decouple; buffer; loading |
| 4 | instrumentation | — | derivable from difference |
| 4 | mosfet-vccs | T2 | 4-11 |

Nodes for ch 5+ get added by `cut` when the chapters are uploaded.

## Skip list
1-1 history · all Technology Briefs · 1-2 units (T0 warm-up only) · 3-7 prose (→ method-choice) · 4-5.3 · lec 1 superhet intro · 9/3 discussion (MATLAB) · HW1 Q1–2 (EV essay) · mesh analysis 3-3/3-4 (not assigned) · lab procedures unless a HW uses them.

## Calendar
```
lec    date   sections            nodes
2      09/02  1-1..1-6            ch1
3      09/09  2-1..2-3            ch2
4-5    09/14  LCA§1-2, 3-1,3-2    nodal nodal-dep supernode mna method-choice
6-7    09/21  3-5..3-8            superposition thevenin norton max-power
8      09/28  2-6                 nonlinear-iv
9      09/30  3-9, 4-11           bjt-dc mosfet-vccs
10-11  10/05  4-1..4-9            opamp-*
EXAM1  10/13  ch1-4
12-13  10/12  5-1..5-6            C/L, first-order
14-15  10/21  6-1..6-6            second-order
16-18  10/28  12-1..12-7          laplace
EXAM2  11/10  ch5,6,12
19-20  11/09  7-1..7-10           phasors
21-22  11/16  9-1..9-3            freq-response
23-24  11/23  9-4..9-7            filters
25     12/02  8-1..8-5            ac-power
FINAL  12/17  all
```
HW issued Fridays, due next Friday 4 pm. Solutions posted 48 h before due.
`prime` with no topic → sections for the next `lec` row after today. `exam` with no topic → next EXAM row's scope.
