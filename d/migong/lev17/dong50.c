
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"ˮ��֮��"NOR);
	set("long", BLU @LONG
  ������ˮ��֮�ݵľ�ͷ!!ˮ֮�������ļ�!!
    �������ں����ϣ��������ϡ����������ꡣ����������һ���ŵķ����֣�֦��
��Ӳ��ϸϸ����ģ���ľ���һ���ֲ�������һƬ����Ĵ󺣣����˲�ͣ����
�����µ̡�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
        set("outdoors", "migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong49",
                "east" : __DIR__"dong49",
	]));
         set("objects", ([
              __DIR__"npc/lev5" : 1,
              __DIR__"npc/lev7" : 1,
              __DIR__"npc/lev9" : 2,
              __DIR__"npc/player" : 1,
              __DIR__"npc/boss2" : 1,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

