// Room: /d/chengdu/sanxia3
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "����Ͽ" NOR );
        set("long", @LONG
�����ǳ�����Ͽ������Ͽ����ˮ�ɶ�����������Ͽ�ȣ��ӵ���
խ��ˮ���伱�������ĸ�ɽ�м����һ���������ͺ���һ��˿��һ
�㣬���Ѷ��С�
LONG
        );
        set("exits", ([
  "southeast" :  __DIR__"sanxia2",
  "west" : __DIR__"shudao11",
  
   ]));
//        set("no_fight",1);

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

