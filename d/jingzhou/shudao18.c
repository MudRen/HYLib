// Room: /d/chengdu/shudao18
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "���" NOR );
        set("long", @LONG
�����������������µ�����ϣ����治Զ���͵��ɶ��ˣ���
��ʼ�����ն�������
��
LONG
        );
        set("exits", ([
  "west" :  __DIR__"shudao19",
  "eastup" : __DIR__"shudao17",
  
   ]));
        
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
	replace_program(ROOM);
}

