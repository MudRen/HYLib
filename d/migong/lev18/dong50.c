
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���̵���Ŀ"NOR);
	set("long", HIY @LONG
  ���������̵���Ŀ�ľ�ͷ!!���֮�������ļ�!!
    ��������һ���ڰ���ʪ�Ķ�Ѩ�������ֵ�����Ȼ��������������
��ʪ����ǽ����ȴ��һ����̦Ҳû�С���������ɭɭ�Ķ�Ѩ��㲻��
�ô��˸����������ս .... ����û��ǸϿ��뿪�����ط��ȽϺá�
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
              __DIR__"npc/lev9" : 3,
              __DIR__"npc/player" : 3,
              __DIR__"npc/boss2" : 1,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

