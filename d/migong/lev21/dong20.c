
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������Թ�"NOR);
	set("long", RED @LONG
�����ǻ�����Թ�,�ƺ����������ѵĵط���Ȼ����
�ϵ�����һ�ѶѵĹǺ���Ǭ����Ѫ���������˾�������
�Ե�ʮ�ֵĹ��졣
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
                "north" : __DIR__"dong17",
		"east" : __DIR__"dong0"+(random(8)+1),
		"south" : __DIR__"dong0"+(random(7)+1),
                "west" : __DIR__"dong21",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(8)+1),
                "west" : __DIR__"dong21",
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(8)+1),
                "north" : __DIR__"dong21",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
              __DIR__"npc/lev4" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
