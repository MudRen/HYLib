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
		"up" : __DIR__"dong8"+(random(3)+5),
		"down" : __DIR__"dong8"+(random(4)+4),
                "west" : __DIR__"dong7"+(random(4)+4),
                "east" : __DIR__"dong6"+(random(6)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"westup" : __DIR__"dong8"+(random(3)+5),
		"eastdown" : __DIR__"dong3"+(random(4)+4),
                "southup" : __DIR__"dong8"+(random(4)+4),
                "northdown" : __DIR__"dong4"+(random(6)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"westsouth" : __DIR__"dong8"+(random(3)+5),
                "eastnorth" : __DIR__"dong8"+(random(4)+4),
	]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
