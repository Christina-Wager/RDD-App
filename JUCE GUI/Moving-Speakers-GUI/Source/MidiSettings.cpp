/*
  ==============================================================================

    MidiSettings.cpp
    Created: 6 May 2020 9:26:49pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#include "MidiSettings.h"

using namespace rdd;


MidiSettings::MidiSettings()
{

	_channel = 1;

	_notes[MOVE_FORWARD] = 20;
	_notes[MOVE_BACKWARD] = 21;
	_notes[STRAFE_LEFT] = 22;
	_notes[STRAFE_RIGHT] = 23;
	_notes[ROTATE_LEFT] = 24;
	_notes[ROTATE_RIGHT] = 25;
	_notes[SPEAKER_UP] = 26;
	_notes[SPEAKER_DOWN] = 27;

	_cc[MOVE_SPEED] = 30;
	_cc[ROTATE_SPEED] = 31;
	_cc[SPEAKER_SPEED] = 32;
}


MidiSettings::~MidiSettings() {

}


bool MidiSettings::load(const File& file) {

	var midisettings = JSON::parse(file);

	return validateAndRead(midisettings);
}


int MidiSettings::getChannel() {
	return _channel;
}


int MidiSettings::getNote(BotCommand cmd) {
	return _notes.find(cmd)->second;
}


int MidiSettings::getCC(BotParameter param) {
	return _cc.find(param)->second;
}


String MidiSettings::toString() {
	String s = "MidiSettings:\n";
	s += " channel:            " + String(_channel) + "\n";
	s += " note move_forward:  " + String(getNote(MOVE_FORWARD)) + "\n";
	s += " note move_backward: " + String(getNote(MOVE_BACKWARD)) + "\n";
	s += " note strafe_left:   " + String(getNote(STRAFE_LEFT)) + "\n";
	s += " note strafe_right:  " + String(getNote(STRAFE_RIGHT)) + "\n";
	s += " note rotate_left:   " + String(getNote(ROTATE_LEFT)) + "\n";
	s += " note rotate_right:  " + String(getNote(ROTATE_RIGHT)) + "\n";
	s += " note speaker_up:    " + String(getNote(SPEAKER_UP)) + "\n";
	s += " note speaker_down:  " + String(getNote(SPEAKER_DOWN)) + "\n";
	s += " cc move_speed:      " + String(getCC(MOVE_SPEED)) + "\n";
	s += " cc rotate_speed:    " + String(getCC(ROTATE_SPEED)) + "\n";
	s += " cc speaker_speed:   " + String(getCC(SPEAKER_SPEED)) + "\n";

	return s;
}



bool MidiSettings::validateAndRead(var json) {

	if (json.isObject()) {
		auto* obj = json.getDynamicObject();

		bool ret = true;

		ret &= getIntFromJsonObject(obj, "channel", _channel);


		auto* objNotes = getChildObjectFromJsonObject(obj, "notes");
		if (objNotes != nullptr) {
			ret &= getIntFromJsonObject(objNotes, "move_forward", _notes[MOVE_FORWARD]);
			ret &= getIntFromJsonObject(objNotes, "move_backward", _notes[MOVE_BACKWARD]);
			ret &= getIntFromJsonObject(objNotes, "strafe_left", _notes[STRAFE_LEFT]);
			ret &= getIntFromJsonObject(objNotes, "strafe_right", _notes[STRAFE_RIGHT]);
			ret &= getIntFromJsonObject(objNotes, "rotate_left", _notes[ROTATE_LEFT]);
			ret &= getIntFromJsonObject(objNotes, "rotate_right", _notes[ROTATE_RIGHT]);
			ret &= getIntFromJsonObject(objNotes, "speaker_up", _notes[SPEAKER_UP]);
			ret &= getIntFromJsonObject(objNotes, "speaker_down", _notes[SPEAKER_DOWN]);
		}
		else
			ret = false;

		auto* objCC = getChildObjectFromJsonObject(obj, "controlchange");
		if (objCC != nullptr) {
			ret &= getIntFromJsonObject(objCC, "move_speed", _cc[MOVE_SPEED]);
			ret &= getIntFromJsonObject(objCC, "rotate_speed", _cc[ROTATE_SPEED]);
			ret &= getIntFromJsonObject(objCC, "speaker_speed", _cc[SPEAKER_SPEED]);
		}
		else
			ret = false;


		return ret;
	}
	else
		return false;
}


bool MidiSettings::getIntFromJsonObject(DynamicObject* obj, const String& id, int& buffer) {

	if (obj->hasProperty(Identifier(id))) {
		auto prop = obj->getProperty(Identifier(id));
		if (prop.isInt()) {
			buffer = prop.operator int();
			return true;
		}
		else
			return false;
	}
	else
		return false;
}		


DynamicObject* MidiSettings::getChildObjectFromJsonObject(DynamicObject* obj, const String& id) {

	if (obj->hasProperty(Identifier(id))) {
		auto prop = obj->getProperty(Identifier(id));
		if (prop.isObject()) {
			return prop.getDynamicObject();
		}
		else
			return nullptr;
	}
	else
		return nullptr;

}
