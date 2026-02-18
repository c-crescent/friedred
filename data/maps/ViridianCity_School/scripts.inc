.set LOCALID_WOMAN, 1
.set LOCALID_LASS,  2
.set LOCALID_BELLSPROUT_MASTER, 3
.set TRAINER, VAR_0x8009

ViridianCity_School_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_School_MapScript_SetMasterTrainerMovementTypes
	.byte 0

ViridianCity_School_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_BELLSPROUT
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, ViridianCity_School_MapScript_BellsproutMasterMovementType
	end

ViridianCity_School_MapScript_BellsproutMasterMovementType::
	setobjectmovementtype LOCALID_BELLSPROUT_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

ViridianCity_School_EventScript_Lass::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes
	closemessage
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, ViridianCity_School_EventScript_WomanNoPokedex
	msgbox ViridianCity_School_Text_NatureChange, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_WomanNoPokedex
	releaseall
	multichoicegrid 0, 1, MULTICHOICE_TRAINER_SCHOOL_NATURE_CHANGE, 5, TRUE
	switch VAR_RESULT
	case 0, ViridianCity_School_Hardy
	case 1, ViridianCity_School_Lonely
	case 2, ViridianCity_School_Brave
	case 3, ViridianCity_School_Adamant
	case 4, ViridianCity_School_Naughty
	case 5, ViridianCity_School_Bold
	case 6, ViridianCity_School_Docile
	case 7, ViridianCity_School_Relaxed
	case 8, ViridianCity_School_Impish
	case 9, ViridianCity_School_Lax
	case 10, ViridianCity_School_Timid
	case 11, ViridianCity_School_Hasty
	case 12, ViridianCity_School_Serious
	case 13, ViridianCity_School_Jolly
	case 14, ViridianCity_School_Naive
	case 15, ViridianCity_School_Modest
	case 16, ViridianCity_School_Mild
	case 17, ViridianCity_School_Quiet
	case 18, ViridianCity_School_Bashful
	case 19, ViridianCity_School_Rash
	case 20, ViridianCity_School_Calm
	case 21, ViridianCity_School_Gentle
	case 22, ViridianCity_School_Sassy
	case 23, ViridianCity_School_Careful
	case 24, ViridianCity_School_Quirky
	end

ViridianCity_School_Hardy::
	setvar VAR_0x8014, 0
	special ChangePokemonPersonality
	end

ViridianCity_School_Lonely::
	setvar VAR_0x8014, 1
	special ChangePokemonPersonality
	end

ViridianCity_School_Brave::
	setvar VAR_0x8014, 2
	special ChangePokemonPersonality
	end

ViridianCity_School_Adamant::
	setvar VAR_0x8014, 3
	special ChangePokemonPersonality
	end

ViridianCity_School_Naughty::
	setvar VAR_0x8014, 4
	special ChangePokemonPersonality
	end

ViridianCity_School_Bold::
	setvar VAR_0x8014, 5
	special ChangePokemonPersonality
	end

ViridianCity_School_Docile::
	setvar VAR_0x8014, 6
	special ChangePokemonPersonality
	end

ViridianCity_School_Relaxed::
	setvar VAR_0x8014, 7
	special ChangePokemonPersonality
	end

ViridianCity_School_Impish::
	setvar VAR_0x8014, 8
	special ChangePokemonPersonality
	end

ViridianCity_School_Lax::
	setvar VAR_0x8014, 9
	special ChangePokemonPersonality
	end

ViridianCity_School_Timid::
	setvar VAR_0x8014, 10
	special ChangePokemonPersonality
	end

ViridianCity_School_Hasty::
	setvar VAR_0x8014, 11
	special ChangePokemonPersonality
	end

ViridianCity_School_Serious::
	setvar VAR_0x8014, 12
	special ChangePokemonPersonality
	end

ViridianCity_School_Jolly::
	setvar VAR_0x8014, 13
	special ChangePokemonPersonality
	end

ViridianCity_School_Naive::
	setvar VAR_0x8014, 14
	special ChangePokemonPersonality
	end

ViridianCity_School_Modest::
	setvar VAR_0x8014, 15
	special ChangePokemonPersonality
	end

ViridianCity_School_Mild::
	setvar VAR_0x8014, 16
	special ChangePokemonPersonality
	end

ViridianCity_School_Quiet::
	setvar VAR_0x8014, 17
	special ChangePokemonPersonality
	end

ViridianCity_School_Bashful::
	setvar VAR_0x8014, 18
	special ChangePokemonPersonality
	end

ViridianCity_School_Rash::
	setvar VAR_0x8014, 19
	special ChangePokemonPersonality
	end

ViridianCity_School_Calm::
	setvar VAR_0x8014, 20
	special ChangePokemonPersonality
	end

ViridianCity_School_Gentle::
	setvar VAR_0x8014, 21
	special ChangePokemonPersonality
	end

ViridianCity_School_Sassy::
	setvar VAR_0x8014, 22
	special ChangePokemonPersonality
	end

ViridianCity_School_Careful::
	setvar VAR_0x8014, 23
	special ChangePokemonPersonality
	end

ViridianCity_School_Quirky::
	setvar VAR_0x8014, 24
	special ChangePokemonPersonality
	end

ViridianCity_School_EventScript_WomanNoPokedex::
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Notebook::
	lockall
	msgbox ViridianCity_School_Text_NotebookFirstPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookSecondPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookThirdPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookFourthPage
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes
	releaseall
	end

ViridianCity_School_EventScript_StopReadingNotebook::
	releaseall
	end

ViridianCity_School_EventScript_Blackboard::
	lockall
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ChooseBlackboardTopic::
	message ViridianCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 7, 1, MULTICHOICE_TRAINER_SCHOOL_WHITEBOARD, 3, FALSE
	switch VAR_RESULT
	case 0, ViridianCity_School_EventScript_ReadSleep
	case 1, ViridianCity_School_EventScript_ReadPoison
	case 2, ViridianCity_School_EventScript_ReadParalysis
	case 3, ViridianCity_School_EventScript_ReadBurn
	case 4, ViridianCity_School_EventScript_ReadFreeze
	case 5, ViridianCity_School_EventScript_ExitBlackboard
	case 127, ViridianCity_School_EventScript_ExitBlackboard
	end

ViridianCity_School_EventScript_ReadSleep::
	msgbox ViridianCity_School_Text_ExplainSleep
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadBurn::
	msgbox ViridianCity_School_Text_ExplainBurn
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadPoison::
	msgbox ViridianCity_School_Text_ExplainPoison
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadFreeze::
	msgbox ViridianCity_School_Text_ExplainFreeze
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadParalysis::
	msgbox ViridianCity_School_Text_ExplainParalysis
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ExitBlackboard::
	releaseall
	end
