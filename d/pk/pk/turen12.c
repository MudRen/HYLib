// Room: /d/pk/turen12.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIR "¾�˳�" NOR);
	set("long", @LONG
������ɭ�ֲ������ϵ����ǲ�֫��ʬ���޴����ǰ���ɫ��Ѫ�Ρ�������
������������־��裬��֪��������ͻ�ܳ�һ����Ӱ��
LONG
	);
	set("exits", ([
		"northeast"  : __DIR__"turen10",
		"west"  : __DIR__"turen11",
		"north" : __DIR__"turen9",
"southup" : "/d/pk/sjsz/wgarden",
"northup" : "/d/pk/bwdh/gate",
	]));
        set("bwdhpk",1);
	setup();
        set("bwdhpk",1);}
