exports_files(glob(["*.cpp"]), visibility = ["//visibility:public"])
cc_test(
   name = "validate_car_competition_test",
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
