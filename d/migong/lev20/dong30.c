
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"��ʹ֮�Ƕ�����"NOR);
	set("long", HIW @LONG
��ʥ����������������޴����ڣ��º͵�̫��������
�����ɼ��������ϣ�ʹ������������������ҫ�Ĺ�ԡ�
������������ӻ��ĳ��У���ʹ֮�ǡ���˵�в���ĳ�
�С������Ƕ������������������ط���ս�������ĸ��ֹ���!!
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

set("sleep_room",1);
	set("exits", ([
                "south" : __DIR__"dong29",
	]));
         set("objects", ([
              __DIR__"npc/lev"+(random(5)+5) : 1,
              __DIR__"npc/lev"+(random(6)+4) : 1,
              __DIR__"npc/lev"+(random(8)+2) : 1,
              __DIR__"npc/lev"+(random(9)+1) : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
