CinnabarIsland_House_MapScripts::
	.byte 0

CinnabarIsland_House_EventScript_LittleGirl::
	msgbox CinnabarIsland_House_Text_LittleGirl, MSGBOX_NPC
	end

CinnabarIsland_House_EventScript_OldLady::
	msgbox CinnabarIsland_House_Text_OldLady, MSGBOX_NPC
	call_if_set FLAG_GOT_DOME_FOSSIL, CinnabarIsland_House_EventScript_GiveHelixFossil
	call_if_set FLAG_GOT_HELIX_FOSSIL, CinnabarIsland_House_EventScript_GiveDomeFossil
	end

CinnabarIsland_House_EventScript_GiveHelixFossil::
	checkitemspace ITEM_HELIX_FOSSIL, 1
	vgoto_if_eq VAR_RESULT, FALSE, FossilNoBagSpace
	giveitem ITEM_HELIX_FOSSIL
	release
	end
CinnabarIsland_House_EventScript_GiveDomeFossil::
	checkitemspace ITEM_DOME_FOSSIL, 1
	vgoto_if_eq VAR_RESULT, FALSE, FossilNoBagSpace
	giveitem ITEM_DOME_FOSSIL
	release
	end

FossilNoBagSpace::
	msgbox CinnabarIsland_House_EventScript_FossilNoBagSpace
	release
	end