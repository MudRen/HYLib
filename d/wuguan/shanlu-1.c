//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ��·�ϣ���������������Ʒ�����㿴���в�����
�������Ÿ����Ĺ��ߣ����Ǳ߹�������������ݴ�����
LONG);
	set("exits", ([
	       "east" : __DIR__"wupinfang",
	       "westup" : __DIR__"dating",
        ]));
        set("outdoors", "���");
	setup();
        replace_program(ROOM);
}

