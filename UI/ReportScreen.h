// Copyright (c) 2014- PPSSPP Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official git repository and contact information can be found at
// https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.

#pragma once

#include <functional>

#include "ui/ui_screen.h"
#include "ui/viewgroup.h"
#include "UI/MiscScreens.h"

class ReportScreen : public UIDialogScreenWithGameBackground {
public:
	ReportScreen(const std::string &gamePath);

protected:
	void update() override;
	void CreateViews() override;
	void UpdateSubmit();

	UI::EventReturn HandleChoice(UI::EventParams &e);
	UI::EventReturn HandleSubmit(UI::EventParams &e);
	UI::EventReturn HandleBrowser(UI::EventParams &e);
	UI::EventReturn HandleReportingChange(UI::EventParams &e);

	UI::Choice *submit_;
	UI::View *screenshot_;
	UI::TextView *reportingNotice_;
	std::string screenshotFilename_;

	int overall_;
	int graphics_;
	int speed_;
	int gameplay_;
	bool enableReporting_;
	bool ratingEnabled_;
	bool includeScreenshot_;
};

class ReportFinishScreen : public UIDialogScreenWithGameBackground {
public:
	ReportFinishScreen(const std::string &gamePath);

protected:
	void update() override;
	void CreateViews() override;

	UI::EventReturn HandleViewFeedback(UI::EventParams &e);

	UI::TextView *resultNotice_;
	bool setStatus_;
};
