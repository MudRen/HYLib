
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"��ʹ֮��"NOR);
	set("long", HIW @LONG
��ʥ����������������޴����ڣ��º͵�̫��������
�����ɼ��������ϣ�ʹ������������������ҫ�Ĺ�ԡ�
������������ӻ��ĳ��У���ʹ֮�ǡ���˵�в���ĳ�
�С�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong20",
                "north" : __DIR__"dong22",
	]));
         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
