//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�����������ڵ���Ʒ����Ҫ����������µ��˶���ȥ
��Ʒ���칤�ߣ��ϱ��Ƕ����䳡��
LONG);
	set("exits", ([
	       "north" : __DIR__"wupinfang",
	       "south" : __DIR__"wuchang4",
        ]));
        set("objects", ([
           __DIR__"npc/thddizi" : 1,
        ]));
	setup();
        replace_program(ROOM);
}

