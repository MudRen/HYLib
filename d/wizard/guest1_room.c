// /d/wizard/guest_room.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʦ������");
	set("long", @LONG
��������ʦ����ҽ����ĵط�������������ʦ��������¹��棻���
��������Ӧ�õ���ʦ�����ȥ(POST)��
LONG );

	set("exits", ([
		"east": __DIR__"guest_room",
        ]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	setup();
	call_other("/clone/board/wiz2_b", "???");
}


