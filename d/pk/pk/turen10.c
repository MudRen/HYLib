// Room: /d/pk/turen10.c

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
		"southwest" : __DIR__"turen12",
		"west"  : __DIR__"turen9",
		"north" : __DIR__"turen6",
"southup" : "/d/pk/sjsz/wgarden",
"northup" : "/d/pk/bwdh/gate",
	]));
        set("bwdhpk",1);
	setup();
        set("bwdhpk",1);
}
