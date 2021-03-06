/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef STARK_UI_MENU_MAIN_MENU_H
#define STARK_UI_MENU_MAIN_MENU_H

#include "engines/stark/ui/menu/locationscreen.h"
#include "engines/stark/services/services.h"
#include "engines/advancedDetector.h"

namespace Stark {

/**
 * The main menu of the game when it is opened
 */
class MainMenuScreen : public StaticLocationScreen {
public:
	MainMenuScreen(Gfx::Driver *gfx, Cursor *cursor);
	virtual ~MainMenuScreen();

	// StaticLocationScreen API
	void open() override;

private:
	template<uint N>
	void helpTextHandler(StaticLocationWidget &widget, const Common::Point &mousePos);

	void newGameHandler();
	void loadHandler();
	void creditsHandler();
	void quitHandler();

	bool isDemo() {
		return StarkGameDescription->flags & ADGF_DEMO;
	}
};

} // End of namespace Stark

#endif // STARK_UI_MENU_MAIN_MENU_H
