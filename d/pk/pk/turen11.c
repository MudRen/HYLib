// Room: /d/pk/turen11.c

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
		"east"  : __DIR__"turen12",
		"northwest"  : __DIR__"turen7",
		"north" : __DIR__"turen8",
"southup" : "/d/pk/sjsz/egarden",
"northup" : "/d/pk/bwdh/gate",
	]));
        set("bwdhpk",1);
	setup();
        set("bwdhpk",1);
}
