// Room: /d/yandang/shandong7.c

inherit ROOM;

void create()
{
	set("short", "���綴");
	set("long", @LONG
���붴��,ֻ�������ϲ����˴��СС��Сʯ��,���ι�,������
��'��.....��....'������.����������һ��ʯ���Ӷ�������,��ʯ����
�ν����ķ��ڶ����γ�һ������,����ʯ����ת.ǿ�ҵķ��ƹε����¾�
����.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"dongwai.c",
  "southdown" : __DIR__"shandong6.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
