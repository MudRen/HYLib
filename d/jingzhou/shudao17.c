// Room: /d/chengdu/shudao17
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "���" NOR );
        set("long", @LONG
�����������������µ�����ϣ���·�ɶ���ɽ���쳣���С�������
�£�Ȼ����ɽ������ɽ�ѣ�Ҳ�����ú��ߣ���֮����������·�Ϸ�Ҫ��
��С�ģ��þ�ȫ���������С�����һ�������;��ú�����...
��
LONG
        );
        set("exits", ([
  "westdown" :  __DIR__"shudao18",
  "eastup" : __DIR__"shudao16",
  
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