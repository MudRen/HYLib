// Room: /d/chengdu/shudao15
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "���" NOR );
        set("long", @LONG
�����������������µ�����ϣ�����������·�Ϸ�Ҫ��
��С�ģ��þ�ȫ���������С�����һ�������;��ú�����...
��
LONG
        );
        set("exits", ([
  "northwest" :  __DIR__"shudao16",
  "eastdown" : __DIR__"shudao14",
  
   ]));
        
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
}

int init()
{
	object me;
	int i;
	me=this_player();
	i=(int)me->query("max_qi")/10;
	me->receive_damage("qi", i );
	message("vinson","���������������ϣ��۵�����������\n", me );
}