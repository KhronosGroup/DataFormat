#!/usr/bin/perl
# Copyright (c) 2017 The Khronos Group Inc.
# Copyright notice at https://www.khronos.org/registry/speccopyright.html
open(FILE, "config/df-xhtml.css");
read(FILE,$stylesheet,10000);
close(FILE);
while ($input = <>) {
    $input =~ s!<link rel="stylesheet" type="text/css" href="config/df-xhtml.css" />!<style>\n$stylesheet\n</style>\n!;
    print $input;
}
