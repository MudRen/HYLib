// Room: /d/yandang/kezhan.c

inherit ROOM;

void create()
{
	set("short","ܽ�ؿ�ջ");
	set("long", @LONG
��ջ�ſڹ���һ������,�����ú�ֽ�����ĸ�����'ܽ�ؿ�ջ',��
��ľ������Щ��ͷ��,�ѿ�����ԭ����ľ��,�ڳ�����,�Աߵ�Ժǽһ��
���,������ȥ���е�����.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"yuanluo",
  "east" : __DIR__"jiedao2",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
