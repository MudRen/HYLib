//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ��·�ϣ�һֱͨ���Ժ��·������Щ��ͨ�Ļ��ݣ�����
��С�񣬲�ͣ�Ľ��š�
LONG);
	set("exits", ([
	       "north" : __DIR__"houyuan",
	       "south" : __DIR__"shilu-4",
        ]));
        set("objects", ([
           __DIR__"npc/puren1" : 1,
        ]));
	set("outdoors", "���");
	setup();
        replace_program(ROOM);
}

