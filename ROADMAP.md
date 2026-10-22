# KayelOS 1.1 — Polish Roadmap

KayelOS 1.0 is frozen and remains the first stable release.

The goal of KayelOS 1.1 is not to redesign the system. It is to clean up rough edges, remove stale or misleading content, improve the installer and login experience, refine the default software selection, and make the distro feel deliberate from boot to daily use.

---

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

## 2. Login / LightDM Greeter Polish

KayelOS currently uses:

- LightDM
- `lightdm-gtk-greeter`
- `lightdm-gtk-greeter-settings`

The current login screen is functional but visually plain and does not yet match the rest of the KayelOS experience.

### Appearance

- Add a KayelOS-branded login wallpaper.
- Review the existing LightDM GTK greeter configuration.
- Improve the GTK theme used by the greeter.
- Improve fonts, colors, spacing and layout where possible.
- Make the greeter visually consistent with the KayelOS desktop and installer.
- Keep the login screen lightweight and appropriate for DWM.
- Remove or replace generic Debian/LightDM branding where appropriate.
- Preserve legitimate upstream copyright and licensing information.

### Functionality

Verify that the following remain clear and functional:

- User selection
- Password entry
- DWM session selection
- Keyboard layout
- Restart
- Shutdown
- Accessibility controls, if present

### Validation

Test:

- Login after logout
- Login after reboot
- Incorrect password handling
- A newly created user
- DWM as the expected/default session
- Shutdown and restart controls
- Keyboard input and layout
- Wallpaper and theme on a fresh KayelOS installation

---

## 3. Super + / Keybind Helper Audit

The keybind helper should become a trustworthy KayelOS reference rather than inherited documentation.

### Audit every displayed shortcut

Check the helper against the actual:

- DWM configuration
- sxhkd configuration
- Rofi configuration
- QuickShell configuration
- KayelOS scripts

For each entry:

- Does the shortcut actually work?
- Does the named application still exist?
- Is the description accurate?
- Is the shortcut useful enough to advertise to students?

### Remove stale information

Examples include:

- Helium browser references
- Applications no longer installed
- Old JustAGuyLinux defaults that KayelOS changed
- Duplicate shortcuts
- Experimental shortcuts
- Shortcuts pointing at scripts that no longer exist
- Incorrect descriptions
- Commands that depend on removed packages

### Longer-term improvement

Ideally there should eventually be one authoritative source for keybindings so the helper cannot drift away from the real configuration.

For 1.1, accuracy is more important than automating this.

---

## 4. Default Package Audit

Review the existing KayelOS package manifest deliberately instead of adding or removing packages ad hoc.

### Remove

Candidates already identified:

- OBS Studio, unless there is a clear classroom use case

Also inspect for:

- Duplicate utilities
- Unused desktop applications
- Leftover packages from experimentation
- Applications exposed in menus but not intended for students
- Large packages with little practical value
- Packages that were only needed during KayelOS development

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

Review categories rather than randomly choosing applications.

#### Development

- Visual Studio Code
- Compiler/build tools
- Git tooling
- Language runtimes needed for lessons

VS Code is currently installed on the development system and should be evaluated as a possible default KayelOS 1.1 application rather than automatically added to the distro.

#### Desktop applications

- Web browser
- Office/document tools
- PDF reader
- Archive manager
- Image viewer
- Media player

#### System utilities

- Screenshot tools
- Networking utilities
- Disk/USB utilities
- Hardware information tools

#### Classroom utilities

- Communication software
- Educational tools
- Development/classroom-specific applications

Every added package should have a clear reason for being part of the default KayelOS installation.

### Package-manifest rule

Only regenerate:

`/usr/share/kayelos/package-manifest.txt`

after the KayelOS 1.1 package set is finalized.

---

## 5. Desktop Experience Audit

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
- Login/logout workflow

Look specifically for:

- Dead buttons
- Incorrect commands
- Missing dependencies
- Old application names
- Upstream branding
- Layout inconsistencies
- Controls that do nothing
- Things that only work on the development VM
- Things inherited from JustAGuyLinux that no longer match KayelOS

Do not redesign working components simply for the sake of changing them.

