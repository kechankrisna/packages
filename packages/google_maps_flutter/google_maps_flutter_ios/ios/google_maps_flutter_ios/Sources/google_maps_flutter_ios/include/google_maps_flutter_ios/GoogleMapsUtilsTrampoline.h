// Copyright 2013 The Flutter Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

@import GoogleMapsUtils;
// Swift Package Manager builds GoogleMapsUtilsObjC (the Objective-C classes,
// e.g. GMUStaticCluster/GMUGradient/GMUWeightedLatLng) as a separate module
// from GoogleMapsUtils (the Swift wrapper, which only re-exports it for Swift
// consumers via `@_exported import`, which does not extend to Objective-C
// `@import`). CocoaPods bundles both into a single module, so this additional
// import is only needed for the SPM build.
#if __has_include(<GoogleMapsUtilsObjC/GMUStaticCluster.h>)
@import GoogleMapsUtilsObjC;
#endif
