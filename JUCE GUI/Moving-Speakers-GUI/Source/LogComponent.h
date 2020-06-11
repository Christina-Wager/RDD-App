/*
  Created with Projucer version: 5.4.7
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
                                                                    //[Comments]
    A simple log window to monitor information in the app.
	Implements Juce's Logger interface.
                                                                    //[/Comments]
*/
class LogComponent  : public Component, public Logger
{
public:
    //==============================================================================
    LogComponent ();
    ~LogComponent() override;

    //==============================================================================

    void logMessage(const String& m);

    void paint (Graphics& g) override;
    void resized() override;



private:
    //==============================================================================
    std::unique_ptr<TextEditor> textEditor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LogComponent)
};

