// Room: /city2/aobai3.c



inherit ROOM;

void create()
{
	set("short", "���ݸ�");
	set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ�أ���������һ��޴��ޱȵ���䣬
��Ȼ�������չ����ı��ˮ�ص����������˻��ݡ������ǳ�������һ
�û����������дУ��ڸ��˴���Ժ�ӣ��Ե���ɭ�ֲ�������һ������
�ߵ�ͨ����Ժ���м����ٱ����ء�
LONG );
	set("exits", ([
		"west" : __DIR__"aobai4",
		"east" : __DIR__"aobai2",
		"north" : __DIR__"aobai3",
	]));
//	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}