#include "MacView.h"
#include "MacWindow.h"

namespace Inertia {

MacView::MacView() : m_view(nullptr)
{
    
}

void MacView::Initialize(Window *window)
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    
    NSWindow *nativeWindow = (NSWindow *) window->GetNativeHandle();
    
    m_view = [[CocoaView alloc] initWithFrame:[nativeWindow frame]];
    
    [nativeWindow setContentView:m_view];
    [nativeWindow makeFirstResponder:m_view];
    
    [pool release];
}

void MacView::Shutdown()
{

}

void MacView::makeReady()
{
    [m_view makeReady];
}

void MacView::present()
{
    [m_view present];
}

}