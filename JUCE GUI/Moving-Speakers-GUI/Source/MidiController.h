/*
  ==============================================================================

    MidiController.h
    Created: 18 Jun 2020 10:21:26am
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MidiSettings.h"

using namespace juce;

namespace rdd {

	class MidiController {


		MidiController(MidiSettings& settings);

		virtual ~MidiController();


		void reconfigure(MidiSettings& settings);



	};
}
