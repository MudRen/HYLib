// Room: /u/jpei/thd/yangjia.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����һ�������Ѿõ��񷿣��Ҿ߰���һӦ��ȫ��ֻ�Ƕ�����һ���������
���м���һ��С�������ϵı��뻹��û�г�ȥ����������ȥ�ĺܴ�æ��ǽ�Ϲ�
��һ����ǹ��
LONG
	);

	set("item_desc", ([
		"qiang" : "һ���þ��˵���ǹ��������ԭ��Ӧ����һ�Եģ���֪Ϊ��ֻʣ��һ�ˡ�",
		"tieqiang" : "һ���þ��˵���ǹ��������ԭ��Ӧ����һ�Եģ���֪Ϊ��ֻʣ��һ�ˡ�",
	]) );

	set("exits", ([
		"south" : __DIR__"njroad3.c",
	]));

	setup();
	replace_program(ROOM);
}
