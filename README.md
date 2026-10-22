# KayelOS

KayelOS is a Debian 13 based Linux environment built for classroom,
development, and everyday use.

It combines a lightweight DWM desktop with QuickShell, development tools, and an installable live environment.

## Current release

**KayelOS 1.0**

- Architecture: amd64
- Base: Debian 13
- Desktop: dwm
- Installer: Calamares via Penguins' Eggs

## Release checksum

KayelOS-1.0-amd64.iso

SHA-256:

969b998b006107eb39c0917046b8c12d071b93ffad5bcf43cb261234b758137c

The ISO itself is intentionally not stored in this Git repository.

## Repository layout

- branding/ - KayelOS and installer branding
- configs/ - KayelOS application configuration
- skel/ - default files installed into new users' home directories
- scripts/ - KayelOS helper and installer scripts
- grub/ - KayelOS GRUB greeting configuration
- packages/ - package manifests
- system/ - operating-system identity/configuration
- releases/ - release checksums
- docs/ - project documentation

## License

KayelOS-original code is distributed under the GNU General Public License
version 3 where applicable.

KayelOS also incorporates third-party projects. Those components retain their
respective upstream licenses. See THIRD_PARTY.md.
