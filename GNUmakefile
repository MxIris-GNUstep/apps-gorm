#   GNUmakefile: main makefile for GNUstep Object Relationship Modeller
#
#   Copyright (C) 1999 Free Software Foundation, Inc.
#
#   Author:  Richard Frith-Macdonald <richard@brainstorm.co.uk>
#   Date: 1999
#   
#   This file is part of GNUstep.
#   
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#   
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#   
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA
#

include $(GNUSTEP_MAKEFILES)/common.make

#
# Each palette is a subproject
#
SUBPROJECTS = \
	Menu \
	Text \
	View \
	Window 

#
# MAIN APP
#
APP_NAME = Gorm
Gorm_APPLICATION_ICON=Gorm.tiff
Gorm_RESOURCE_FILES = \
	Menu/Menu.palette \
	Text/Text.palette \
	View/View.palette \
	Window/Window.palette \
	Images/GormClass.tiff \
	Images/GormFilesOwner.tiff \
	Images/GormFirstResponder.tiff \
	Images/GormFontManager.tiff \
	Images/GormImage.tiff \
	Images/GormWindow.tiff \
	Images/GormMenu.tiff \
	Images/GormObject.tiff \
	Images/GormSound.tiff \
        Images/Gorm.tiff \
        Images/GormLinkImage.tiff

Gorm_HEADERS = \
	Gorm.h \
	GormPrivate.h

Gorm_OBJC_FILES = \
        Gorm.m \
	GormDocument.m \
	IBInspector.m \
	IBPalette.m \
	InfoPanel.m \
	GormViewKnobs.m \
	GormObjectEditor.m \
	GormWindowEditor.m \
	GormInspectorsManager.m \
	GormPalettesManager.m \
	GormResourcesManager.m

-include GNUmakefile.preamble

-include GNUmakefile.local

include $(GNUSTEP_MAKEFILES)/aggregate.make
include $(GNUSTEP_MAKEFILES)/application.make
include $(GNUSTEP_MAKEFILES)/bundle.make

-include GNUmakefile.postamble
