#import <Cocoa/Cocoa.h>

@interface MenuBuilder : NSObject {}

+(void) populateMainMenu;

+(void) populateApplicationMenu:(NSMenu *)menu;
+(void) populateDebugMenu:(NSMenu *)menu;
+(void) populateEditMenu:(NSMenu *)menu;
+(void) populateFileMenu:(NSMenu *)menu;
+(void) populateFindMenu:(NSMenu *)menu;
+(void) populateHelpMenu:(NSMenu *)menu;
+(void) populateSpellingMenu:(NSMenu *)menu;
+(void) populateViewMenu:(NSMenu *)menu;
+(void) populateWindowMenu:(NSMenu *)menu;

@end
