/*
  Created with Projucer version: 5.4.5
*/

#include "TabsComponent.h"

//==============================================================================
TabsComponent::TabsComponent ()
{
    tabbedComponent.reset (new TabbedComponent (TabbedButtonBar::TabsAtTop));
    addAndMakeVisible (tabbedComponent.get());
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (TRANS("Manual Control"), Colours::lightgrey, 0, false);
    tabbedComponent->addTab (TRANS("Waypoint Editor"), Colours::lightgrey, 0, false);
    tabbedComponent->addTab (TRANS("Settings"), Colours::lightgrey, 0, false);
    tabbedComponent->setCurrentTabIndex (0);

	Colour tabColor = getLookAndFeel().findColour(ResizableWindow::backgroundColourId);

	tabbedComponent->setTabBackgroundColour(0, tabColor);
	tabbedComponent->setTabBackgroundColour(1, tabColor);
	tabbedComponent->setTabBackgroundColour(2, tabColor);
}

TabsComponent::~TabsComponent()
{
    tabbedComponent = nullptr;
}

//==============================================================================
void TabsComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff323e44));
}

void TabsComponent::resized()
{
    tabbedComponent->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
}

//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TabsComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TABBEDCOMPONENT name="new tabbed component" id="96829c8fe1730fce" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="0 0 100% 100%" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="Manual Control" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Waypoint Editor" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Settings" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


