//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ��·�ϣ���������涼��ϰ���ã���������������������ģ�
��������ݴ�����
LONG);
	set("exits", ([
	       "eastup" : __DIR__"dating",
	       "west" : __DIR__"shilu-4",
	       "north" : __DIR__"xiwutang",
	       "south" : __DIR__"xiwutang2",
        ]));
        set("outdoors", "���");
	setup();
        replace_program(ROOM);
}

