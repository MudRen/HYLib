// Room in ����
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
������һƬ����֮�С�������ľïʢ��������գ��ǳ����졣����
�����������������ֵı߽磬������Ƭ���ַǳ���һ����紵������
ľ����ɳɳ��������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southwest" : __DIR__"shulin1",
		"north":__DIR__"shulin3",
	]));
       setup();
	replace_program(ROOM);
}	
