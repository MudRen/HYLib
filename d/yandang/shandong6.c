// Room: /d/yandang/shandong6.c

inherit ROOM;

void create()
{
	set("short", "���綴");
	set("long", @LONG
������ʯ����,��ʯ���,�绢,��ʨ,����ɮ�ݷ�,���������,ǧ��
��̬,������ʤ.����ȥ,�����ж�,ʯ����ʯ.�����վ�,С������,������
��,�Ƿ�����˼,ֱ�ǹ���.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandong5",
  "northup" : __DIR__"shandong7",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/big_stone.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
