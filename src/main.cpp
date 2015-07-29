#include "ofMain.h"
#include "ofApp.h"
#include "sounddevices.h"
#include "MUI.h" 
#include "ofAppGlutWindow.h"
#if defined(TARGET_OSX)
#import <AppKit/AppKit.h>
#endif
//========================================================================
int main( ){

//	ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofAppGlutWindow window;
	cout << "LAUNCH DESKTOP" << endl;
	ofSetupOpenGL(&window, 1000,1000, OF_WINDOW);

	#if defined(TARGET_OSX)
	NSWindow * cocoaWindow = (NSWindow*)window.getCocoaWindow();
	[cocoaWindow setFrame:[[NSScreen mainScreen] visibleFrame] display:YES];
//	[cocoaWindow setLevel:10];
	#endif

	mui_init();
	mui::MuiConfig::font = "mui/fonts/Lato-Regular.ttf";
	ofRunApp(new ofApp);
	
}

#ifdef _WIN32
INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow)
{
    return main();
}
#endif
