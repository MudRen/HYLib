// zhongtang.c

inherit ROOM;
#include <ansi.h>

void create()
{
       set("short",HIC"����"NOR);
       set("long", @LONG
��ٲ�����һ��é�ݵ����ã�ֻ�����г����ª�����ྻ�쳣������ֻ��
һ��һ����������ޱ��
LONG
        );

       set("exits", ([
	  "out" : __DIR__"xiaolu",
	  "east" : __DIR__"xiaoshi",
          "north" : __DIR__"wshi",
       ]));	
       setup();
       replace_program(ROOM);
}

