// Room: /d/chengdu/shudao11
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "���" NOR );
        set("long", @LONG
�����������������µ�����ϣ�����������Խ����ɽ���ͽ���
�Ĵ���أ����ߣ���ȥ�羰��������Ͽ����·ʮ����᫣�ʱ����ת
ʱ����ɽ��ʱ����Ҫ����ɭ�֡�
LONG
        );
        set("exits", ([
  "east" :  __DIR__"sanxia3",
  "northwest" : __DIR__"shudao12",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

