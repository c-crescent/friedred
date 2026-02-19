TwoIsland_House_MapScripts::
	.byte 0

TwoIsland_House_EventScript_MoveManiac::
	lock
	faceplayer
	msgbox TwoIsland_House_Text_TeachMonMoveForMushroom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TwoIsland_House_EventScript_EndTutorMove
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_ChooseMonToTutor::
	setvar VAR_TEMP_0, 1
	msgbox TwoIsland_House_Text_TutorWhichMon
	special SelectMoveTutorMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, TwoIsland_House_EventScript_EndTutorMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_CantTutorEgg
	goto_if_eq VAR_0x8005, 0, TwoIsland_House_EventScript_NoMoveToTutorMon
	goto TwoIsland_House_EventScript_ChooseMoveToTeach
	end

TwoIsland_House_EventScript_ChooseMoveToTeach::
	msgbox TwoIsland_House_Text_TeachWhichMove
	special DisplayMoveTutorMenu
	waitstate
	goto_if_eq VAR_0x8004, 0, TwoIsland_House_EventScript_ChooseMonToTutor
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox TwoIsland_House_Text_TutorDone
	call EventScript_RestorePrevTextColor
	goto TwoIsland_House_EventScript_EndTutorMove
	end
TwoIsland_House_EventScript_NoMoveToTutorMon::
	msgbox TwoIsland_House_Text_NoMoveICanTeachThatMon
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_CantTutorEgg::
	msgbox TwoIsland_House_Text_CantTeachAnEgg
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_EndTutorMove::
	setvar VAR_TEMP_0, 0
	msgbox TwoIsland_House_Text_NeedMushroomOrTwoToLearnMove
	release
	end
TwoIsland_House_EventScript_EffortWoman::
	lock
	faceplayer
	bufferleadmonspeciesname 0
	msgbox TwoIsland_House_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	compare VAR_RESULT, TRUE
	call_if_eq TwoIsland_House_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, AreLeadMonEVsMaxedOut
	compare VAR_RESULT, FALSE
	call_if_eq TwoIsland_House_EventScript_MonEVsNotMaxed
	msgbox TwoIsland_House_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message TwoIsland_House_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox TwoIsland_House_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

TwoIsland_House_EventScript_MonEVsNotMaxed::
	msgbox TwoIsland_House_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

TwoIsland_House_EventScript_MonHasEffortRibbon::
	msgbox TwoIsland_House_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

TwoIsland_House_Text_OhYourPokemon:
	.string "Oh?\n"
	.string "Your {STR_VAR_1}…$"

TwoIsland_House_Text_PleaseGiveItThisEffortRibbon:
	.string "Went for it stupendously!\p"
	.string "As its reward, please give it this\n"
	.string "EFFORT RIBBON.$"

TwoIsland_House_Text_ReceivedEffortRibbon:
	.string "{COLOR DARK_GRAY}{PLAYER} received the EFFORT RIBBON.$"

TwoIsland_House_Text_PutEffortRibbonOnMon:
	.string "{COLOR DARK_GRAY}{PLAYER} put the EFFORT RIBBON\n"
	.string "on {STR_VAR_1}.$"

TwoIsland_House_Text_GoForItLittleHarder:
	.string "You have to go for it a\n"
	.string "little harder.\p"
	.string "If you do, I'll give your POKéMON\n"
	.string "something nice.$"

TwoIsland_House_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
	.string "RIBBON looks good on it!$"
