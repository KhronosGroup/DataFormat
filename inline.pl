#!/usr/bin/perl
open(DATAFILE, "<", "images/Khronos_Dec14.svg.b64");
$data = <DATAFILE>;
close DATAFILE;
open(INPUT, "<", "df.html");
while ($input = <INPUT>) {
    $input;
    $input =~ s!images/Khronos_Dec14.svg!data:image/svg+xml;base64,$data!;
    print $input;
}
