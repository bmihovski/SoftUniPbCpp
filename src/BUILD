filegroup(
    name = "destination_files",
    srcs = glob(["entities/destination/*"]),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "competition_files",
    srcs = glob(["entities/competition/*"]),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "car_files",
    srcs = glob(["entities/car/*"]),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "repositories_files",
    srcs = glob(["entities/repositories/*"]),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "common",
    hdrs = glob(["common/*.h"]),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "core",
    srcs = glob(["core/*.cpp"]),
    hdrs = glob(["core/*.h"]),
    visibility = ["//visibility:public"],
    deps = [
        "//src:common",
    ],
)
cc_library(
    name = "car",
    srcs = glob(["entities/car/*.cpp"]),
    hdrs = glob(["entities/car/*.h"]),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "competition",
    srcs = glob(["entities/competition/*.cpp"]),
    hdrs = glob(["entities/competition/*.h"]),
    visibility = ["//visibility:public"],
    deps = [
        "//src:destination",
        "//src:car",
    ],
)

cc_library(
    name = "destination",
    srcs = glob(["entities/destination/*.cpp"]),
    hdrs = glob(["entities/destination/*.h"]),
    visibility = ["//visibility:public"],
    deps = [
        "//src:car",
    ],
)

cc_library(
    name = "repositories",
    srcs = glob(["entities/repositories/*.cpp"]),
    hdrs = glob(["entities/repositories/*.h"]),
    visibility = ["//visibility:public"],
    deps = [
        "//src:destination",
    ],
)

exports_files(["main.cpp"])
