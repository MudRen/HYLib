// Room: /dream/feicui.c
// HEM 1998/9/18
inherit ROOM;
void create()
{
	set("outdoors", "tangmen");
	set("short", "��䳤��");
	set("long", @LONG
	����Ȼ�������У���һ������ȫ���Ǹߴ�������ʯ·���Ե����������
�գ�ֻ��ż���е�����й��·�ϣ���������ֹ���С·�������������һ�㣬������
����������䳤�ȡ���
LONG
	);
        set("outdoors","tangmen");
        set("exits", ([
		"northwest" : __DIR__"zhulin",
                "east" : __DIR__"fufeng",
	]));
        setup();
	replace_program(ROOM);
}

