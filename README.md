@'
# SensorValidator

A C++17 implementation of a sensor reading validator using Bazel and GoogleTest.

## Overview

`SensorValidator` checks whether a `SensorReading` is currently usable.

A reading is considered valid when:

1. Its value is within the configured inclusive range `[min_value, max_value]`.
2. Its age does not exceed the configured maximum age.

## Project Structure

```text
.
├── MODULE.bazel
├── .bazelversion
├── lib
│   ├── BUILD.bazel
│   ├── sensor_validator.h
│   └── sensor_validator.cc
└── test
    ├── BUILD.bazel
    └── sensor_validator_test.cc
