// /d/gaoli/xuanwumen
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�������ɽ·������ۣ������ҵ���·��һ��С�ģ�
�Ϳ��ܹ�����ȥ������ȥ�����Կ��������ǵ�ȫò��
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"shanlu3",
		"northup":__DIR__"shanlu5",
	]));

 	set("outdoors", "/d/gaoli");
	setup();
	replace_program(ROOM);
}


