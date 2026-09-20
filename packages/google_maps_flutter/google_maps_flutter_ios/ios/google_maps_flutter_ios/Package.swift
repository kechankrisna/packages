// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "google_maps_flutter_ios",
    platforms: [
        .iOS("16.0"),
    ],
    products: [
        .library(name: "google-maps-flutter-ios", targets: ["google_maps_flutter_ios"])
    ],
    dependencies: [
        .package(url: "https://github.com/googlemaps/ios-maps-sdk", from: "10.0.0"),
        .package(url: "https://github.com/googlemaps/google-maps-ios-utils", from: "7.0.0"),
    ],
    targets: [
        .target(
            name: "google_maps_flutter_ios",
            dependencies: [
                .product(name: "GoogleMaps", package: "ios-maps-sdk"),
                .product(name: "GoogleMapsUtils", package: "google-maps-ios-utils"),
            ],
            resources: [
                .copy("Resources/PrivacyInfo.xcprivacy"),
            ],
            cSettings: [
                .headerSearchPath("include/google_maps_flutter_ios")
            ]
        )
    ]
)
