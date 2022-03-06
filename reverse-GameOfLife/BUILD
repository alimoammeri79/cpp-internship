cc_library(
    name = "build-all-the-files",
    srcs = glob(["gol.cpp", "Array_2D.h"]),
    hdrs = glob(["gol.h", "Array_2D.h"]),
    visibility = ["//visibility:public"]
)

# cc_library(
#     name = "gol",
#     srcs = ["gol.cpp"],
#     deps = [
#         ":gol",
#         ":Array_2D"
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