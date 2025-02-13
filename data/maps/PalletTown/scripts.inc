# 1 "data/maps/PalletTown/scripts.pory"

# 2 "data/maps/PalletTown/scripts.pory"
.equ LOCALID_PROF_OAK,  3
# 3 "data/maps/PalletTown/scripts.pory"

# 4 "data/maps/PalletTown/scripts.pory"
PalletTown_MapScripts::
# 5 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
# 6 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
# 7 "data/maps/PalletTown/scripts.pory"
	.byte 0
# 8 "data/maps/PalletTown/scripts.pory"

# 9 "data/maps/PalletTown/scripts.pory"
PalletTown_OnTransition::
# 10 "data/maps/PalletTown/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
# 11 "data/maps/PalletTown/scripts.pory"
	end
# 12 "data/maps/PalletTown/scripts.pory"

# 13 "data/maps/PalletTown/scripts.pory"

# 14 "data/maps/PalletTown/scripts.pory"
PalletTown_OnFrame::
# 15 "data/maps/PalletTown/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
# 16 "data/maps/PalletTown/scripts.pory"
	.2byte 0
# 17 "data/maps/PalletTown/scripts.pory"

# 18 "data/maps/PalletTown/scripts.pory"
@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
# 19 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakRatingScene::
# 20 "data/maps/PalletTown/scripts.pory"
	lockall
# 21 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 22 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 14, 14
# 23 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
# 24 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 25 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
# 26 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 27 "data/maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
# 28 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakLetMeSeePokedex
# 29 "data/maps/PalletTown/scripts.pory"
	setvar VAR_0x8004, 0
# 30 "data/maps/PalletTown/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 31 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 32 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 33 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 34 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 35 "data/maps/PalletTown/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
# 36 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
# 37 "data/maps/PalletTown/scripts.pory"
	closemessage
# 38 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 39 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
# 40 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
# 41 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 42 "data/maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 43 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 44 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 45 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 46 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 47 "data/maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 48 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 49 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
# 50 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 51 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 52 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 53 "data/maps/PalletTown/scripts.pory"
	waitstate
# 54 "data/maps/PalletTown/scripts.pory"
	releaseall
# 55 "data/maps/PalletTown/scripts.pory"
	end
# 56 "data/maps/PalletTown/scripts.pory"

# 57 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_EndOakRatingScene::
# 58 "data/maps/PalletTown/scripts.pory"
	closemessage
# 59 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakExit
# 60 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 61 "data/maps/PalletTown/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 62 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 63 "data/maps/PalletTown/scripts.pory"
	releaseall
# 64 "data/maps/PalletTown/scripts.pory"
	end
# 65 "data/maps/PalletTown/scripts.pory"

# 66 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotEnoughMonsForNationalDex::
# 67 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
# 68 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 69 "data/maps/PalletTown/scripts.pory"
	end
# 70 "data/maps/PalletTown/scripts.pory"

# 71 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotBeenToOneIslandYet::
# 72 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
# 73 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 74 "data/maps/PalletTown/scripts.pory"
	end
# 75 "data/maps/PalletTown/scripts.pory"

# 76 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToPlayersDoor::
# 77 "data/maps/PalletTown/scripts.pory"
	walk_left
# 78 "data/maps/PalletTown/scripts.pory"
	walk_left
# 79 "data/maps/PalletTown/scripts.pory"
	walk_left
# 80 "data/maps/PalletTown/scripts.pory"
	walk_up
# 81 "data/maps/PalletTown/scripts.pory"
	walk_up
# 82 "data/maps/PalletTown/scripts.pory"
	walk_up
# 83 "data/maps/PalletTown/scripts.pory"
	walk_up
# 84 "data/maps/PalletTown/scripts.pory"
	walk_up
# 85 "data/maps/PalletTown/scripts.pory"
	walk_left
# 86 "data/maps/PalletTown/scripts.pory"
	walk_left
# 87 "data/maps/PalletTown/scripts.pory"
	walk_left
# 88 "data/maps/PalletTown/scripts.pory"
	walk_left
# 89 "data/maps/PalletTown/scripts.pory"
	walk_left
# 90 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 91 "data/maps/PalletTown/scripts.pory"
	step_end
# 92 "data/maps/PalletTown/scripts.pory"

# 93 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakExit::
# 94 "data/maps/PalletTown/scripts.pory"
	walk_right
