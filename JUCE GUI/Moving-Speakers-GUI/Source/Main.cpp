/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MainComponent.h"

//==============================================================================
class MovingSpeakersGUIApplication  : public JUCEApplication
{
public:
    //==============================================================================
    MovingSpeakersGUIApplication() {}

    const String getApplicationName() override       { return "RDD App"; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    //bool moreThanOneInstanceAllowed() override       { return true; }

    //==============================================================================
    void initialise (const String& commandLine) override { mainWindow.reset (new MainWindow ("RDD App"));}

    void shutdown() override { mainWindow = nullptr;}

    void systemRequestedQuit() override { quit();}

    //==============================================================================
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow (String name)  : DocumentWindow (name, Desktop::getInstance().getDefaultLookAndFeel()
                                                    .findColour (ResizableWindow::backgroundColourId),
                                                    DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainComponent(), true);

            setResizable (true, false);
            setResizeLimits(500, 300, 800, 600);
            centreWithSize (getWidth(), getHeight());

            setVisible (true);
        }

        void closeButtonPressed() override
        {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
START_JUCE_APPLICATION (MovingSpeakersGUIApplication)
