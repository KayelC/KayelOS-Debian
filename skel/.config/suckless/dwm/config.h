/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 6;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 0;        /* 0 means no systray (quickshell bar has an SNI tray) */
static const int statusallmons      = 1;        /* statusallmons patch: 1 draws status on every monitor, 0 only on selected */
static const int vertpad            = 8;       /* vertical padding of bar */
static const int sidepad            = 8;       /* horizontal padding of bar */
static const unsigned int gappih    = 8;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;       /* vert inner gap between windows */
static const unsigned int gappoh    = 8;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;       /* vert outer gap between windows and screen edge */
static int smartgaps                = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 0;        /* 0 means no bar (quickshell; Mod+Ctrl+b for native fallback) */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font Mono:size=12" };
static const char dmenufont[]       = "monospace:size=10";
/* xresources patch: drop const so values can be overridden at startup
 * from ~/.Xresources via the resources[] mapping below */
static char col_gray1[]       = "#17171c";  /* normbgcolor */
static char col_gray3[]       = "#d2cbbc";  /* normfgcolor */
static char col_gray4[]       = "#3c2d2a";  /* normbordercolor */
static char col_cyan[]        = "#d88c79";  /* selbgcolor */
static char col_barbie[]      = "#d88c79";  /* selbordercolor */
static char col_selfg[]       = "#17171c";  /* selfgcolor — own buffer so it can differ from normbordercolor */
static char *colors[][3]            = {
	/*               fg         bg         border    */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray4 },
	[SchemeSel]  = { col_selfg, col_cyan,  col_barbie },
};

/* Xresources keys -> dwm vars. Set in ~/.Xresources e.g.:
 *   dwm.normbgcolor: #00141d
 *   dwm.selbgcolor:  #b3e5fc
 * Then `xrdb -merge ~/.Xresources` and restart dwm (Mod+Shift+r).
 * NOTE: col_gray4 is shared by SchemeNorm.border and SchemeSel.fg, so
 * setting either normbordercolor or selfgcolor changes both. */
ResourcePref resources[] = {
	{ "normbgcolor",     STRING, &col_gray1 },
	{ "normfgcolor",     STRING, &col_gray3 },
	{ "normbordercolor", STRING, &col_gray4 },
	{ "selbgcolor",      STRING, &col_cyan  },
	{ "selfgcolor",      STRING, &col_selfg },
	{ "selbordercolor",  STRING, &col_barbie },
};

static const char *const autostart[] = {
	"sh", "-c", "~/.config/suckless/scripts/autostart.sh", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" };
#include "scratchtagwins.c"

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   iscentered   monitor    scratch key */
	{ "Gimp",     NULL,       NULL,       0,            1,           1,           -1,        0  },
	{ "mpv",      NULL,       NULL,       0,            1,           1,           -1,        0  },
	{ "qimgv",    NULL,       NULL,       0,            1,           1,           -1,        0  },
	{ "Nwg-look", NULL,       NULL,       0,            1,           1,           -1,        0  },
	/* quickshell-network sets no WM_CLASS; match its title (like bspwm's rule) */
	{ NULL,       NULL,       "Network",  0,            1,           1,           -1,        0  },
	{ NULL,   "scratchpad",   NULL,       0,            1,           1,           -1,       's' },
	{ NULL,   "pulsemixer",   NULL,       0,            1,           1,           -1,       'a' },
	SCRATCHTAGWIN_RULE (scratchtagwin1, 1),
	SCRATCHTAGWIN_RULE (scratchtagwin2, 2),
	SCRATCHTAGWIN_RULE (scratchtagwin3, 3),
	SCRATCHTAGWIN_RULE (scratchtagwin4, 4),
	SCRATCHTAGWIN_RULE (scratchtagwin5, 5),
	SCRATCHTAGWIN_RULE (scratchtagwin6, 6),
	SCRATCHTAGWIN_RULE (scratchtagwin7, 7),
	SCRATCHTAGWIN_RULE (scratchtagwin8, 8),
	SCRATCHTAGWIN_RULE (scratchtagwin9, 9),
};

/* window following */
#define WFACTIVE '>'
#define WFINACTIVE 'v'
#define WFDEFAULT WFACTIVE

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󰕴",      dwindle },                 /* first entry is default */
	{ "󰙀",      tile },
	{ "󰕭",      columnlayout },
	{ "󰕬",      centeredmaster },
	{ "󰕰",      NULL },                    /* no layout function means floating behavior */
	{ "󱒈",      bstack },
	{ "󰕯",      nrowgrid },
	{ "󱇙",      deck },
	{ "󰕫",      gaplessgrid },
	{ "󰪷",      spiral },
	{ "󰕮",      monocle },
	{ "󰝘",      grid },
	{ "󱒉",      bstackhoriz },            /* no keybinding */
	{ "󰕱",      centeredfloatingmaster },  /* no keybinding */
	{ "󱇚",      horizgrid },              /* no keybinding */
	{ NULL,      NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "kitty", NULL };

