/*
  ==============================================================================

    MidiController.h
    Created: 18 Jun 2020 10:21:26am
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once

#include <AppConfig.h>
#include <JuceHeader.h>
#include <set>
#include "MidiSettings.h"

using namespace juce;

namespace rdd {

	class MidiController : public MidiInputCallback, public ChangeListener {

	public:
		MidiController(const MidiSettings& settings);

		virtual ~MidiController();


		void reconfigure(const MidiSettings& settings);

		bool addMidiInput(String midiInputIdentifier);
		bool removeMidiInput(String midiInputIdentifier);
		
		bool addMidiOuput(String midiOutputIdentifier);
		bool removeMidiOutput(String midiOutputIdentifier);
		

		// velocity must be in the range of 0 - 127
		void startCommand(MidiSettings::BotCommand cmd, uint8 velocity);
		void stopCommand(MidiSettings::BotCommand cmd);

		// value must be in the range of 0 - 127
		void sendParameter(MidiSettings::BotParameter param, uint8 value);

		void handleIncomingMidiMessage(MidiInput* source, const MidiMessage& message) override;

		void changeListenerCallback(ChangeBroadcaster* source) override;


	protected:

		MidiSettings _midiSettings;
		AudioDeviceManager _deviceManager;

		std::set<String> _midiInputIdentifiers;
		std::vector<std::unique_ptr<MidiOutput>> _midiOutputs;

	};
}
