/* Gorm.h
 *
 * Copyright (C) 1999 Free Software Foundation, Inc.
 *
 * Author:	Richard Frith-Macdonald <richard@brainstrom.co.uk>
 * Date:	1999
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

#ifndef GORM_H
#define GORM_H

#include <Foundation/Foundation.h>
#include <AppKit/AppKit.h>
#include <AppKit/NSNibConnector.h>
#include <AppKit/NSNibLoading.h>

/*
 * Positions of handles for resizing items.
 */
typedef enum {
  IBBottomLeftKnobPosition = 0,
  IBMiddleLeftKnobPosition = 1,
  IBTopLeftKnobPosition = 2,
  IBTopMiddleKnobPosition = 3,
  IBTopRightKnobPosition = 4,
  IBMiddleRightKnobPosition = 5,
  IBBottomRightKnobPosition = 6,
  IBBottomMiddleKnobPosition = 7,
  IBNoneKnobPosition = -1
} IBKnobPosition;

/*
 * Pasteboard types used for DnD when views are dragged out of a palette
 * window into another window in Gorm (or, in the case of IBWindowPboardType
 * onto the desktop).
 */
extern NSString	*IBCellPboardType;
extern NSString	*IBMenuPboardType;
extern NSString	*IBMenuCellPboardType;
extern NSString	*IBObjectPboardType;
extern NSString	*IBViewPboardType;
extern NSString	*IBWindowPboardType;

/*
 * Notification for editing and inspecting the objects etc.
 */
extern NSString *IBAttributesChangedNotification;
extern NSString *IBInspectorDidModifyObjectNotification;
extern NSString *IBSelectionChangedNotification;
extern NSString *IBDidOpenDocumentNotification;
extern NSString *IBWillSaveDocumentNotification;
extern NSString *IBDidSaveDocumentNotification;
extern NSString *IBWillCloseDocumentNotification;
extern NSString *IBWillBeginTestingInterfaceNotification;
extern NSString *IBDidBeginTestingInterfaceNotification;
extern NSString *IBWillEndTestingInterfaceNotification;
extern NSString *IBDidEndTestingInterfaceNotification;





/*
 * Connector objects are used to record connections between nib objects.
 */
@protocol IBConnectors <NSObject>
- (id) destination;
- (void) establishConnection;
- (NSString*) label;
- (void) replaceObject: (id)anObject withObject: (id)anotherObject;
- (id) source;
- (void) setDestination: (id)anObject;
- (void) setLabel: (NSString*)label;
- (void) setSource: (id)anObject;
@end

@interface NSObject (IBEditorSpecification)
- (NSString*) editorClassName;
@end

@protocol IBSelectionOwners <NSObject>
- (unsigned) selectionCount;
- (NSArray*) selection;
- (void) drawSelection;
@end

@protocol IBEditors <IBSelectionOwners>
- (BOOL) acceptsTypeFromArray: (NSArray*)types;
- (BOOL) activate;
- (id) initWithObject: (id)anObject inDocument: (id/*<IBDocuments>*/)aDocument;
- (void) close;
- (void) closeSubeditors;
- (void) copySelection;
- (void) deleteSelection;
- (id /*<IBDocuments>*/) document;
- (id) editedObject;
- (void) makeSelectionVisible: (BOOL)flag;
- (id<IBEditors>) openSubeditorForObject: (id)anObject;
- (void) orderFront;
- (void) pasteInSelection;
- (void) resetObject: (id)anObject;
- (void) selectObjects: (NSArray*)objects;
- (void) validateEditing;
- (BOOL) wantsSelection;
- (NSWindow*) window;
@end

@protocol IBDocuments <NSObject>
- (void) addConnector: (id<IBConnectors>)aConnector;
- (NSArray*) allConnectors;
- (void) attachObject: (id)anObject toParent: (id)aParent;
- (void) attachObjects: (NSArray*)anArray toParent: (id)aParent;
- (NSArray*) connectorsForDestination: (id)destination;
- (NSArray*) connectorsForDestination: (id)destination
			      ofClass: (Class)aConnectorClass;
- (NSArray*) connectorsForSource: (id)source;
- (NSArray*) connectorsForSource: (id)source
			 ofClass: (Class)aConnectorClass;
