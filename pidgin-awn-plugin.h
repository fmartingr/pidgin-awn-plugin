/*
 * AWN plugin for Pidgin
 * Copyright (C) 2010 Felipe (Pyronhell) Martin <pyronhell@gmail.com>
 * Copyright from other people that wrote code with another purpose:
 * Copyright (C) 2007 Michael (mycroes) Croes <mycroes@gmail.com>
 * Copyright (C) 2002-3 Robert McQueen <robot101@debian.org>
 * Copyright (C) 2003 Herman Bloggs <hermanator12002@yahoo.com>
 *
 * Continued work from the plugin of:
 * Michael (mycroes) Croes <mycroes@gmail.com>
 * Which was in turn inspired by a similar plugin by:
 * Robert McQueen <robot101@debian.org>
 * Herman Bloggs <hermanator12002@yahoo.com>
 * Which was in turn inspired by a similar plugin by:
 * John (J5) Palmieri <johnp@martianrock.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef _PIDGIN_AWN_H_
#define _PIDGIN_AWN_H_

/* Hardcoded icon paths */
#define PATH_IMG_AWAY			"~/.purple/plugins/pidgin-awn-plugin/pidgin-away.png"
#define PATH_IMG_CONNECTING		"~/.purple/plugins/pidgin-awn-plugin/pidgin-login.png"
#define PATH_IMG_OFFLINE		"~/.purple/plugins/pidgin-awn-plugin/pidgin-offline.png"
#define PATH_IMG_ONLINE			"~/.purple/plugins/pidgin-awn-plugin/pidgin-online.png"

/* Enum(s) */
typedef enum
{
	AWN_STATUS_OFFLINE,
	AWN_STATUS_ONLINE,
	AWN_STATUS_ONLINE_PENDING,
	AWN_STATUS_AWAY,
	AWN_STATUS_AWAY_PENDING,
	AWN_STATUS_CONNECTING
} AwnStatus;

/* Function prototypes */
static void setAwnIcon(char *);
static void unsetAwnIcon();
static void setAwnInfo(char *);
static void unsetAwnInfo();
static void update_icon(AwnStatus);
static GList * get_pending_list();
static gboolean awn_update_status();
static gboolean plugin_load(PurplePlugin *);
static gboolean plugin_unload(PurplePlugin *);

#endif /*_PIDGIN_AWN_H_*/
