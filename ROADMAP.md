# KayelOS 1.1 — Polish Roadmap

KayelOS 1.0 is frozen and remains the first stable release.

The goal of KayelOS 1.1 is not to redesign the system. It is to clean up rough edges, remove stale or misleading content, improve the installer experience, refine the default software selection, and make the distro feel deliberate from boot to daily use.

## 1. Installer / Calamares Polish

### Branding
- Replace the current placeholder/repeated slideshow images.
- Remove leftover Penguins' Eggs-style wording and awkward taglines from anything user-facing.
- Keep internal Eggs identifiers where technically required.
- Create a consistent KayelOS visual style for:
  - Welcome page
  - Installation slideshow
  - Logo
  - Finished-installation page

### Slideshow
Reduce the installer slideshow to a small number of useful slides rather than filler.

Possible topics:
- Welcome to KayelOS
- Lightweight DWM workflow
- Classroom / development environment
- Installation complete / getting started

Avoid marketing-style slogans that do not add useful information.

### Installer behaviour
- Re-test the Rofi → wrapper → pkexec → Eggs → Calamares path.
- Verify the installer launcher only exists in the live environment.
- Verify fresh installations do not inherit installer launchers.
- Review error handling if Calamares fails to launch.

### Live-session security
- Replace the current weak/default live-session password configuration if possible.
- Check whether passwordless or another Eggs-supported approach gives a better live-user experience.

---

## 2. Super + / Keybind Helper Audit

The keybind helper should become a trustworthy reference rather than inherited documentation.

### Audit every displayed shortcut
Check the helper against the actual DWM, sxhkd, Rofi and QuickShell configuration.

For each entry:
- Does the shortcut actually work?
- Does the named application still exist?
- Is the description accurate?
- Is the shortcut worth advertising to students?

### Remove stale information
Examples include:
- Helium browser references
- Applications no longer installed
- Old JustAGuyLinux defaults that KayelOS changed
- Duplicate shortcuts
- Experimental shortcuts
- Shortcuts pointing at scripts that no longer exist

### Longer-term improvement
Ideally there should eventually be one authoritative source for keybindings so the helper cannot drift away from the real configuration.

For 1.1, accuracy is more important than automating this.

---

## 3. Default Package Audit

Review the existing KayelOS package manifest deliberately instead of adding/removing packages ad hoc.

### Remove
Candidates already identified:
- OBS Studio, unless there is a clear classroom use case

Also inspect for:
- Duplicate utilities
- Unused desktop applications
- Leftover packages from experimentation
- Applications exposed in menus but not intended for students
- Large packages with little value

### Keep
Likely examples:
- Git
- Discord, if wanted for the classroom
- Development tools
- Core DWM/QuickShell dependencies
- Fonts
- Calamares / Eggs requirements
- Useful terminal tools

### Consider adding
Review categories rather than randomly choosing applications:

- Web browser
- Code editor / IDE
- Office/document tools
- PDF reader
- Archive manager
- Image viewer
- Media player
- Screenshot tools
- Networking utilities
- Disk/USB utilities
- Development/compiler tools
- Classroom utilities

Every added package should have a reason for being part of the KayelOS default installation.

### Package-manifest rule
Only regenerate:

`/usr/share/kayelos/package-manifest.txt`

after the 1.1 package set is finalized.

---

## 4. Desktop Experience Audit

Walk through KayelOS as though using it for the first time.

Check:

- DWM keybindings
- QuickShell bar
- Launcher
- Power menu
- Network controls
- Volume controls
- Media controls
- Notifications
- Weather widget
- Screenshot tools
- Wallpaper picker
- Terminal
- File manager
- Browser
- Default applications
- Rofi menus

Look specifically for:
- Dead buttons
- Incorrect commands
- Missing dependencies
- Old application names
- Upstream branding
- Layout inconsistencies
- Things that work only on the development VM

Do not redesign working components simply for the sake of changing them.

