// Room: /jingzhou/yamenzhengting
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���϶����������ס������һ������������������ϸ������ǽ������һ�����ң���
�顰�����������ĸ���������Ĵ��֡�֪���������İ����������飬ʦү�����ں�
LONG
	);

	set("exits", ([
		"north" : __DIR__"jzyamen",
		"south" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
		
	]));

	setup();
	replace_program(ROOM);
}

