# Reverse Conway's Game of Life

## About

This program takes a state of game of life and tries to find it's initial state.

## Input-output example

### Input

<pre><code>4 5 10
....*
..*.*
.*..*
..*.*</code></pre>

### Output

<pre><code>..*.*
...**
**.**
*....</code></pre>

Note that it can be more than one initial state, it just outputs one of them.

## How to build it?

<div>
  You can use bazel:
  <pre><code>$ bazel build //:main --cxxopt='-std=c++17'</code></pre>
  and run it with the following command:
  <pre><code>$ ./bazel-bin/main </code></pre>
</div>

## How to test it?

<div>
  You can use bazel:
  <pre><code>$ bazel test tests:test --cxxopt='-std=c++17'</code></pre>
</div>

## How it works?

Right now it uses brute-force approach to achieve the solution. It generates all possible states and evolve them
to find out witch one reach the given state.
