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
		"eastup" : __DIR__"dong1"+(random(3)+5),
		"southdown" : __DIR__"dong2"+(random(2)+6),
                "westsouth" : __DIR__"dong2"+(random(2)+6),
                "northup" : __DIR__"dong0"+(random(5)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"westup" : __DIR__"dong2"+(random(3)+5),
		"eastdown" : __DIR__"dong1"+(random(3)+5),
                "southup" : __DIR__"dong2"+(random(2)+6),
                "northdown" : __DIR__"dong1"+(random(6)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"westsouth" : __DIR__"dong2"+(random(3)+5),
                "eastnorth" : __DIR__"dong2"+(random(2)+6),
	]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