SCRATCHTAGWIN (scratchtagwin1, 1);
SCRATCHTAGWIN (scratchtagwin2, 2);
SCRATCHTAGWIN (scratchtagwin3, 3);
SCRATCHTAGWIN (scratchtagwin4, 4);
SCRATCHTAGWIN (scratchtagwin5, 5);
SCRATCHTAGWIN (scratchtagwin6, 6);
SCRATCHTAGWIN (scratchtagwin7, 7);
SCRATCHTAGWIN (scratchtagwin8, 8);
SCRATCHTAGWIN (scratchtagwin9, 9);

/*First arg only serves to match against key in rules*/
/* --name sets the WM_CLASS instance the rules match on; kitty rewrites
   titles at runtime, so title matching would lose the scratchkey. */
static const char *scratchpadcmd[] = {"s", "kitty", "--name", "scratchpad", NULL};
static const char *pulsemixercmd[] = {"a", "kitty", "--name", "pulsemixer", "-e", "pulsemixer", NULL};


#include "movestack.c"
/* keys[] is annotated for scripts/gen-keybinds, which regenerates
 * keybindings.txt (the Super+/ help) on every build:
 *   /o === NAME === o/          section header
 *   trailing /o description o/  help text for that binding ("!" pins to top)
 *   /o @help key :: desc o/     hand-written row for macro-generated bindings
 * (o = *). Bindings without a trailing comment don't appear in the help. */
