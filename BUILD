# Reference the main binary target from src/BUILD
cc_binary(
    name = "main",
    srcs = ["//src:main.cpp"],
    deps = [
        "//src:common",
        "//src:core",
        "//src:car",
        "//src:competition",
        "//src:destination",
        "//src:repositories",
    ],
    visibility = ["//visibility:public"],
)

