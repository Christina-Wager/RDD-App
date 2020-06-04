/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/


#include "LogComponent.h"



//==============================================================================
LogComponent::LogComponent ()
{
    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (true);
    textEditor->setReturnKeyStartsNewLine (true);
    textEditor->setReadOnly (true);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (false);
    textEditor->setPopupMenuEnabled (false);
    textEditor->setText (String());
}

LogComponent::~LogComponent()
{
    textEditor = nullptr;
}

//==============================================================================
void LogComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff323e44));
}

void LogComponent::resized()
{
    textEditor->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
}


void LogComponent::logMessage(const String& m)
{
	textEditor->moveCaretToEnd();
	textEditor->insertTextAtCaret(m + newLine);
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="LogComponent" componentName=""
                 parentClasses="public Component, public Logger" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTEDITOR name="new text editor" id="6ebb4bdaf6eb980e" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="0 0 100% 100%" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="1"
              caret="0" popupmenu="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

