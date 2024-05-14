#!/usr/bin/env python3

import sys
import argparse

from pathlib import Path

HDRS = [
    "src/internal/base.h",
    "src/internal/extract.h",
    "src/type.h",
    "src/internal/raw_vec.h",
    "src/declare.h",
];

def main():
    parser = argparse.ArgumentParser(description="unify")
    parser.add_argument(
        "--out",
        type=argparse.FileType("w", encoding="utf-8"),
        default="vec.h",
        help="location to output the file to",
    )
    parser.add_argument(
        "--include_dir",
        type=Path,
        default=".",
        help="path to src/*.h"
    )
    parser.add_argument(
        "--guard",
        type=str,
        default="__VEC_H__",
        help="header guard for outfile",
    )

    args = parser.parse_args()
    include_dir = args.include_dir.resolve()
    guard = args.guard;

    out = args.out

    lines = []
    lines.append(f'#ifndef {guard}')
    lines.append(f'#define {guard}')

    for hdr in HDRS:
        path = include_dir / hdr
        f = open(path)
        buf = f.read()
        buf_lines = buf.splitlines()
        for line in buf_lines:
            if "#include \"" in line:
                continue
            lines.append(line)
        f.close()

    lines.append(f'#endif /* {guard} */')

    for line in lines:
        out.write(f'{line}\n')

    out.close()

if __name__ == '__main__': sys.exit(main() or 0)

