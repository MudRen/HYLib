// Room: /d/cangzhou/kezhan.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���ջ");
        set("long", @LONG
�����Ǿ��ǲ��ݿ�ջ����˵��ҿ�ջ��ֱ�����Ŀ͵���ϰ�ԭ����һ��
�����ϵĸ��ˣ��Դ����������󣬿�����ҿ�ջ����������·�����ﶼ������
����ջͶ��һ�����Ǹ���λ����һ�����ӣ���ʾ����̽�������ˣ�Ҳ˳����
�����⡣��ջ��һ¥�Ǹ���¥���ܶ����ڴ��Է�����¥����ס�޵ĵط��ˡ�
���ϵĺ�����д���ĸ����֡����ݴ��ջ����
LONG );
        set("exits", ([
        	"north" : __DIR__"beijie3",
		"south" : __DIR__"nanjie1",
		"up" : __DIR__"kezhan2",
	]));
	
	set("objects", ([
                __DIR__"npc/xiaoer" : 1,
		__DIR__"npc/miao" : 1,
        ]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail(CYN"��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n"NOR);

	if ( me->query_temp("rent_paid") && dir != "up" )
		return notify_fail(CYN"��С����æ��ס���͹��Ѿ��������ӣ����᲻ס��������أ����˻���ΪС���ź����أ�\n"NOR);

	return ::valid_leave(me, dir);
}
