#!/usr/bin/perl
# Copyright (c) 2014-2017 The Khronos Group Inc.
# Copyright notice at https://www.khronos.org/registry/speccopyright.html
while ($input = <>) {
    # Special case for css...
    while (($svgfile) = $input =~ m!(url\("../images/[^.]+.svg)!) {
        $svgfile =~ s!url\("../!!;
        open(FILE, "base64 -w 0 $svgfile |");
        $encoded = <FILE>;
        close(FILE);
        $input =~ s!url\("../images/[^.]+.svg"!url\("data:image/svg+xml;base64,$encoded"!;
    }
    while (($svgfile) = $input =~ m!(src="images/[^.]+.svg)!) {
        $svgfile =~ s/src="//;
        open(FILE, "base64 -w 0 $svgfile |");
        $encoded = <FILE>;
        close(FILE);
        $input =~ s!src="images/[^.]+.svg"!src="data:image/svg+xml;base64,$encoded"!;
    }
    while (($pngfile) = $input =~ m!(src="images/[^.]+.png)!) {
        $pngfile =~ s/src="//;
        open(FILE, "base64 -w 0 $pngfile |");
        $encoded = <FILE>;
        close(FILE);
        $input =~ s!src="images/[^.]+.png"!src="data:image/png+xml;base64,$encoded"!;
    }
    print $input;
}
