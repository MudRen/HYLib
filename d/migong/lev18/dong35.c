
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
set("outdoors", "migong");
	set("exits", ([
                "west" : __DIR__"dong3"+(random(5)+4),
		"east" : __DIR__"dong3"+(random(5)+4),
		"south" : __DIR__"dong3"+(random(5)+4),
                "north" : __DIR__"dong3"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong3"+(random(5)+4),
                "west" : __DIR__"dong3"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(5)+4),
                "north" : __DIR__"dong3"+(random(5)+4),
	]));

         set("objects", ([
              __DIR__"npc/lev3" : random(8),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

