
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���̵���Ŀ"NOR);
	set("long", HIY @LONG
    ��������һ���ڰ���ʪ�Ķ�Ѩ�������ֵ�����Ȼ��������������
��ʪ����ǽ����ȴ��һ����̦Ҳû�С���������ɭɭ�Ķ�Ѩ��㲻��
�ô��˸����������ս .... ����û��ǸϿ��뿪�����ط��ȽϺá�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("no_npc",1);
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong50",
		"west" : __DIR__"dong4"+(random(9)+1),
                "east" : __DIR__"dong4"+(random(9)+1),

	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong48",
                "east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong50",
                "north" : __DIR__"dong49",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong50",
                "east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong33",
                "north" : __DIR__"dong49",
	]));

         set("objects", ([
              __DIR__"npc/lev9" : 6,
              __DIR__"npc/lev7" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

