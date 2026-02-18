LavenderTown_House1_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_ResetEVCheck
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
	release
	end

LavenderTown_House1_EventScript_ResetEVCheck::
	msgbox LavenderTown_House1_Text_ResetEV, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavenderTown_House1_EventScript_CooltrainerFGhostGone2
	special ResetPokemonLeadPokemonEV
	msgbox LavenderTown_House1_Text_ResetEVCompleted
	closemessage
	release
	end

LavenderTown_House1_EventScript_CooltrainerFGhostGone2::
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
	release
	end
LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end
