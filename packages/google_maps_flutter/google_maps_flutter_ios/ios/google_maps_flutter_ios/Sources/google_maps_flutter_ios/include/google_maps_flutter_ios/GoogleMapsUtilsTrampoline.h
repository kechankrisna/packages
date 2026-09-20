// Copyright 2013 The Flutter Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

@import GoogleMapsUtils;
// Swift Package Manager builds GoogleMapsUtilsObjC (the Objective-C classes,
// e.g. GMUStaticCluster/GMUGradient/GMUWeightedLatLng) as a separate module
// from GoogleMapsUtils (the Swift wrapper, which only re-exports it for Swift
// consumers via `@_exported import`, which does not extend to Objective-C
// `@import`), so it also needs to be imported directly for the SPM build.
//
// This must NOT be behind a conditional (e.g. `#if SWIFT_PACKAGE`): this
// header is part of this module's own public interface, and Clang's
// explicit module dependency scanner (used by Xcode's SPM integration)
// evaluates conditional `@import`s inside a module's interface separately
// from -- and inconsistently with -- the preprocessor state used to
// actually compile it. A scan-time/compile-time mismatch there silently
// drops the dependency edge from the module's own precompiled interface,
// so GMUStaticCluster/GMUGradient/GMUWeightedLatLng show up as "unknown
// type" everywhere in this module, even though the plain `@import` line
// itself reports no error. Unconditional import fixes that, at the cost
// of this plugin now requiring the Swift Package Manager build; it can no
// longer be built via CocoaPods, which does not vendor GoogleMapsUtilsObjC
// as its own module.
@import GoogleMapsUtilsObjC;