# 95 "data/maps/PalletTown/scripts.pory"
	walk_right
# 96 "data/maps/PalletTown/scripts.pory"
	walk_right
# 97 "data/maps/PalletTown/scripts.pory"
	walk_right
# 98 "data/maps/PalletTown/scripts.pory"
	walk_right
# 99 "data/maps/PalletTown/scripts.pory"
	walk_down
# 100 "data/maps/PalletTown/scripts.pory"
	walk_down
# 101 "data/maps/PalletTown/scripts.pory"
	walk_down
# 102 "data/maps/PalletTown/scripts.pory"
	walk_down
# 103 "data/maps/PalletTown/scripts.pory"
	walk_down
# 104 "data/maps/PalletTown/scripts.pory"
	walk_right
# 105 "data/maps/PalletTown/scripts.pory"
	walk_right
# 106 "data/maps/PalletTown/scripts.pory"
	walk_right
# 107 "data/maps/PalletTown/scripts.pory"
	step_end
# 108 "data/maps/PalletTown/scripts.pory"

# 109 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabFromHouse::
# 110 "data/maps/PalletTown/scripts.pory"
	walk_right
# 111 "data/maps/PalletTown/scripts.pory"
	walk_right
# 112 "data/maps/PalletTown/scripts.pory"
	walk_right
# 113 "data/maps/PalletTown/scripts.pory"
	walk_right
# 114 "data/maps/PalletTown/scripts.pory"
	walk_right
# 115 "data/maps/PalletTown/scripts.pory"
	walk_down
# 116 "data/maps/PalletTown/scripts.pory"
	walk_down
# 117 "data/maps/PalletTown/scripts.pory"
	walk_down
# 118 "data/maps/PalletTown/scripts.pory"
	walk_down
# 119 "data/maps/PalletTown/scripts.pory"
	walk_down
# 120 "data/maps/PalletTown/scripts.pory"
	walk_right
# 121 "data/maps/PalletTown/scripts.pory"
	walk_right
# 122 "data/maps/PalletTown/scripts.pory"
	walk_right
# 123 "data/maps/PalletTown/scripts.pory"
	walk_right
# 124 "data/maps/PalletTown/scripts.pory"
	walk_right
# 125 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 126 "data/maps/PalletTown/scripts.pory"
	step_end
# 127 "data/maps/PalletTown/scripts.pory"

# 128 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabFromHouse::
# 129 "data/maps/PalletTown/scripts.pory"
	walk_down
# 130 "data/maps/PalletTown/scripts.pory"
	walk_right
# 131 "data/maps/PalletTown/scripts.pory"
	walk_right
# 132 "data/maps/PalletTown/scripts.pory"
	walk_right
# 133 "data/maps/PalletTown/scripts.pory"
	walk_right
# 134 "data/maps/PalletTown/scripts.pory"
	walk_right
# 135 "data/maps/PalletTown/scripts.pory"
	walk_down
# 136 "data/maps/PalletTown/scripts.pory"
	walk_down
# 137 "data/maps/PalletTown/scripts.pory"
	walk_down
# 138 "data/maps/PalletTown/scripts.pory"
	walk_down
# 139 "data/maps/PalletTown/scripts.pory"
	walk_down
# 140 "data/maps/PalletTown/scripts.pory"
	walk_right
# 141 "data/maps/PalletTown/scripts.pory"
	walk_right
# 142 "data/maps/PalletTown/scripts.pory"
	walk_right
# 143 "data/maps/PalletTown/scripts.pory"
	walk_right
# 144 "data/maps/PalletTown/scripts.pory"
	step_end
# 145 "data/maps/PalletTown/scripts.pory"

# 146 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerLeft::
# 147 "data/maps/PalletTown/scripts.pory"
	lockall
# 148 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 0
# 149 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 150 "data/maps/PalletTown/scripts.pory"
	end
# 151 "data/maps/PalletTown/scripts.pory"

# 152 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerRight::
# 153 "data/maps/PalletTown/scripts.pory"
	lockall
# 154 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 1
# 155 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 156 "data/maps/PalletTown/scripts.pory"
	end
# 157 "data/maps/PalletTown/scripts.pory"

# 158 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTrigger::
# 159 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 160 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 161 "data/maps/PalletTown/scripts.pory"
	delay 30
# 162 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_OAK, 0
# 163 "data/maps/PalletTown/scripts.pory"
	message PalletTown_Text_OakDontGoOut
