/* IBInspector.h
 *
 * Copyright (C) 2003 Free Software Foundation, Inc.
 *
 * Author:	Gregory John Casamento <greg_casamento@yahoo.com>
 * Date:	2003
 * 
 * This file is part of GNUstep.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef INCLUDED_IBPALETTE_H
#define INCLUDED_IBPALETTE_H

#include <Foundation/NSMapTable.h>
#include <Foundation/NSObject.h>
#include <InterfaceBuilder/IBDocuments.h>
#include <InterfaceBuilder/IBSystem.h>

// forward references
@class NSString;
@class NSImage;
@class NSWindow;
@class NSView;

/*
 * Pasteboard types used for DnD when views are dragged out of a palette
 * window into another window in Gorm (or, in the case of IBWindowPboardType
 * onto the desktop).
 */
IB_EXPORT NSString	*IBCellPboardType;
IB_EXPORT NSString	*IBMenuPboardType;
IB_EXPORT NSString	*IBMenuCellPboardType;
IB_EXPORT NSString	*IBObjectPboardType;
IB_EXPORT NSString	*IBViewPboardType;
IB_EXPORT NSString	*IBWindowPboardType;
IB_EXPORT NSString	*IBFormatterPboardType;

/*
 * Pasteboard types used for DnD from images or sounds tab
 * to views or inspector's textfield onto the desktop).
 * NOTE: These are specific to Gorm... 
 */
IB_EXPORT NSString	*GormImagePboardType;
IB_EXPORT NSString	*GormSoundPboardType;
IB_EXPORT NSString      *GormLinkPboardType;

@interface IBPalette : NSObject
{
  NSWindow	  *originalWindow;
  NSImage	  *icon;
  id<IBDocuments> document;
}
/*
 * For internal use only - these class methods return the information
 * associated with a particular view.
 */
+ (id) objectForView: (NSView*)aView;
+ (NSString*) typeForView: (NSView*)aView;

/**
 * Associate a particular object and DnD type with a view - so that
 * Gorm knows to initiate a DnD session with the specified object
 * and type rather than an archived copy of the view itsself and
 * the default type (IBViewPboardType).
 */
- (void) associateObject: (id)anObject
		    type: (NSString*)aType
		    with: (NSView*)aView;

/**
 * Releases all the instance variables apart from the window (which is
 * presumed to release itsself when closed) and removes self as an observer
 * of notifications before destroying self.
 */
- (void) dealloc;

/**
 * Method called by GUI builder application when a new palette has been created 
 * and its model (nib/gorm) has been loaded.  Any palette initialization should 
 * be done here.
 */
- (void) finishInstantiate;

/**
 * Return the icon representing the palette.
 */
- (NSImage*) paletteIcon;

/**
 * Return the window containing the views that may be dragged from the
 * palette.
 */
- (NSWindow*) originalWindow;

/**
 * Returns an object representing the palette which conforms to the
 * IBDocuments protocol.
 */
- (id<IBDocuments>) paletteDocument;
@end
#endif
