//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ��·�ϣ������ȥ���Ǻ�Ժ�ˣ�����������������
���洫�����󷹲˵���������������ݵķ����������ȥ����ݴ�����
LONG);
	set("exits", ([
          "east" : __DIR__"shilu-2",
          "south" : __DIR__"lang3",
          "north" : __DIR__"shilu-3",
          "west" : __DIR__"fanting",
        ]));
        set("outdoors", "���");
	setup();
        replace_program(ROOM);
}

