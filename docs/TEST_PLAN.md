# Test plan

## Current milestone
- Configure and compile with CMake on Windows and Linux.
- Run `ctest`.
- Confirm diagnostics executable does not enumerate or modify disks.

## Later milestones
- Unit tests for parsers and validation.
- Fuzz malformed ISO metadata and configuration.
- QEMU + OVMF boot tests.
- Test supported images individually; do not infer compatibility from one successful image.
- Physical USB tests only after virtual tests pass, using expendable test media and explicit operator confirmation.
