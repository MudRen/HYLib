// Room: /d/cangzhou/fuya.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���ݸ���");
        set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷ�
����ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�����������
��ǰѲ�ߡ�
LONG );
        set("exits", ([
        	"east" : __DIR__"beijie2",
		"west" : __DIR__"zhenting",
	]));
        
	set("objects", ([
                __DIR__"npc/yayi.c" : 2,
      	]));
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me)
         && objectp(present("ya yi", environment(me)))
         && dir == "west")
           return notify_fail(CYN"���ۺȵ���������˭������뿪�����\n"NOR);
        return ::valid_leave(me, dir);
}
