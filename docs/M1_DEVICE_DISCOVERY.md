# M1 — Read-only device discovery

## Implemented in this commit

- Linux host enumeration through `/sys/block`.
- Reports whole-disk device name, conventional `/dev/<name>` path, capacity, and removable flag when the kernel exposes it.
- Skips common virtual memory devices (`loop*`, `ram*`, and `zram*`).
- Uses metadata reads only. It does not open disks for writing, mount them, partition them, format them, or copy data.

## Current limitations

- Linux implementation only. Other platforms currently return an empty list.
- The removable flag is supplied by the Linux kernel and is not a guarantee that a device is a USB drive.
- Device capacity uses the Linux sysfs 512-byte sector count.
- This is an early inventory feature, not yet a safe USB-target selection or imaging workflow.

## Next work

1. Add Windows enumeration using documented storage APIs and test on Windows.
2. Add stable device identifiers and human-readable model/vendor information.
3. Add tests for parsing and capacity overflow.
4. Add a UI that displays devices without enabling destructive actions.
