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
		"south" : __DIR__"dong4"+(random(2)+6),
		"north" : __DIR__"dong4"+(random(3)+5),
                "west" : __DIR__"dong5"+(random(2)+6),
                "east" : __DIR__"dong5"+(random(3)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"westnorth" : __DIR__"dong4"+(random(3)+5),
		"eastsouth" : __DIR__"dong5"+(random(4)+4),
                "southwest" : __DIR__"dong5"+(random(3)+5),
                "northeast" : __DIR__"dong4"+(random(2)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"down" : __DIR__"dong5"+(random(2)+6),
                "up" : __DIR__"dong5"+(random(3)+5),
	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
