# TSP SEALS

**TSP = Troubleshoot Problems**

TSP SEALS is an open-source, modular USB boot and troubleshooting platform.
This repository is the foundation scaffold—not yet a bootable replacement for Ventoy.

## Initial engineering decisions

- **Boot targets:** UEFI first; Legacy BIOS is a planned compatibility target.
- **Host platforms:** Windows and Linux are planned. The first developer workflow is cross-platform.
- **Implementation strategy:** TSP-owned orchestration and user experience, with mature open-source components integrated behind clear interfaces.
- **Safety:** destructive USB operations are out of scope for this foundation milestone. Future disk-writing features must require explicit device confirmation and must never silently format a drive.

## Proposed stack

| Area | Choice | Why |
|---|---|---|
| UEFI development | EDK II | Established open-source UEFI development environment |
| Boot menu / filesystem modules | GRUB 2 (where license-compatible) | Mature boot ecosystem; integration must preserve GPL obligations |
| UEFI firmware testing | OVMF + QEMU | Repeatable virtual-machine testing before physical hardware |
| Core utilities | C17 + CMake | Portable low-level components |
| Desktop UI (later phase) | .NET LTS / C# | Cross-platform desktop tooling |
| CI | GitHub Actions | Automated build and test checks |
| Documentation | Markdown | Easy to review and version |

Exact component versions and license notices must be pinned before shipping binaries.

## Repository map

- `docs/` — architecture, roadmap, test plan, dependency policy
- `core/` — portable C core library
- `tools/` — host-side diagnostic utilities
- `tests/` — core unit test
- `uefi/` — EDK II integration boundary (not a complete firmware application yet)

## Build the foundation

Requirements: CMake 3.20+ and a C17 compiler.

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

The diagnostics executable now includes early read-only Linux whole-disk discovery (name, /dev path, capacity, and kernel removable flag). Windows device discovery is not implemented yet. The tool never writes to storage.

## Current status

Milestone 0 is complete as a repository scaffold. Milestone 1 has begun: read-only Linux storage discovery is implemented. Windows discovery, the desktop app, ISO booting, partitioning, formatting, Secure Boot signing, and physical USB writing are not implemented yet.

## Verified locally

Build and hardware validation for the M1 device-discovery changes are pending. Do not treat this source update as a tested release.
