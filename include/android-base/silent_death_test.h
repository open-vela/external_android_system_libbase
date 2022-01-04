/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <signal.h>
#include <gtest/gtest.h>

#include <array>
#include <memory>

#if !defined(__BIONIC__)
#define sigaction64 sigaction
#endif

// Disables debuggerd stack traces to speed up death tests, make them less
// noisy in logcat, and avoid expected deaths from showing up in stability metrics.
//
// When writing new death tests, inherit the test suite from SilentDeathTest
// defined below. Only use ScopedSilentDeath in a test case/suite if changing the
// test base from testing::Test to SilentDeathTest adds additional complextity when
// test suite code is shared between death and non-death tests.
//
// For example, use ScopedSilentDeath if you have:
//   class FooTest : public testing::Test { ... /* shared setup/teardown */ };
//
//   using FooDeathTest = FooTest;
//
//   TEST_F(FooTest, DoesThis) {
//     // normal test
//   }
//
//   TEST_F (FooDeathTest, DoesThat) {
//     ScopedSilentDeath _silentDeath;
//     // death test
//   }
class ScopedSilentDeath {
 public:
  ScopedSilentDeath() {
    for (int signo : SUPPRESSED_SIGNALS) {
      struct sigaction64 action = {.sa_handler = SIG_DFL};
      sigaction64(signo, &action, &previous_);
    }
  }

  ~ScopedSilentDeath() {
    for (int signo : SUPPRESSED_SIGNALS) {
      sigaction64(signo, &previous_, nullptr);
    }
  }

 private:
  static constexpr std::array<int, 4> SUPPRESSED_SIGNALS = {SIGABRT, SIGBUS, SIGSEGV, SIGSYS};

  struct sigaction64 previous_;
};

// When writing death tests, use `using myDeathTest = SilentDeathTest;` or inherit from
// SilentDeathTest instead of inheriting from testing::Test yourself.
//
// Disables debuggerd stack traces to speed up death tests, make them less
// noisy in logcat, and avoid expected deaths from showing up in stability metrics.
class SilentDeathTest : public testing::Test {
 protected:
  void SetUp() override {
    silent_death_ = std::unique_ptr<ScopedSilentDeath>(new ScopedSilentDeath);
  }

  void TearDown() override { silent_death_.reset(); }

 private:
  std::unique_ptr<ScopedSilentDeath> silent_death_;
};
