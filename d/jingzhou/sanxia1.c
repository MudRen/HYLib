// Room: /d/chengdu/sanxia1
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "����Ͽ" NOR );
        set("long", @LONG
�����ǳ�����Ͽ������Ͽ��������ɽ������������գ����ν��
Գ���ĩ�ʰ�����������ӵ��Ƚ�խ����ˮ��Ĳ�����������������
����������ʱ��������������ȥ��
LONG
        );
        set("exits", ([
  "southwest" :  __DIR__"sanxia2",
  "east" : __DIR__"shudao10",
  
   ]));
//        set("no_fight",1);

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

