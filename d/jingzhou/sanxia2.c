// Room: /d/chengdu/sanxia2
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "��Ͽ" NOR );
        set("long", @LONG
�����ǳ�����Ͽ����Ͽ��Ҳ�����������һ��Ͽ�ȣ���Ů��
�߸������ڽ��ߣ�ԶԶ��ȥ������һΪͤͤ��������Ů��������
������ʤ�ա�
LONG
        );
        set("exits", ([
  "northeast" :  __DIR__"sanxia1",
  "northwest" : __DIR__"sanxia3",
  
   ]));
//        set("no_fight",1);

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