# 164 "data/maps/PalletTown/scripts.pory"
	waitmessage
# 165 "data/maps/PalletTown/scripts.pory"
	delay 85
# 166 "data/maps/PalletTown/scripts.pory"
	closemessage
# 167 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 168 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 169 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 170 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 171 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 172 "data/maps/PalletTown/scripts.pory"
	delay 30
# 173 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 174 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
# 175 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
# 176 "data/maps/PalletTown/scripts.pory"
	delay 30
# 177 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
# 178 "data/maps/PalletTown/scripts.pory"
	closemessage
# 179 "data/maps/PalletTown/scripts.pory"
	delay 30
# 180 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
# 181 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
# 182 "data/maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 183 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 184 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 185 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 186 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 187 "data/maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 188 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 189 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 190 "data/maps/PalletTown/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 191 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 192 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 193 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 194 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 195 "data/maps/PalletTown/scripts.pory"
	waitstate
# 196 "data/maps/PalletTown/scripts.pory"
	releaseall
# 197 "data/maps/PalletTown/scripts.pory"
	end
# 198 "data/maps/PalletTown/scripts.pory"

# 199 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterLeft::
# 200 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLeft
# 201 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 202 "data/maps/PalletTown/scripts.pory"
	return
# 203 "data/maps/PalletTown/scripts.pory"

# 204 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterRight::
# 205 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterRight
# 206 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 207 "data/maps/PalletTown/scripts.pory"
	return
# 208 "data/maps/PalletTown/scripts.pory"

# 209 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabLeft::
# 210 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
# 211 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
# 212 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 213 "data/maps/PalletTown/scripts.pory"
	return
# 214 "data/maps/PalletTown/scripts.pory"

# 215 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabRight::
# 216 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
# 217 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
# 218 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 219 "data/maps/PalletTown/scripts.pory"
	return
# 220 "data/maps/PalletTown/scripts.pory"

# 221 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLeft::
# 222 "data/maps/PalletTown/scripts.pory"
	walk_up
# 223 "data/maps/PalletTown/scripts.pory"
	walk_up
# 224 "data/maps/PalletTown/scripts.pory"
	walk_right
# 225 "data/maps/PalletTown/scripts.pory"
	walk_up
# 226 "data/maps/PalletTown/scripts.pory"
	walk_up
# 227 "data/maps/PalletTown/scripts.pory"
	walk_right
# 228 "data/maps/PalletTown/scripts.pory"
	walk_up
# 229 "data/maps/PalletTown/scripts.pory"
	walk_up
# 230 "data/maps/PalletTown/scripts.pory"
	step_end
# 231 "data/maps/PalletTown/scripts.pory"

# 232 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterRight::
# 233 "data/maps/PalletTown/scripts.pory"
	walk_right
# 234 "data/maps/PalletTown/scripts.pory"
	walk_up
# 235 "data/maps/PalletTown/scripts.pory"
	walk_up
# 236 "data/maps/PalletTown/scripts.pory"
	walk_right
# 237 "data/maps/PalletTown/scripts.pory"
	walk_up
# 238 "data/maps/PalletTown/scripts.pory"
	walk_up
# 239 "data/maps/PalletTown/scripts.pory"
	walk_right
# 240 "data/maps/PalletTown/scripts.pory"
	walk_up
# 241 "data/maps/PalletTown/scripts.pory"
	walk_up
# 242 "data/maps/PalletTown/scripts.pory"
	step_end
# 243 "data/maps/PalletTown/scripts.pory"

# 244 "data/maps/PalletTown/scripts.pory"
	.macro walk_to_lab
# 245 "data/maps/PalletTown/scripts.pory"
	walk_left
# 246 "data/maps/PalletTown/scripts.pory"
	walk_down
# 247 "data/maps/PalletTown/scripts.pory"
	walk_down
# 248 "data/maps/PalletTown/scripts.pory"
	walk_down
# 249 "data/maps/PalletTown/scripts.pory"
	walk_down
# 250 "data/maps/PalletTown/scripts.pory"
	walk_down
# 251 "data/maps/PalletTown/scripts.pory"
	walk_down
# 252 "data/maps/PalletTown/scripts.pory"
	walk_down
# 253 "data/maps/PalletTown/scripts.pory"
	walk_down
# 254 "data/maps/PalletTown/scripts.pory"
	walk_down
# 255 "data/maps/PalletTown/scripts.pory"
	walk_down
