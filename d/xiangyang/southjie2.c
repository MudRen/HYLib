// Room: /d/xiangyang/southjie2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
��������������ķ����ضΣ���Ȼ�þ�ս�𣬵��ڹ�����
�˵ı����£��������ϰ��չ��ŷǳ��������ȵ����������
������������һ�Ҷĳ���������һ�������¥�󣬹��š��ơ�
���������Ŷ�������һ�����ң����顰����¥�����֡�һ����
������ζ�˱Ƕ�����
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"nixianglou",
		"west"  : __DIR__"duchang",
		"south" : __DIR__"southjie3",
		"north" : __DIR__"southjie1",
	]));
	set("objects", ([
"/clone/master/master"+(random(24)+1): random(2),
		"/d/city/npc/liumang" : 1,
	]));
	setup();
	replace_program(ROOM);
}
