// Room: /d/yandang/luoyan18.c

inherit ROOM;

void create()
{
	set("short", "�е��Ӿ���");
	set("long", @LONG
�߽�����,���ŵ�һ�ɹ�ζ,�����Եú�����,�����ܾ�û�˴�ɨ��
����,Ҳ�ѹ�,��Ҷ�æ������,˭������Щ��.�ҽǵ�ϴ������,������
�·�,�������õ�һ��ʱ��Żᱻϴ.
LONG
	);
	set("sleep_equipment", "����");
	set("sleep_room", "1");
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan17",
  "north" : __DIR__"luoyan21",
]));

	setup();
	replace_program(ROOM);
}
