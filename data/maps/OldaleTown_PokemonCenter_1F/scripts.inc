.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC at the counter over there\n"
	.string "is very handy for Pokémon Trainers.\p"
	.string "You can store items, check mail, and\n"
	.string "transfer Pokémon, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "Pokémon Centers are great for us\n"
	.string "scientists.\p"
	.string "They let us take care of Pokémon\n"
	.string "and study their biology.$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "I hear Prof. Sakura is working on\n"
	.string "a new Pokédex for Rika.\p"
	.string "I wonder when they'll finish it?$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "I hear Prof. Sakura is working on\n"
	.string "a new Pokédex for Rika.\p"
	.string "Oh! You have it, there! Are you\n"
	.string "filling it out for her?\p"
	.string "If you are, good luck! Rika is a\n"
	.string "big place.$"

PokemartMain::
	lock
	faceplayer
	msgbox gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain
	release
	end

