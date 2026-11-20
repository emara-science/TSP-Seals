# Open-source dependency policy

Candidate upstream projects:

- **EDK II** — UEFI development environment; BSD-2-Clause-Patent licensing is used by the project. Pin a specific release/commit and retain notices.
- **GRUB 2** — candidate bootloader integration; GPLv3-or-later licensing has important distribution and linking implications. Keep integration boundaries explicit and obtain license review before distribution.
- **QEMU** — machine emulation for automated test environments.
- **OVMF** — UEFI firmware image used with QEMU for virtual testing.
- **CMake** — cross-platform build configuration.
- **.NET** — proposed desktop application runtime/toolchain for a later milestone.

This list is an evaluation shortlist, not a claim that these projects are already vendored or linked into this repository. Before shipping, create an SBOM, pin exact versions, scan licenses, and include all required notices.
