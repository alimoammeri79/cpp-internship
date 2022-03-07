cc_library(
    name = "build-all-the-files",
    srcs = glob(["gol.cpp", "Array2d.h"]),
    hdrs = glob(["gol.h", "Array2d.h"]),
    visibility = ["//visibility:public"]
)

# cc_library(
#     name = "gol",
#     srcs = ["gol.cpp"],
#     deps = [
#         ":gol",
#         ":Array2d"
#     ],
#     visibility = ["//visibility:public"]
# )

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        ":build-all-the-files"
    ]
)