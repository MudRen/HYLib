
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
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong3"+(random(6)+4),
                "north" : __DIR__"dong44",
		"west" : __DIR__"dong3"+(random(6)+4),
                "east" : __DIR__"dong45",
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong44",
                "west" : __DIR__"dong3"+(random(6)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(6)+4),
                "north" : __DIR__"dong3"+(random(6)+4),
		"west" : __DIR__"dong4"+(random(3)+4),
                "east" : __DIR__"dong3"+(random(6)+4),
	]));
         set("objects", ([
              __DIR__"npc/lev7" : 3,
              __DIR__"npc/lev5" : 3,
      "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

