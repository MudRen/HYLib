// Room in ����
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
������һƬ����֮�С�������ľïʢ��������գ��ǳ����졣����
���Ǹ����ĳ������ˡ��кܶ��˴������Բ�����������������ķ���Զ
ʤ������ս���е���ԭ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southwest" : __DIR__"baihumen",
		"northeast":__DIR__"shulin2",
	]));
	set("objects", ([
   "quest/skills2/wunon/dalie/dalie" : 2,
	
	]));	
       setup();
	replace_program(ROOM);
}	
