
#import "Engine/Main/Main.h"
#import "MacWindow.h"

int main()
{
#ifdef __APPLE__
    pthread_setname_np("Main Thread");
#endif
    
    Window *w = new MacWindow();
    //Main *m = new Main(w);
    Main::s_Main = new Main(w);
    
    w->Initialize();
    
    Main::s_Main->Start();
    
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