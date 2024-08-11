#!/usr/bin/perl
# Copyright 2017-2024 The Khronos Group Inc.
# SPDX-License-Identifier: Apache-2.0

open(FILE, "config/df-xhtml.css");
read(FILE,$stylesheet,10000);
close(FILE);
while ($input = <>) {
    $input =~ s!<link rel="stylesheet" type="text/css" href="config/df-xhtml.css" />!<style>\n$stylesheet\n</style>\n!;
    print $input;
}
