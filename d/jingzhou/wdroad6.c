// wdroad6.c ����·
// by Xiang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY "����·" NOR);
	set("long", @LONG
	������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǻ������磬
��˵���������˳�û�����ɾ�����
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southeast" : __DIR__"wdroad5",
		"west" : __DIR__"wdroad7",
	]));

	setup();
	replace_program(ROOM);
}

