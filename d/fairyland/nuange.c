// Room: /u/qingyun/jyzj/nuange.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ů��");
	set("long", @LONG
����ɽ��һ����Ϊ���䣬���ڴ�ů��֮��ȴ��ů�紺�����ֲ����δ�����
̿�𣬴˼�ȡů�������������ޱȡ����г���ԻͲ��ã�������϶����Ž���
��棬���Ǹ����������ϱ��Ǵ�����
LONG	);
	set("exits", ([
		"south" : __DIR__"dating",
	]));
/*	set("objects",([
		__DIR__"npc/zhu-jiuzhen" : 1,
	]));*/
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
