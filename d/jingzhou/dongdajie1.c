// Room: /jingzhou/dongdajie1.c
// congw 980829

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ����ϱ���һ�����ӵ�Ժ�ӣ������εĴ�����
��д�š�������Ժ���ĸ��̽���֣��Ծ����������治ʱ�ش���ѧ��������ٴ�
�Ķ�������������һ������ߵİ������ഫ�ǹ�ȥһλ״ԪΪ��ĸ����֮������
��ġ�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"shuyuan",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"baita",
	]));

	setup();
	replace_program(ROOM);
}

