// Room in ����
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
������һƬ����֮�С�������ľïʢ��������գ��ǳ����졣����
��һ�����̨�������ϱ��ߣ����Ǹ����ĳ������ˡ��м����ٱ�������
�������������ˡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"shulin2",
		"northup":__DIR__"dongfenghuotai",
	]));
       setup();
	replace_program(ROOM);
}	
