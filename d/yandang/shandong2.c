// Room: /d/yandang/shandong2.c

inherit ROOM;

void create()
{
	set("short", "͸�춴");
	set("long", @LONG
͸�춴��������������ʮ�ɸߵĶ������и�СС���촰,�������
����͸������,�ڰ��ڵĶ�����,�γ�һ����·,����Ͽ�,����һ����Լ
���ɵ�����,��˵����ʼ�������������ƶ�,��������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"shandong1",
  "northeast" : __DIR__"shandong4",
]));

	setup();
	replace_program(ROOM);
}