- (BOOL) containsObject: (id)anObject;
- (BOOL) containsObjectWithName: (NSString*)aName forParent: (id)parent;
- (BOOL) copyObject: (id)anObject
	       type: (NSString*)aType
       toPasteboard: (NSPasteboard*)aPasteboard;
- (BOOL) copyObjects: (NSArray*)anArray
		type: (NSString*)aType
	toPasteboard: (NSPasteboard*)aPasteboard;
- (void) detachObject: (id)anObject;
- (void) detachObjects: (NSArray*)anArray;
- (NSString*) documentPath;
- (BOOL) documentShouldClose;
- (void) documentWillClose;
- (void) editor: (id<IBEditors>)anEditor didCloseForObject: (id)anObject;
- (id<IBEditors>) editorForObject: (id)anObject
			   create: (BOOL)flag;
- (id<IBEditors>) editorForObject: (id)anObject
			 inEditor: (id<IBEditors>)anEditor
			   create: (BOOL)flag;
- (NSString*) nameForObject: (id)anObject;
- (NSArray*) objects;
- (id<IBEditors>) openEditorForObject: (id)anObject;
- (id<IBEditors>) parentEditorForEditor: (id<IBEditors>)anEditor;
- (id) parentOfObject: (id)anObject;
- (NSArray*) pasteType: (NSString*)aType
	fromPasteboard: (NSPasteboard*)aPasteboard
		parent: (id)parent;
- (void) removeConnector: (id<IBConnectors>)aConnector;
- (void) resignSelectionForEditor: (id<IBEditors>)editor;
- (void) setName: (NSString*)aName forObject: (id)object;
- (void) setSelectionFromEditor: (id<IBEditors>)anEditor;
- (void) touch;		/* Mark document as having been changed.	*/
@end

@protocol IB <NSObject>
- (id<IBDocuments>) activeDocument;
- (BOOL) isTestingInterface;
- (id<IBSelectionOwners>) selectionOwner;
- (id) selectedObject;
@end

@interface IBPalette : NSObject
{
  NSWindow	*window;
  NSImage	*icon;
}
/*
 * For internal use only - these class methods return the information
 * associated with a particular view.
 */
+ (id) objectForView: (NSView*)aView;
+ (NSString*) typeForView: (NSView*)aView;

/*
 * Associate a particular object and DnD type with a view - so that
 * Gorm knows to initiate a DnD session with the specified object
 * and type rather than an archived copy of the view itsself and
 * the default type (IBViewPboardType).
 */
- (void) associateObject: (id)anObject
		    type: (NSString*)aType
		    with: (NSView*)aView;

/*
 * Method called by Gorm when a new palette has been created and its nib
 * (if any) has been loaded.  Any palette initialisation should be done here.
 */
- (void) finishInstantiate;

/*
 * Return the icon representing the palette.
 */
- (NSImage*) paletteIcon;

/*
 * Return the window containing the views that may be dragged from the
 * palette.
 */
- (NSWindow*) originalWindow;
@end

/*
 * How to get the inspector for a particular object.
 */
@interface NSObject (IBInspectorClassNames)
- (NSString*) inspectorClassName;
- (NSString*) connectInspectorClassName;
- (NSString*) sizeInspectorClassName;
- (NSString*) helpInspectorClassName;
- (NSString*) classInspectorClassName;
@end

@interface IBInspector : NSObject
{
  id		object;
  NSWindow	*window;
  NSButton	*okButton;
  NSButton	*revertButton;
}
- (id) object;
- (void) ok: (id)sender;
- (NSButton*) okButton;
- (void) revert: (id)sender;
- (NSButton*) revertButton;
- (void) touch: (id)sender;
- (BOOL) wantsButtons;
- (NSWindow*) window;
@end

@interface NSView (ViewAdditions)
- (BOOL) acceptsColor: (NSColor*)color atPoint: (NSPoint)point;
- (BOOL) allowsAltDragging;
- (void) depositColor: (NSColor*)color atPoint: (NSPoint)point;
- (NSSize) maximumSizeFromKnobPosition: (IBKnobPosition)knobPosition;
- (NSSize) minimumSizeFromKnobPosition: (IBKnobPosition)position;
- (void) placeView: (NSRect)newFrame;
@end

#endif