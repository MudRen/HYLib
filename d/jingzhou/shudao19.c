// Room: /d/chengdu/shudao19
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "�ٵ�" NOR );
        set("long", @LONG
������һ���ٵ��ϣ������Ѿ����Կ����ɶ������ˣ���ȥ�������
LONG
        );
        set("exits", ([
  "south" :  "/d/chengdu/westgate",
  "east" : __DIR__"shudao18",
  
   ]));
        
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
	replace_program(ROOM);
}

