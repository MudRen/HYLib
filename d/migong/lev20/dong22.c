
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"��ʹ֮�ǹ㳡"NOR);
	set("long", HIW @LONG
��ʥ����������������޴����ڣ��º͵�̫��������
�����ɼ��������ϣ�ʹ������������������ҫ�Ĺ�ԡ�
������������ӻ��ĳ��У���ʹ֮�ǡ���˵�в���ĳ�
�С������и�ħ���㣬����Լ�¼һ��(save)��
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong21",
                "north" : __DIR__"dong23",
                "east" : __DIR__"dong24",
                "west" : __DIR__"dong27",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(3),
         ]));
 set("valid_startroom", "1");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
