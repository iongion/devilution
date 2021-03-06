/*
 * UNPUBLISHED -- Rights  reserved  under  the  copyright  laws  of the
 * United States.  Use  of a copyright notice is precautionary only and
 * does not imply publication or disclosure.
 *
 * THIS DOCUMENTATION CONTAINS CONFIDENTIAL AND PROPRIETARY INFORMATION
 * OF    BLIZZARD   ENTERTAINMENT.    ANY   DUPLICATION,  MODIFICATION,
 * DISTRIBUTION, OR DISCLOSURE IS STRICTLY PROHIBITED WITHOUT THE PRIOR
 * EXPRESS WRITTEN PERMISSION OF BLIZZARD ENTERTAINMENT.
 */

#include "../types.h"

bool sgbIsScrolling; // weak
int track_cpp_init_value; // weak
int sgdwLastWalk; // weak
bool sgbIsWalking; // weak

int track_inf = 0x7F800000; // weak

//----- (004618AA) --------------------------------------------------------
struct track_cpp_init
{
	track_cpp_init()
	{
		track_cpp_init_value = track_inf;
	}
} _track_cpp_init;
// 4802D0: using guessed type int track_inf;
// 6ABABC: using guessed type int track_cpp_init_value;

//----- (004618B5) --------------------------------------------------------
void __cdecl track_process()
{
	int v0; // eax
	DWORD v1; // eax

	if ( sgbIsWalking )
	{
		if ( cursmx >= 0 && cursmx < 111 && cursmy >= 0 && cursmy < 111 )
		{
			v0 = myplr;
			if ( (plr[myplr]._pVar8 > 6 || plr[v0]._pmode == PM_STAND)
			  && (cursmx != plr[v0]._ptargx || cursmy != plr[v0]._ptargy) )
			{
				v1 = GetTickCount();
				if ( v1 - sgdwLastWalk >= 300 )
				{
					sgdwLastWalk = v1;
					NetSendCmdLoc(1u, CMD_WALKXY, cursmx, cursmy);
					if ( !sgbIsScrolling )
						sgbIsScrolling = 1;
				}
			}
		}
	}
}
// 6ABAB8: using guessed type char sgbIsScrolling;
// 6ABAC0: using guessed type int sgdwLastWalk;
// 6ABAC4: using guessed type int sgbIsWalking;

//----- (00461953) --------------------------------------------------------
void __fastcall track_repeat_walk(bool rep)
{
	if ( sgbIsWalking != rep )
	{
		sgbIsWalking = rep;
		if ( rep )
		{
			sgbIsScrolling = 0;
			sgdwLastWalk = GetTickCount() - 50;
			NetSendCmdLoc(1u, CMD_WALKXY, cursmx, cursmy);
		}
		else if ( sgbIsScrolling )
		{
			sgbIsScrolling = 0;
		}
	}
}
// 6ABAB8: using guessed type char sgbIsScrolling;
// 6ABAC0: using guessed type int sgdwLastWalk;
// 6ABAC4: using guessed type int sgbIsWalking;

//----- (0046199F) --------------------------------------------------------
bool __cdecl track_isscrolling()
{
	return sgbIsScrolling;
}
// 6ABAB8: using guessed type char sgbIsScrolling;
