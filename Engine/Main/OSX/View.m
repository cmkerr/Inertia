#import "View.h"

@implementation View

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
    [pool release];
}

- (void) present
{
    [m_context flushBuffer];
}

- (void)drawRect:(NSRect)dirtyRect
{
    float aspectRatio;
    
    [self makeReady];
    [m_context update];
    
    glViewport(0, 0, dirtyRect.size.width, dirtyRect.size.height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    aspectRatio = (float) dirtyRect.size.width / (float) dirtyRect.size.height;
    gluPerspective(90.0, aspectRatio, 1, 100);
}



@end
