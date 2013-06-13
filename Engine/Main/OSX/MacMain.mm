
#import "Engine/Main/Main.h"
#import "MacWindow.h"

int main()
{
#ifdef __APPLE__
    pthread_setname_np("Main Thread");
#endif
    
    Inertia::Window *w = new Inertia::MacWindow();
    //Main *m = new Main(w);
    Inertia::Main::s_Main = new Inertia::Main(w);
    
    w->Initialize();
    
    Inertia::Main::s_Main->Start();
    
    // This should be a call to Main::IsRunning(), but this thread
    // won't get control back after the message pump sends the terminate
    // event.
    //while (Main::s_Main->IsRunning())
    while (true)
    {
        w->HandleEvents();
    }
    
    // This is never actually hit on Mac
    w->Close();
}