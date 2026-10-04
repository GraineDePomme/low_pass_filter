# Low-Pass Filter Simulation

This project simulates the effect of a low-pass filter represented by the following electronic circuit for which a signal gets in on the left and comes out filtered on the right.

![](/circuit.jpeg)

Ohm's law gives us

$$ V_{in} - V_{out} = RI $$

and the capacitor law gives us

$$ Q = CV_{out} $$
$$ I = \frac{dQ}{dt} $$

By substituting the second equation into the third then into the first equation we get

$$ \frac{dV_{out}}{dt} = \frac{1}{RC} (V_{in} - V_{out}) $$

This gives us a first-order one-variable ordinary different equation that can be solved numerically.

## How it works

This program solves the differential equation above using the fourth-order Runge-Kutta method. It takes as an argument the initial time $t_0$, the final time $t_f$, the number of simulation steps between $t_0$ and $t_f$ and a value for $RC$. 

Compiling and executing the code can be done like so

``` bash
gcc main.c -o low_pass_filter -lm
./low_pass_filter 0 10 1000 0.1
```

The program prints $t$, $V_{in}$ and $V_{out}$ in the terminal, which can be redirected in a `data.csv` file.

``` bash
./low_pass_filter > data.csv
```

```
data.csv
...
1.090000, 1.000000, 0.090000
1.100000, 1.000000, 0.100000
1.110000, 1.000000, 0.110000
1.120000, 1.000000, 0.120000
1.130000, 1.000000, 0.130000
...
```

## Square-wave input signal

Here we present the result of the simulation when applied to a square-wave signal with frequency 440 Hz and amplitude 1:

$$ V_{in}(t) = 

\begin{cases}
      1 & \text{if $\lfloor 2t \rfloor$ is even}\\
      -1 & \text{if $\lfloor 2t \rfloor$ is odd}
    \end{cases} 
 $$

![](/animation.gif)

