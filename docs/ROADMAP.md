# Roadmap

## M0 — Foundation (current)
- Product identity and repository layout
- Portable C core
- Build and unit-test baseline
- Architecture and safety boundaries

## M1 — Read-only diagnostics
- Cross-platform device enumeration
- USB / storage metadata
- SMART capability detection (no drive modification)
- Structured diagnostic report

## M2 — Image inspection
- ISO metadata parser
- SHA-256 verification
- Known-image profile format
- Input fuzz tests

## M3 — Virtual UEFI boot prototype
- EDK II integration
- QEMU + OVMF test harness
- Boot menu prototype using legally compatible components

## M4 — Controlled USB deployment
- Explicit target-device selection
- Clear data-loss warning and confirmation
- Verify-after-write workflow
- Recovery and failure handling

## M5 — Compatibility and release
- Windows and Linux host support
- UEFI matrix; Legacy BIOS only after separate validation
- Secure Boot design and signing process
- Reproducible builds and release provenance
