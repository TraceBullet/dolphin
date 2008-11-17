// Copyright (C) 2003-2008 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/


#include "Common.h"
#include "IniFile.h"
#include "Config.h"

Config g_Config;

Config::Config()
{
    memset(this, 0, sizeof(Config));
}

void Config::Load()
{
    std::string temp;
    IniFile iniFile;
    iniFile.Load(FULL_CONFIG_DIR "Wiimote.ini");

	// get resolution

    iniFile.Get("Settings", "SidewaysDPad", &bSidewaysDPad, 0); // Hardware
	iniFile.Get("Settings", "WideScreen", &bWideScreen, 0);
	iniFile.Get("Settings", "ExtensionConnected", &bExtensionConnected, 0);
	
}

void Config::Save()
{
    IniFile iniFile;
    iniFile.Load(FULL_CONFIG_DIR "Wiimote.ini");
    iniFile.Set("Settings", "SidewaysDPad", bSidewaysDPad);
    iniFile.Set("Settings", "WideScreen", bWideScreen);
	iniFile.Set("Settings", "ExtensionConnected", bExtensionConnected);


    iniFile.Save(FULL_CONFIG_DIR "Wiimote.ini");
}
