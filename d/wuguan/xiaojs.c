//cool 98.4.18
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "С����");
        set("long", @LONG
�����������ǰ��һ��С���У����������������С������
���ڲ�ͣ��ߺ�ȡ���Ⱥ���в���С��å��Ѱ�����£�����˶���
ŭ�����ԡ�
LONG);
        set("exits", ([
              "north" : __DIR__"guanmen",
              "southwest" : "/d/xiangyang/northroad1",
        ]));
               set("no_fight",1);
	set("outdoors", "���");
	setup();
}

