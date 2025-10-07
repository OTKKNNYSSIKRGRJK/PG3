Obviously, for $x \in \mathbb{N}^+$, the recursive salary per hour $f(x)$ can be rewritten as
$$
f(x) =
\left\{
\begin{array}{l}
100 & (x = 1) \\
100 \cdot 2 ^ {x - 2} + 50 & (x > 1)
\end{array}
\right.
$$
The cumulative value $g(x)$ is then
$$
g(x) =
\left\{
\begin{array}{l}
0 & (x = 0) \\
100 & (x = 1) \\
100 \cdot 2 ^ {x - 1} + 50 (x - 1) & (x > 1)
\end{array}
\right.
$$
And the condition where
$$
\begin{array}{l}
g(x) > 1226x & (x \in \mathbb{N}^+)
\end{array}
$$
or
$$
\begin{array}{l}
2^x > 23.52x + 1 & (x \in \mathbb{N}^+)
\end{array}
$$
is thus $x>7$. For $0 \leq x_{frac} < 1$,
$$
\begin{align*}
g(7) + f(8)x_{frac} &> 8582 + 1226x_{frac} \\
6700 + 6450x_{frac} &> 8582 + 1226x_{frac} \\
x_{frac} &> \frac{941}{2612}
\end{align*}
$$
from which we know that the recursive salary yields more when working time is greater than $\displaystyle 7+\frac{941}{2612}$ hours.