// Room: /d/pk/turen2.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIR "���˳�" NOR);
	set("long", @LONG
������ɭ�ֲ������ϵ����ǲ�֫��ʬ���޴����ǰ���ɫ��Ѫ�Ρ�������
������������־��裬��֪��������ͻ�ܳ�һ����Ӱ��
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"turen6",
		"south" : __DIR__"turen5",
		"west"  : __DIR__"turen1",
	]));
        set("bwdhpk",1);
	setup();
        set("bwdhpk",1);
}
