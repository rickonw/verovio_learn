/*
 * MidiEditor
 * Copyright (C) 2010  Markus Schwenk
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EVENTTOOL_H_
#define EVENTTOOL_H_

#include "EditorTool.h"

#include <QList>
class MidiEvent;

class EventTool: public EditorTool {

	public:
		EventTool();
		EventTool(EventTool &other);
		static void selectEvent(MidiEvent *event, bool single, bool ignoreStr=false);
		static void deselectEvent(MidiEvent *event);
		static void clearSelection();
		void paintSelectedEvents(QPainter *painter);
		static QList<MidiEvent*> *selectedEventList();
		void changeTick(MidiEvent* event, int shiftX);
		ProtocolEntry *copy();
		void reloadState(ProtocolEntry *entry);

		virtual bool pressKey(int key);
		static bool shiftPressed, strPressed, altPressed, spacePressed, altGrPressed;
		static void copyAction();
		static void pasteAction();

	protected:
		static QList<MidiEvent*> *selectedEvents, *copiedEvents;
		QList<MidiEvent*> *ownSelectedEvents;
		static bool isCutAction;
};

#endif
