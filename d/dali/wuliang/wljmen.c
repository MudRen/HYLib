// Room: wljmen.c
// By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY"��������"NOR);
	set("long", @LONG
��������������������������گ����ɽ���ɣ������˾�ס����ɽ��������
�Դ����ʹ�����Ϊ�������������ڣ�ÿ�����꣬�������µ��ӱ��ڽ�������
���䶷������ʤ����ס��������
LONG
	);
	set("exits", ([ 
	    "southdown" : __DIR__"xiaolu5",
	    "enter" : __DIR__"wlj",
        ]));

        set("objects", ([
              __DIR__"npc/yu_guangbiao" : 1,
              __DIR__"npc/wu_guangsheng" : 1,
        ]));

        set("outdoors", "����");

	setup();
}

int valid_leave(object me,string dir)
{ 
     if( dir == "enter"
      && (present("yu guangbiao", environment(me))))
         return notify_fail("�������ǰ��ס���ȥ·���������صأ��κ��˲����������ڡ�\n");
     if( dir == "enter"
      && (present("wu guangsheng", environment(me))))
         return notify_fail("���ʤ��ǰ��ס���ȥ·���������صأ��κ��˲����������ڡ�\n");
         return ::valid_leave(me, dir);
}
