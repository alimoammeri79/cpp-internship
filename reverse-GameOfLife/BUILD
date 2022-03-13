cc_library(
    name = "build-all-the-files",
    srcs = glob(["gol.cpp", "array2d.h"]),
    hdrs = glob(["gol.h", "array2d.h"]),
    visibility = ["//visibility:public"]
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        ":build-all-the-files"
    ]
)