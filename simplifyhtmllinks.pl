#!/usr/bin/perl
# Copyright 2019-2024 The Khronos Group Inc.
# SPDX-License-Identifier: Apache-2.0

# There appears to be no way to make the HTML output sylistically match the PDF
# and provide links as numbers without replicating the caption.
# Therefore we post-process the HTML to fix it.
# Note that we need to use unicode to do this properly.
use utf8;
open FH, '<:encoding(UTF-8)', $ARGV[0];
open OFH, '>:encoding(UTF-8)', $ARGV[1];
while ($lineread = <FH>) {
    $lineread =~ s/Section ([0-9.]+), “[^”]*”/Section $1/g;
    $lineread =~ s/Table ([0-9.]+), “[^”]*”/Table $1/g;
    $lineread =~ s/Equation ([0-9.]+), “[^”]*”/Equation $1/g;
    $lineread =~ s/Image ([0-9.]+), “[^”]*”/Image $1/g;
    $lineread =~ s/Figure ([0-9.]+), “[^”]*”/Figure $1/g;
    $lineread =~ s/Section ([0-9.]+), “[^”]*”/Section $1/g;
    $lineread =~ s/Table ([0-9.]+), “[^”]*”/Table $1/g;
    $lineread =~ s/Equation ([0-9.]+), “[^”]*”/Equation $1/g;
    $lineread =~ s/Image ([0-9.]+), “[^”]*”/Image $1/g;
    $lineread =~ s/Figure ([0-9.]+), “[^”]*”/Figure $1/g;
    print OFH $lineread;
}
