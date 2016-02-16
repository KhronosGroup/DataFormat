#!/usr/bin/perl
# Copyright (c) 2014-2015 The Khronos Group Inc.
# Copyright notice at https://www.khronos.org/registry/speccopyright.html
open(DATAFILE, "<", "images/Khronos_Dec14.svg.b64");
$data = <DATAFILE>;
close DATAFILE;
open(INPUT, "<", "df.html");
while ($input = <INPUT>) {
    $input;
    $input =~ s!images/Khronos_Dec14.svg!data:image/svg+xml;base64,$data!;
    print $input;
}
