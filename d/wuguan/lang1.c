//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�ͨ�������䳡�����Ǽ������߹�����ʱ���˱�̧������
�����������������赹�ġ�
LONG);
	set("exits", ([
	       "west" : __DIR__"wuchang1",
	       "east" : __DIR__"dayuan",
        ]));
        set("objects", ([
           __DIR__"npc/mrdizi" : 1,
        ]));
	setup();
        replace_program(ROOM);
}

