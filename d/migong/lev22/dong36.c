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
		"south" : __DIR__"dong0"+(random(5)+1),
		"north" : __DIR__"dong3"+(random(3)+5),
                "west" : __DIR__"dong3"+(random(2)+6),
                "east" : __DIR__"dong0"+(random(5)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"westup" : __DIR__"dong3"+(random(3)+5),
		"eastup" : __DIR__"dong1"+(random(4)+4),
                "southup" : __DIR__"dong1"+(random(3)+5),
                "northup" : __DIR__"dong3"+(random(2)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(2)+6),
                "north" : __DIR__"dong3"+(random(3)+5),
	]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
