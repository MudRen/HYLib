
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮�þ�"NOR);
	set("long", RED @LONG
ΰ������������ҫ�����ɭ���У�����ɭ����ҫ��
һƬ���ɫ�Ĺ���С��ڸߴ����ָ��������������밫
��ľ,  �㷢�����Ѿ���·�ˡ� �������������Ϣһ��(save)��
��˯��(sleep)��
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
set("sleep_room",1);
	set("exits", ([
		"eastsouth" : __DIR__"dong0"+(random(4)+1),
                "westnorth" : __DIR__"dong03",
	]));
 set("valid_startroom", "1");
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(3)+3),
                "north" : __DIR__"dong0"+(random(4)+1),
		"west" : __DIR__"dong0"+(random(4)+1),
                "east" : __DIR__"dong03",
	]));

         set("objects", ([
"/d/migong/lev16/npc/obj/food2" : 1,
"/d/migong/lev16/npc/obj/water1" : 1,
              __DIR__"npc/player" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
