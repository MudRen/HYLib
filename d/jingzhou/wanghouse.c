// Room: wanghousemen
// congw 980830

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴������࣬����
������������������Ϲ�������������д�š��򸮡�����������֡�
LONG
	);

	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"dayuan",
	]));

	setup();
	replace_program(ROOM);
}

