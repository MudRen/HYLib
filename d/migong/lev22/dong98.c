#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"众神之神殿"NOR);
	set("long", HIW @LONG
 这个世界，飘浮在云中,雾中,地板是由发亮的黄金所铺成，四周的墙壁
和天花板上满布著美丽的壁画和精致的石雕。空中悬浮的水晶散发著神秘
的光芒，无可描述飘荡在空中的音乐使这一切如梦如幻。
LONG NOR);
	set("exits", ([
		"up" : __DIR__"dong99",
		"down" : __DIR__"dong97",
                	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/boss11": 1,
             __DIR__"npc/boss12": 1,
              __DIR__"npc/boss13": 1,
             __DIR__"npc/boss14": 1,
              __DIR__"npc/boss15": 1,
             __DIR__"npc/boss16": 1,
             __DIR__"npc/boss17": 1,
             __DIR__"npc/boss21": 1,
             __DIR__"npc/boss22": 1,
              __DIR__"npc/boss23": 1,
             __DIR__"npc/boss24": 1,
              __DIR__"npc/boss25": 1,
             __DIR__"npc/boss26": 1,
             __DIR__"npc/boss27": 1,
                ]));
set("no_npc",1);
	set("no_fight",1);
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
