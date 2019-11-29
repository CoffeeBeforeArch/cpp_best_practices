// This program shows off the clever initialization of a string
// By: Nick from CoffeeBeforeArch

#include <benchmark/benchmark.h>
#include <cstdlib>
#include <string>

using std::string;

// What if we have a more complex initialization?
static void baseBench(benchmark::State &s) {
  const int i = rand();
  while (s.KeepRunning()) {
    // By forgetting const, we call the constructor then do assignment
    string s;
    switch (i % 4) {
      case 0:
        s = "The string from case 0!";
        break;
      case 1:
        s = "The string from case 1!";
        break;
      case 2:
        s = "The string from case 2!";
        break;
      case 3:
        s = "The string from case 3!";
        break;
    }
  }
}
BENCHMARK(baseBench);

// We can solve more complex initialization with lambdas!
static void betterBench(benchmark::State &s) {
  const int i = rand();
  while (s.KeepRunning()) {
    // By forgetting const, we call the constructor then do assignment
    const string s = [&]() {
      switch (i % 4) {
        case 0:
          return "The string from case 0!";
        case 1:
          return "The string from case 1!";
        case 2:
          return "The string from case 2!";
        case 3:
          return "The string from case 3!";
        default:
          return "Some string to shut the compiler up";
      }
    }();
  }
}
BENCHMARK(betterBench);

BENCHMARK_MAIN();
