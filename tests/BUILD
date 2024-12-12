exports_files(["validate_destination_exists_test.cpp"], visibility = ["//visibility:public"])
cc_test(
   name = "validate_destination_exists_test",
   srcs = glob(["*.cpp"]),
   deps = [
        "@bazel_tools//tools/cpp/runfiles:runfiles",
        "//src:destination",
        "//src:competition",
        "//src:car",
        "//src:repositories",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
   ],
   data = [
        "//src:destination_files",
        "//src:competition_files",
        "//src:car_files",
        "//src:repositories_files",
    ],
)