static const Key keys[] = {
	/* modifier                     key        function        argument */

	/* === LAUNCH === */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },  /* !Terminal (kitty) */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } }, /* dmenu_run */

	/* === WINDOW === */
	{ MODKEY,                       XK_q,      killclient,     {0} },              /* !Close focused window */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },       /* Focus next window */
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },       /* Focus previous window */
	{ MODKEY,                       XK_Left,   focusstack,     {.i = -1 } },       /* Focus previous window */
	{ MODKEY,                       XK_Right,  focusstack,     {.i = +1 } },       /* Focus next window */
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },       /* Move window down in stack */
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },       /* Move window up in stack */
	{ MODKEY|ShiftMask,             XK_Left,   movestack,      {.i = -1 } },       /* Move window up in stack */
	{ MODKEY|ShiftMask,             XK_Right,  movestack,      {.i = +1 } },       /* Move window down in stack */
	{ MODKEY,                       XK_Tab,    view,           {0} },              /* Toggle previous tag */
	{ MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} },              /* Toggle fullscreen */
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },              /* Toggle floating */
	{ MODKEY,                       XK_y,      togglesticky,   {0} },              /* Toggle sticky (show on all tags) */
	{ MODKEY,                       XK_n,      togglefollow,   {0} },              /* Toggle window-follow on tag/monitor change */
	{ MODKEY|ControlMask,           XK_b,      togglebar,      {0} },              /* Toggle bar */
	{ MODKEY,                       XK_apostrophe, spawn,      SHCMD("rofi -show window -theme \"$HOME/.config/suckless/rofi/window.rasi\"") }, /* Window switcher (rofi, all tags/monitors) */

	/* === LAYOUT === */
	{ MODKEY,                       XK_h,      resizefocused,  {.f = -0.05} },     /* !Resize: shrink master / shrink column */
	{ MODKEY,                       XK_l,      resizefocused,  {.f = +0.05} },     /* !Resize: grow master / grow column */
	{ MODKEY|ControlMask,           XK_Left,   resizefocused,  {.f = -0.05} },     /* Resize: shrink (layout-aware) */
	{ MODKEY|ControlMask,           XK_Right,  resizefocused,  {.f = +0.05} },     /* Resize: grow (layout-aware) */
	{ MODKEY,                       XK_semicolon, resetfacts,  {0} },              /* Reset master + column factors */
	{ MODKEY|ALTKEY,              XK_Tab,    incnmaster,     {.i = +1 } },       /* Master count +1 */
	{ MODKEY|ALTKEY|ShiftMask,    XK_Tab,    incnmaster,     {.i = -1 } },       /* Master count -1 */
	/*{ MODKEY,                       XK_space,  setlayout,      {0} }, */
	{ ShiftMask|ControlMask,        XK_1,      setlayout,      {.v = &layouts[0] } },  /* Layout: dwindle */
	{ ShiftMask|ControlMask,        XK_2,      setlayout,      {.v = &layouts[1] } },  /* Layout: tile */
	{ ShiftMask|ControlMask,        XK_3,      setlayout,      {.v = &layouts[2] } },  /* Layout: columns (cfact-weighted) */
	{ ShiftMask|ControlMask,        XK_4,      setlayout,      {.v = &layouts[3] } },  /* Layout: centered master */
	{ ShiftMask|ControlMask,        XK_5,      setlayout,      {.v = &layouts[4] } },  /* Layout: floating */
	{ ShiftMask|ControlMask,        XK_6,      setlayout,      {.v = &layouts[5] } },  /* Layout: bstack */
	{ ShiftMask|ControlMask,        XK_7,      setlayout,      {.v = &layouts[6] } },  /* Layout: nrowgrid */
	{ ShiftMask|ControlMask,        XK_8,      setlayout,      {.v = &layouts[7] } },  /* Layout: deck */
	{ ShiftMask|ControlMask,        XK_9,      setlayout,      {.v = &layouts[8] } },  /* Layout: gaplessgrid */
	{ ShiftMask|ControlMask,        XK_0,      setlayout,      {.v = &layouts[9] } },  /* Layout: spiral */
	{ ShiftMask|ControlMask,        XK_minus,  setlayout,      {.v = &layouts[10] } }, /* Layout: monocle */
	{ ShiftMask|ControlMask,        XK_equal,  setlayout,      {.v = &layouts[11] } }, /* Layout: grid */

	/* === TAGS === */
	/* @help Super + 1..9, 0, -, = :: !View tag 1..12 */
	/* @help Super + Shift + 1..= :: Send focused window to tag */
	/* @help Super + Ctrl + 1..= :: Toggle tag visibility */
	/* @help Super + Ctrl + Shift + 1..= :: Toggle window on tag */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9)
	TAGKEYS(                        XK_minus,                  10)
	TAGKEYS(                        XK_equal,                  11)
	{ ControlMask|ShiftMask,        XK_Left,   viewtoleft,     {0} },              /* View previous tag */
	{ ControlMask|ShiftMask,        XK_Right,  viewtoright,    {0} },              /* View next tag */
	{ ALTKEY|ControlMask,         XK_Left,   tagtoleft,      {0} },              /* Send window to previous tag */
	{ ALTKEY|ControlMask,         XK_Right,  tagtoright,     {0} },              /* Send window to next tag */

	/* === MONITOR === */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },       /* Focus previous monitor */
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },       /* Focus next monitor */
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },       /* Send window to previous monitor */
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },       /* Send window to next monitor */

	/* === SCRATCHPAD === */
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } }, /* !Toggle scratchpad (kitty) */
	{ MODKEY,                       XK_v,      togglescratch,  {.v = pulsemixercmd } }, /* Toggle pulsemixer */
	/* @help Super + Alt + 1..9 :: Toggle named scratch slot 1..9 */
	/* @help Super + Alt + Shift + 1..9 :: Promote focused window into slot */
	SCRATCHTAGWIN_KEY (scratchtagwin1, 1)
	SCRATCHTAGWIN_KEY (scratchtagwin2, 2)
	SCRATCHTAGWIN_KEY (scratchtagwin3, 3)
	SCRATCHTAGWIN_KEY (scratchtagwin4, 4)
	SCRATCHTAGWIN_KEY (scratchtagwin5, 5)
	SCRATCHTAGWIN_KEY (scratchtagwin6, 6)
	SCRATCHTAGWIN_KEY (scratchtagwin7, 7)
	SCRATCHTAGWIN_KEY (scratchtagwin8, 8)
	SCRATCHTAGWIN_KEY (scratchtagwin9, 9)
	{ MODKEY|ALTKEY|ShiftMask,     XK_s,      makescratchtagwin,  {.i = 's'} },   /* Promote focused window to scratchpad */
	{ MODKEY|ALTKEY|ShiftMask,     XK_grave,  makescratchtagwin,  {.i = 0} },     /* Clear scratch state on focused window */

	/* === GAPS === */
	{ MODKEY|ALTKEY,              XK_0,      togglegaps,     {0} },              /* !Toggle gaps on/off */
	{ MODKEY|ALTKEY|ShiftMask,    XK_0,      defaultgaps,    {0} },              /* Reset gaps to defaults */
	{ MODKEY|ALTKEY,              XK_u,      incrgaps,       {.i = 1 } },        /* Increase all gaps */
	{ MODKEY|ALTKEY|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },       /* Decrease all gaps */
	{ MODKEY|ALTKEY,              XK_i,      incrigaps,      {.i = 1 } },        /* Increase inner gaps */
	{ MODKEY|ALTKEY|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },       /* Decrease inner gaps */
	{ MODKEY|ALTKEY,              XK_o,      incrogaps,      {.i = 1 } },        /* Increase outer gaps */
	{ MODKEY|ALTKEY|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },       /* Decrease outer gaps */
	{ MODKEY|ALTKEY,              XK_6,      incrihgaps,     {.i = 1 } },        /* Inner horizontal gap +1 */
	{ MODKEY|ALTKEY|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },       /* Inner horizontal gap -1 */
	{ MODKEY|ALTKEY,              XK_7,      incrivgaps,     {.i = 1 } },        /* Inner vertical gap +1 */
	{ MODKEY|ALTKEY|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },       /* Inner vertical gap -1 */
	{ MODKEY|ALTKEY,              XK_8,      incrohgaps,     {.i = 1 } },        /* Outer horizontal gap +1 */
	{ MODKEY|ALTKEY|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },       /* Outer horizontal gap -1 */
	{ MODKEY|ALTKEY,              XK_9,      incrovgaps,     {.i = 1 } },        /* Outer vertical gap +1 */
	{ MODKEY|ALTKEY|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },       /* Outer vertical gap -1 */

	/* === SYSTEM === */
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} },              /* !Restart dwm (preserves tags/windows) */
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },              /* Quit dwm */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkFollowSymbol,      0,              Button1,        togglefollow,   {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