---

## 5. Shell / Terminal Polish

Review:

- Bash prompt
- Aliases
- Shell functions
- Fastfetch
- Startup messages
- Terminal theme

Remove:
- Dead aliases
- Machine-specific commands
- References to old applications
- Commands that assume software we no longer ship

Keep the existing KayelOS prompt and Fastfetch appearance unless an actual problem is found.

---

## 6. Branding Consistency

Audit all visible names and icons.

Search for:

- Debian branding that should say KayelOS
- Penguins' Eggs branding visible to users
- JustAGuyLinux text that should instead be attributed rather than presented as the OS name
- Old hostnames/usernames
- Generic placeholder artwork
- Inconsistent capitalization such as KayelOS / Kayelos / kayelos

Areas:
- Calamares
- GRUB
- Fastfetch
- QuickShell
- Rofi
- Desktop launchers
- `/etc/os-release`
- Application comments/descriptions

Do not remove legitimate upstream copyright/license attribution.

---

## 7. `/etc/skel` Audit

Re-run the fresh-user audit after all desktop changes.

Check:
- No `/home/kayel`
- No `sealink-dev`
- No factory-user ownership
- No histories
- No SSH/GPG material
- No secrets/tokens
- No VMware-specific display configuration
- Correct default configs
- Correct wallpapers
- Correct executable permissions

Create a fresh user and verify the resulting home directory rather than assuming `/etc/skel` is correct.

---

## 8. ISO Size / Distribution

KayelOS 1.0 is larger than GitHub's single-release-asset limit and therefore needs multipart distribution.

For 1.1:
- Measure what consumes the most ISO space.
- Determine how much removing unnecessary packages such as OBS saves.
- Check the wallpaper collection size.
- Check package caches/build leftovers.
- Review Eggs compression settings.

Goal:

**Try to bring KayelOS below GitHub's single-file asset limit without damaging the intended experience.**

If this can be achieved naturally, KayelOS 1.1 can return to a single-click ISO download.

Do not sacrifice useful software solely to hit the size target.

---

## 9. Hardware / Installation Testing

Test the finished 1.1 candidate in more than the development VM.

Minimum validation:
- VMware fresh installation
- UEFI boot/install
- Fresh non-factory username
- Fresh custom hostname

Where possible also test:
- VirtualBox
- Real USB boot
- Real hardware
- Wi-Fi
- Ethernet
- Audio
- Bluetooth
- Multiple displays
- Intel/AMD graphics

Record anything hardware-specific rather than baking machine-specific fixes into `/etc/skel`.

---

## 10. Release Hygiene

Before building 1.1:

- Update `VERSION`
- Update `CHANGELOG.md`
- Update README if behaviour changed
- Refresh package manifest
- Refresh repo copies of changed configs
- Run privacy scan
- Run shell syntax checks
- Verify executable permissions
- Build candidate ISO
- Calculate SHA-256
- Perform fresh-install validation
- Tag the exact tested source snapshot
- Publish release only after validation

The KayelOS 1.0 tag and ISO remain untouched.

---

# Deferred Until After 1.1

## `kayelos-update`

Do not build the full updater until the KayelOS-managed file set is stable.

Before implementing it, decide:

- Which files KayelOS owns
- Which files belong to the user
- Whether modified user configs are overwritten, merged or skipped
- How versions are compared
- How downloads are authenticated/verified
- How failed updates roll back
- How package changes are handled

A simple updater script is easy to write.

A safe updater that respects users' customizations is a design problem.

That makes it a better project after the 1.1 polish work.

---

# Current Priority Order

1. Calamares branding and installer text
2. Super + / keybind helper
3. Package keep/remove/add audit
4. Desktop commands and menus
5. Shell/config cleanup
6. Branding consistency sweep
7. `/etc/skel` rebuild/audit
8. ISO-size optimization
9. Fresh-install/hardware testing
10. KayelOS 1.1 release
11. Update-system design
