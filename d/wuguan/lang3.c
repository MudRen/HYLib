//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�һֱͨ���Ժ���ϱ��������䳡��
LONG);
	set("exits", ([
	       "north" : __DIR__"shilu-4",
	       "south" : __DIR__"wuchang3",
        ]));
	setup();
        replace_program(ROOM);
}

