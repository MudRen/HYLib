inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϡ����ܵ���Ұ�Ѿ�����ѩ���ǣ�����
��ȥ�����Լ��Ѿ��������ޱ��޼ʵ�ѩԭ�С���������ѩ����Х������
�����˻����������������ƺ���һ�ƴ�������
LONG );
	set("exits", ([
		"north" : __DIR__"dongcheng",
		"south" : __DIR__"dadao2",
	]));
 	set("outdoors", "daiwai");
	setup();
	replace_program(ROOM);
}


