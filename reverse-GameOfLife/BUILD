cc_library(
    name = "build-all-the-files",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        ":build-all-the-files"
    ],
)