# 256 "data/maps/PalletTown/scripts.pory"
	walk_down
# 257 "data/maps/PalletTown/scripts.pory"
	walk_right
# 258 "data/maps/PalletTown/scripts.pory"
	walk_right
# 259 "data/maps/PalletTown/scripts.pory"
	walk_right
# 260 "data/maps/PalletTown/scripts.pory"
	walk_right
# 261 "data/maps/PalletTown/scripts.pory"
	.endm
# 262 "data/maps/PalletTown/scripts.pory"

# 263 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabLeft::
# 264 "data/maps/PalletTown/scripts.pory"
	walk_down
# 265 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 266 "data/maps/PalletTown/scripts.pory"
	walk_right
# 267 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 268 "data/maps/PalletTown/scripts.pory"
	step_end
# 269 "data/maps/PalletTown/scripts.pory"

# 270 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabRight::
# 271 "data/maps/PalletTown/scripts.pory"
	walk_down
# 272 "data/maps/PalletTown/scripts.pory"
	walk_left
# 273 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 274 "data/maps/PalletTown/scripts.pory"
	walk_right
# 275 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 276 "data/maps/PalletTown/scripts.pory"
	step_end
# 277 "data/maps/PalletTown/scripts.pory"

# 278 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLab::
# 279 "data/maps/PalletTown/scripts.pory"
	walk_up
# 280 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 281 "data/maps/PalletTown/scripts.pory"
	step_end
# 282 "data/maps/PalletTown/scripts.pory"

# 283 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabLeft::
# 284 "data/maps/PalletTown/scripts.pory"
	walk_down
# 285 "data/maps/PalletTown/scripts.pory"
	walk_down
# 286 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 287 "data/maps/PalletTown/scripts.pory"
	step_end
# 288 "data/maps/PalletTown/scripts.pory"

# 289 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabRight::
# 290 "data/maps/PalletTown/scripts.pory"
	walk_down
# 291 "data/maps/PalletTown/scripts.pory"
	walk_down
# 292 "data/maps/PalletTown/scripts.pory"
	walk_left
# 293 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 294 "data/maps/PalletTown/scripts.pory"
	step_end
# 295 "data/maps/PalletTown/scripts.pory"

# 296 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerEnterLab::
# 297 "data/maps/PalletTown/scripts.pory"
	walk_right
# 298 "data/maps/PalletTown/scripts.pory"
	walk_up
# 299 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 300 "data/maps/PalletTown/scripts.pory"
	step_end
# 301 "data/maps/PalletTown/scripts.pory"

# 302 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FatMan::
# 303 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
# 304 "data/maps/PalletTown/scripts.pory"
	end
# 305 "data/maps/PalletTown/scripts.pory"

# 306 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OaksLabSign::
# 307 "data/maps/PalletTown/scripts.pory"
	lockall
# 308 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, 0
# 309 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakPokemonResearchLab
# 310 "data/maps/PalletTown/scripts.pory"
	releaseall
# 311 "data/maps/PalletTown/scripts.pory"
	end
# 312 "data/maps/PalletTown/scripts.pory"

# 313 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_PlayersHouseSign::
# 314 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
# 315 "data/maps/PalletTown/scripts.pory"
	end
# 316 "data/maps/PalletTown/scripts.pory"

# 317 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_RivalsHouseSign::
# 318 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
# 319 "data/maps/PalletTown/scripts.pory"
	end
# 320 "data/maps/PalletTown/scripts.pory"

# 321 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TownSign::
# 322 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
# 323 "data/maps/PalletTown/scripts.pory"
	end
# 324 "data/maps/PalletTown/scripts.pory"

# 325 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyTrigger::
# 326 "data/maps/PalletTown/scripts.pory"
	end

PalletTown_FlowerGirl::
# 331 "data/maps/PalletTown/scripts.pory"
	lock
# 332 "data/maps/PalletTown/scripts.pory"
	faceplayer
# 333 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_FlowerGirl_Text_0
# 334 "data/maps/PalletTown/scripts.pory"
	release
	return


PalletTown_FlowerGirl_Text_0:
# 333 "data/maps/PalletTown/scripts.pory"
	.string "I've told you this a million times,\n"
	.string "{PLAYER}, watch where you're\l"
	.string "stepping! If you trample even one of my\l"
	.string "flowers, I'll be letting your mother\l"
	.string "know!$"
