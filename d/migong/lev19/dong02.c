
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"����֮ɭ"NOR);
	set("long", RED @LONG
    ������һ�����ϵ�ԭʼɭ�֣������������ľ���������ǹ��϶�
��ɣ���ݷ������������µ�ĥ��������������ɭ�ֲ����ϣ�������ݺ
�������в����ܷҶྫ��޹�ա��������������Ϣһ��(save)��
��˯��(sleep)��
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+1),
                "west" : __DIR__"dong03",
	]));
 set("valid_startroom", "1");
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(3)+3),
                "north" : __DIR__"dong0"+(random(4)+1),
		"east" : __DIR__"dong0"+(random(4)+3),
                "west" : __DIR__"dong03",
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
