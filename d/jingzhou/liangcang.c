// Room: /jingzhou/liangcang.c
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ǿ��������ˣ����϶�����������dai)�����װ���ǰ��ȴ���֮�����
ʳ��
LONG
	);

	set("exits", ([
		"west" : __DIR__"lcmen",
	]));

	setup();
	replace_program(ROOM);
}

