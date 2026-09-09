# eecs215 state
updated: 2026-09-09

## nodes
node | state | ceiling | last | note
topology | solid | T1 | 2026-09-09 | nodes, extraordinary nodes, series via ordinary node
charge-current | solid | T1 | 2026-09-09 | constant i and integral of exponential both clean
power-sign | solid | T2 | 2026-09-09 | PSC, supplied vs absorbed, sum p = 0; labeling-flip case understood
sources | solid | T1 | 2026-09-09 | dependent-source eval (CCVS) clean
switch-topology | shaky | T1 | 2026-09-09 | see mistakes; open/closed x series/parallel table taught
kcl | untested | | |
kvl | untested | | |
combine | untested | | |
source-transform | untested | | |
nonlinear-iv | untested | | |
nodal | untested | | |
nodal-dep | untested | | |
supernode | untested | | |
mna | untested | | |
method-choice | untested | | |
superposition | untested | | |
thevenin | untested | | |
norton | untested | | |
max-power | untested | | |
bjt-dc | untested | | |
opamp-model | untested | | |
ideal-rules | untested | | |
inv | untested | | |
noninv | untested | | |
summing | untested | | |
difference | untested | | |
linear-range | untested | | |
cascade | untested | | |
mosfet-vccs | untested | | |

## mistakes  (open until answered correctly twice)
date | node | what | correct-since
2026-09-09 | switch-topology | misconception: closed switch in parallel with R shorts R out (R deleted, 0 A through it); answered as if switch were open | 0

## log  (keep last 30)
date | mode | topic | result
2026-09-09 | solidify | ch1 all 5 nodes | 4 solid, 1 shaky; T3 deferred (needed ch2 Ohm's law, out of scope)
2026-09-09 | off-node | discussion 1 linear algebra + MATLAB | handout P1/P2 all parts correct; inv vs left divide, symbolic, format covered

## notes
- Ohm's law (2-1) used during ch1 teaching but not yet lectured as of 09/09.
- Discussion 1 (linear algebra / MATLAB) is off-node per skip list; not tracked as nodes.
- Discussion slide 12 Gaussian elimination: stated answer 3,-1,2 appears wrong; verified 3,-1,-2 by substitution.
- MATLAB installed via AUR but segfaults under Hyprland + glibc 2.44; using MATLAB Online instead.
- 09/09 session: two T3 problems were mis-scoped by tutor into ch2/ch3 material; a sources miss on
  "killing" sources was also out of scope (ch3) and is NOT logged as a deficit.
