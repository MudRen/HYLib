#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"º£Ö®½¸µº½"NOR);
	set("long",GRN @LONG
     Ò»¸ö´óÀË´òÔÚÑÒ½¸ÉÏ£¬½¦Æğ¡õÌìµÄË®»¨£¬ÄãÉÁ±Ü²»¼°±»ÁÜ¸öÕıÖø
º£·ç´µÀ´£¬Ô¶Ô¶Ì÷Íû£¬¼¸ËÒÓæ´¬ÕıËæ²¨ÔØ¸¡ÔØÉò£»»Ş°µ²»Ã÷µÄÌì¿Õ£¬ÎÚ
ÔÆÍÅ´ØºÃËÆÒ»Ö»Ö»ÕıÔÚÕÅÑÀÎè×¦µÄÒ°ÊŞ¡££
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong69",
		"east" : __DIR__"dong69",
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong69",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong69",
		"east" : __DIR__"dong69",
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong69",
	]));
         set("objects", ([
              __DIR__"npc/lev8" : 2,
              __DIR__"npc/lev6" : 2,
              __DIR__"npc/player" : 1,
              __DIR__"npc/boss1" : 1,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
