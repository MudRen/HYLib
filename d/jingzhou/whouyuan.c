// Room: whouyuan
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�������򸮵ĺ�Ժ��Ժ������һ�øߴ��������������ա�������һ��С�ţ�������һƬ
�����͵Ĳ˵ء�
LONG
	);

	set("exits", ([
		"south" : __DIR__"dayuan",
		"west" : __DIR__"caidi",
	]));

	setup();
	replace_program(ROOM);
}

