// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "ɭ��");
	set("long", @LONG
�г��������һ���������У����ܶ����ǲ����ľ������������ã���
��ȴ�ڳ���������ƻ衣����һֱͨ���������� 
LONG
	);
        set("outdoors", "����");

	set("exits", ([
             "north" : __DIR__"shanlin-4",
	     "westdown" : __DIR__"shanlin-2",
	]));
        set("objects", ([
	      __DIR__"obj/yeguo" : 2,
	]));
	setup();
	replace_program(ROOM);
}
