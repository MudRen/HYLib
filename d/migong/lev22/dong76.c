#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"����֮ʧ��԰"NOR);
	set("long", HIW @LONG
 ������磬Ʈ��������,����,�ذ����ɷ����Ļƽ����̳ɣ����ܵ�ǽ��
���컨���������������ıڻ��;��µ�ʯ�񡣿���������ˮ��ɢ��������
�Ĺ�â���޿�����Ʈ���ڿ��е�����ʹ��һ��������á�
LONG NOR);

	set("exits", ([
		"east" : __DIR__"dong7"+(random(3)+5),
		"south" : __DIR__"dong5"+(random(4)+4),
                "west" : __DIR__"dong7"+(random(4)+4),
                "north" : __DIR__"dong6"+(random(6)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(3)+5),
		"east" : __DIR__"dong5"+(random(4)+4),
                "south" : __DIR__"dong7"+(random(4)+4),
                "north" : __DIR__"dong6"+(random(6)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(3)+5),
                "east" : __DIR__"dong7"+(random(4)+4),
	]));

          set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 3,
             __DIR__"npc/lev"+(random(9)+1) : 3,
                ]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
