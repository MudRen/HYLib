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
		"north" : __DIR__"dong11",
		"up" : __DIR__"dong98",
                	]));
         set("objects", ([
              __DIR__"npc/lev3" : 2,
             __DIR__"npc/lev2" : 2,
             __DIR__"npc/lev1" : 2,
                ]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
