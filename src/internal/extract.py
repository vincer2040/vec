#!/bin/env python3

from pathlib import Path

DEPTH = 64
KEYS = [
  'obj_copy', 'obj_dtor', 'obj_eq',
  'alloc_alloc', 'alloc_realloc', 'alloc_free',

  'modifiers',
]
FILE = Path(__file__).parent / 'extract.h'

def main():
    text = FILE.read_text()
    end = text.find('/* !!! */')

    lines = []
    lines.append(text[:end] + '/* !!! */')
    lines.append('')

    for key in KEYS:
        lines.append(f'#define VEC_EXTRACT_{key}(key_, val_) VEC_EXTRACT_{key}Z##key_')
        lines.append(f'#define VEC_EXTRACT_{key}Z{key} VEC_NOTHING, VEC_NOTHING, VEC_NOTHING')
    lines.append('')

    for i in range(0, DEPTH):
        lines.append(f'#define VEC_EXTRACT{i:02X}(needle_, kv_, ...) VEC_SELECT{i:02X}(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT{i+1:02X}, (needle_, __VA_ARGS__), VEC_NOTHING)')
    lines.append('')
    for i in range(0, DEPTH):
        lines.append(f'#define VEC_SELECT{i:02X}(x_, ...) VEC_SELECT{i:02X}_(x_, __VA_ARGS__)')
    lines.append('')
    for i in range(0, DEPTH):
        lines.append(f'#define VEC_SELECT{i:02X}_(ignored_, _call_, _args_, call_, args_, ...) call_ args_')
    lines.append('')
    lines.append('#endif  // __VEC_EXTRACT_H__')

    FILE.write_text('\n'.join(lines) + '\n')

if __name__ == '__main__': main()
