
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
		"south" : __DIR__"dong3"+(random(4)+5),
                "north" : __DIR__"dong3"+(random(4)+5),
		"west" : __DIR__"dong40",
                "east" : __DIR__"dong3"+(random(4)+5),

	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(4)+5),
                "north" : __DIR__"dong40",
		"west" : __DIR__"dong3"+(random(4)+5),
                "east" : __DIR__"dong3"+(random(4)+5),
	]));
         set("objects", ([
              __DIR__"npc/lev1" : 2,
              __DIR__"npc/lev3" : 2,
              __DIR__"npc/lev2" : 3,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}