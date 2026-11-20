# TSP SEALS — Architecture (Milestone 0)

## Design principles

1. **Safety before convenience:** read-only discovery first; destructive operations require a separate, explicit confirmation layer.
2. **Modularity:** bootloader, image validation, device discovery, and UI communicate through documented interfaces.
3. **Reproducibility:** pinned dependencies, recorded build inputs, automated tests, and virtual firmware testing.
4. **License hygiene:** every imported component gets a version, upstream URL, license identifier, notices, and a documented integration boundary.
5. **No false compatibility claims:** each firmware/filesystem/OS combination must be tested and recorded.

## Logical components

- **TSP Core:** shared types, logging, configuration, error model.
- **Device Discovery:** read-only enumeration and device metadata.
- **Image Inspector:** ISO metadata and checksum verification.
- **Boot Integration:** EDK II / UEFI application boundary; GRUB integration evaluated separately.
- **Desktop Shell:** future C# UI for Windows and Linux.
- **Test Harness:** QEMU + OVMF virtual boot matrix.

## Boot strategy

UEFI is the first implementation target because it provides a defined application and boot-services model. Legacy BIOS support is a later compatibility milestone and may require a separate boot path.

GRUB is a candidate integration, not a blanket solution: ISO boot behavior varies by distribution and image layout. Each supported image needs a tested profile.

## Security boundaries

- Never execute files from an ISO during inspection.
- Treat image names, metadata, and configuration as untrusted input.
- Verify downloaded image checksums/signatures where upstream publishers provide them.
- Do not write partition tables or format media in Milestone 0.
- Secure Boot support requires a documented key/signing model and tests; it is not claimed by this scaffold.
