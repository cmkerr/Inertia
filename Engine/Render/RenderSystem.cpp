#include "RenderSystem.h"

#ifdef __APPLE__
#include "Engine/Render/OSX/MacView.h"
#endif

#import <OpenGL/glu.h>

#include "Engine/Entity/ComponentManager.h"
#include "Game/Components/PositionComponent.h"

RenderSystem::RenderSystem() : m_view(nullptr)
{
    
}

void RenderSystem::Initialize(Window *window)
{
    m_view = new MacView();
    m_view->Initialize(window);

}

void RenderSystem::Shutdown()
{
    m_view->Shutdown();
}

void RenderSystem::Draw()
{
    m_view->makeReady();
    
    // Issue draw commands
    // ...
    

    ComponentManager<PositionComponent>::Instance();
    //ComponentManager<PositionComponent>::iterator it  = ComponentManager<PositionComponent>::Instance()->begin();
    //ComponentManager<PositionComponent>::iterator end = ComponentManager<PositionComponent>::Instance()->end();
    //for (; it != ComponentManager<PositionComponent>::Instance()->end(); ++it)
    //{
    //
    //}
    
    
    glMatrixMode(GL_MODELVIEW);
    
    // set the background colour
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    
    // inform the context that the view has been resized
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // prepare for primitive drawing
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 1.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslated(0.0, 0.0, -2);
    glBegin(GL_TRIANGLES);
    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glColor3d(0.0, 1.0, 0.0);
    glVertex3d(1.0, 0.0, 0.0);
    glColor3d(0.0, 0.0, 1.0);
    glVertex3d(1.0, 1.0, 0.0);
    glEnd();
    glPopMatrix();
    
    m_view->present();
}