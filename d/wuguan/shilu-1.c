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
              "north" : __DIR__"xuetang",
              "south" : __DIR__"zhangfang",
        ]));
        set("objects", ([
           __DIR__"npc/xiaojh" : 1,
        ]));
	set("outdoors", "���");
	setup();
        replace_program(ROOM);
}

