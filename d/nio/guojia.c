// Room: /u/jpei/thd/guojia.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����һ�������Ѿõ��񷿣��Ҿ߰���һӦ��ȫ��ֻ�Ƕ�����һ���������
���м���һ��С�������ϵı��뻹��û�г�ȥ����������ȥ�ĺܴ�æ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"njroad2.c",
	]));

	setup();
	replace_program(ROOM);
}
