/*
  ==============================================================================

    MidiSettings.h
    Created: 6 May 2020 9:26:49pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

namespace rdd {

	class MidiSettings {

	public:

		enum BotCommand {
			MOVE_FORWARD,
			MOVE_BACKWARD,
			STRAFE_LEFT,
			STRAFE_RIGHT,
			ROTATE_LEFT,
			ROTATE_RIGHT,
			SPEAKER_UP,
			SPEAKER_DOWN
		};

		enum BotParameter {
			MOVE_SPEED,
			ROTATE_SPEED,
			SPEAKER_SPEED
		};



		MidiSettings();

		virtual ~MidiSettings();


		bool load(const File& file);

		int getChannel() { return _channel; }

		inline int getNote(BotCommand cmd) { return _notes.find(cmd)->second; }

		inline int getCC(BotParameter param) { return _cc.find(param)->second; }

		String toString();


	protected:
		
		bool validateAndRead(var json);

		bool getIntFromJsonObject(DynamicObject* obj, const String& id, int& buffer);

		DynamicObject* getChildObjectFromJsonObject(DynamicObject* obj, const String& id);


	protected:

		int	_channel;

		std::map<BotCommand, int> _notes;

		std::map<BotParameter, int>	_cc;


	};

}