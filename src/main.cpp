// SPDX-License-Identifier: GPL-3.0-only
// swft - Transfer files using sound waves
// Copyright (C) 2023 ters

#include "config.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <argparse/argparse.hpp>

int main(int argc, char* argv[]) {

    // generate version string from config.h
    static_assert(SWFT_VERSION >= 0, "SWFT_VERSION must be >= 0");
    std::string version = std::to_string(SWFT_VERSION);

    argparse::ArgumentParser program("swft", version);
    program.add_argument("--file").help("file to transmit").metavar("FILE");
    program.add_argument("-r", "--receive").help("receive a file").default_value(false).implicit_value(true);
    program.add_argument("--verbose").default_value(false).implicit_value(true);

    program.add_description("Transfer files using sound waves.");
    program.add_epilog("Still in development.");

    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
        std::cout << program;
        exit(0);
    }
}