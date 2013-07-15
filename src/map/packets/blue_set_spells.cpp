/*
===========================================================================

  Copyright (c) 2010-2012 Darkstar Dev Teams

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/

  This file is part of DarkStar-server source code.

===========================================================================
*/

#include "../../common/socket.h"

#include <string.h>

#include "blue_set_spells.h"

#include "../charentity.h"

CBlueSetSpellsPacket::CBlueSetSpellsPacket(CCharEntity* PChar)
{
	this->type = 0x44;
	this->size = 0x4E;

	WBUFB(data,(0x04)-4) = JOB_BLU;
    if (PChar->GetSJob() == JOB_BLU)
    {
        WBUFB(data,(0x05)-4) = 0x01;
    }

	memcpy(data+(0x08)-4, &PChar->m_SetBlueSpells, 20);

}