---

## 6. Shell / Terminal Polish

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
- Development-only helpers that should not reach students

Keep the existing KayelOS prompt and Fastfetch appearance unless an actual problem is found.

---

## 7. Branding Consistency

Audit all visible names, artwork and icons.

Search for:

- Debian branding that should say KayelOS
- Penguins' Eggs branding visible to users
- JustAGuyLinux text that should instead be attribution rather than the displayed OS identity
- Old hostnames/usernames
- Generic placeholder artwork
- Inconsistent capitalization such as KayelOS / Kayelos / kayelos
- Old application names
- Generic installer or login artwork

Areas:

- Calamares
- LightDM greeter
- GRUB
- Fastfetch
- QuickShell
- Rofi
- Desktop launchers
- `/etc/os-release`
- Application comments/descriptions
- Login/logout experience

Do not remove legitimate upstream copyright or license attribution.

---

## 8. `/etc/skel` Audit

Re-run the fresh-user audit after all desktop changes.

Check:

- No `/home/kayel`
- No `sealink-dev`
- No factory-user ownership
- No shell histories
- No SSH/GPG material
- No secrets or tokens
- No VMware-specific display configuration
- Correct default configs
- Correct wallpapers
- Correct executable permissions
- Correct keybind helper
- Correct launcher configuration
- Correct terminal configuration

Create a fresh user and verify the resulting home directory rather than assuming `/etc/skel` is correct.

---

## 9. ISO Size / Distribution

KayelOS 1.0 is larger than GitHub's single-release-asset limit and therefore requires multipart distribution.

For 1.1:

- Measure what consumes the most ISO space.
- Determine how much removing unnecessary packages such as OBS saves.
- Check the wallpaper collection size.
- Check package caches and build leftovers.
- Review Eggs compression settings.
- Check whether development-only packages accidentally remain installed.
- Measure the impact of any newly added packages such as VS Code.

### Goal

**Try to bring KayelOS below GitHub's single-file asset limit without damaging the intended experience.**

If this can be achieved naturally, KayelOS 1.1 can return to a single-click ISO download.

Do not sacrifice useful software solely to hit the size target.

If the ISO remains too large, keep the existing multipart system and improve the instructions/helpers where necessary.

---

## 10. Hardware / Installation Testing

Test the finished 1.1 candidate in more than the development VM.

### Minimum validation

- VMware fresh installation
- UEFI boot/install
- Fresh non-factory username
- Fresh custom hostname
- Fresh-user `/etc/skel` inheritance
- Login through LightDM
- DWM session startup

### Where possible

Also test:

- VirtualBox
- Real USB boot
- Real hardware
- Wi-Fi
- Ethernet
- Audio
- Bluetooth
- Multiple displays
- Intel graphics
- AMD graphics

Record hardware-specific issues rather than baking machine-specific fixes into `/etc/skel`.

---

## 11. Release Hygiene

Before building KayelOS 1.1:

- Update `VERSION`
- Update `CHANGELOG.md`
- Update `README.md` if behaviour changed
- Refresh package manifest
- Refresh repository copies of changed configs
- Run privacy scan
- Run shell syntax checks
- Verify executable permissions
- Verify Git LFS assets
- Build candidate ISO
- Calculate SHA-256
- Perform fresh-install validation
- Test LightDM on the installed system
- Test the keybind helper
- Test default applications
- Tag the exact tested source snapshot
- Publish the release only after validation

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
- How downloads are authenticated and verified
- How failed updates roll back
- How package changes are handled
- How configuration migrations are handled between releases

A simple updater script is easy to write.

A safe updater that respects users' customizations is a design problem.

That makes it a better project after the 1.1 polish work.

---

# Current Priority Order

1. LightDM login / greeter polish
2. Calamares branding and installer text
3. Super + / keybind helper audit
4. Package keep/remove/add audit
5. Desktop commands and menus
6. Shell/config cleanup
7. Branding consistency sweep
8. `/etc/skel` rebuild and fresh-user audit
9. ISO-size optimization
10. Fresh-install and hardware testing
11. KayelOS 1.1 release
12. Update-system design