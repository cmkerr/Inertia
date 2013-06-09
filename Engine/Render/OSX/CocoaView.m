#import "CocoaView.h"

@implementation CocoaView

#include <OpenGL/glu.h>

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        NSOpenGLPixelFormatAttribute attrs[] = {
            NSOpenGLPFADoubleBuffer,
            NSOpenGLPFADepthSize, 32,
            0
        };
        m_format = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
        
        // create and activate the context object which maintains the OpenGL state
        m_context = [[NSOpenGLContext alloc] initWithFormat: m_format shareContext: nil];
        
        needsResize = false;
        
    }
    
    return self;
}

- (void) dealloc
{
    [m_format release];
    [m_context release];
    
    [super dealloc];
}

- (void) makeReady
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    
    [m_context clearDrawable];
    [m_context setView:self];
    [m_context makeCurrentContext];
    
    if (needsResize) [self resize];
    
    [pool release];
}

- (void) present
{
    [m_context flushBuffer];
}

- (void) resize
{
    float aspectRatio;
    
    [m_context update];
    
    glViewport(0, 0, resizeFrame.size.width, resizeFrame.size.height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    aspectRatio = (float) resizeFrame.size.width / (float) resizeFrame.size.height;
    gluPerspective(90.0, aspectRatio, 1, 100);
    
    needsResize = false;
}

- (void)drawRect:(NSRect)dirtyRect
{
    // Need to synchronize threads, so just mark as needing resize
    resizeFrame = dirtyRect;
    needsResize = true;
}



@end
