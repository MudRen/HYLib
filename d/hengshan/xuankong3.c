// Room: /d/hengshan/xuankong3.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µĴ��۱����������һ������������������
��ʮ������ķ��񣬴���������ʮ���κ����񣬵�������
̬����Ĵ�С����һ����ʮ����
LONG
	);
	set("exits", ([
		"out" : __DIR__"xuankong2",
	]));
        set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}

