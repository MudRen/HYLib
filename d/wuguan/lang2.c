//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�ͨ�����䳡�����������ģ��������֡�
LONG);
	set("exits", ([
	       "east" : __DIR__"wuchang2",
	       "west" : __DIR__"dayuan",
        ]));
        set("objects", ([
           __DIR__"npc/xiaohs" : 1,
        ]));
	setup();
        replace_program(ROOM);
}

