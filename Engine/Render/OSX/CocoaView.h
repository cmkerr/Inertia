#import <Cocoa/Cocoa.h>

#import <OpenGL/gl.h>

@interface CocoaView : NSView{
    NSOpenGLContext *m_context;
    NSOpenGLPixelFormat *m_format;
}
- (id)initWithFrame:(NSRect)frame;
- (void) dealloc;

- (void) makeReady;
- (void) present;
@end
