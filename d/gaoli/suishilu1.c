// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʯ·");
	set("long", @LONG	
������һ����ʯ·��������һ��������ʯ·�������������ƣ���
�����¡������������Լ�������ӵ�������������Զ����һ����Ժ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"northeast" : __DIR__"dadao9",
		"west":__DIR__"suishilu2",
       	]));
       setup();
	replace_program(ROOM);
}	
