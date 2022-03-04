<div>
  To run the program, you can use <code>run.sh</code> script:
  <pre><code>$ chmod +x run.sh</code></pre>
  <pre><code>$ ./run.sh [TEST_CASE_NUMBER]</code></pre>

  or bazel:
  <pre><code>$ bazel build //:main --cxxopt='-std=c++17'</code></pre>
  <pre><code>$ ./bazel-bin/main </code></pre>
</div>
