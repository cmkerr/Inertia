
#import "Engine/Main/Main.h"
#import "MacWindow.h"

int main()
{
#ifdef __APPLE__
    pthread_setname_np("Main Thread");
#endif
    
    
    Window *w = new MacWindow();
    Main *m = new Main(w);
    
    w->Initialize();
    w->Show();
    
    m->Start();
    
    while (true)
    {
        w->HandleEvents();
        
        w->Draw();
    }
    
    w->Close();
}