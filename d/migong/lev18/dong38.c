
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
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong32",
                "east" : __DIR__"dong37",
		"south" : __DIR__"dong35",
                "north" : __DIR__"dong39",

	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong33",
                "north" : __DIR__"dong32",
		"west" : __DIR__"dong34",
                "east" : __DIR__"dong39",
	]));

         set("objects", ([
              __DIR__"npc/lev4" : random(5),
              __DIR__"npc/lev3" : 5,

         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

