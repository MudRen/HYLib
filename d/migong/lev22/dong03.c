
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
		"east" : __DIR__"dong"+(random(18)+3),
		"south" : __DIR__"dong"+(random(13)+3),
                "west" : __DIR__"dong"+(random(8)+3),
                "north" : __DIR__"dong"+(random(3)+3),
	]));
          set("objects", ([
__DIR__"npc/lev3" : random(6),
//             "/clone/box/gboxm" : random(2),
         ]));
if (random(3)==0)
	set("exits", ([
		"eastnorth" : __DIR__"dong"+(random(8)+3),
		"southwest" : __DIR__"dong"+(random(3)+4),
                "westsouth" : __DIR__"dong"+(random(18)+4),
                "northeast" : __DIR__"dong"+(random(13)+4),
	]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
