// Room: /d/yandang/shanlu8.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��˵Ԫ������Ԫ��,ɽ������,ԭ������е��޶��������־��յ�
��ɮͳͳ�����ҵ���,ֻ��һ�����ĳ��Ļ��ɮ����Ȯ�������Ᵽȫ����
��,��������ĸ���˵�е�ɽ����.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/nuhai.c" : 1,
  __DIR__"npc/nanhai.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shanlu7",
  	"westdown" : __DIR__"to_yandang3",
  "enter" : __DIR__"shandong1",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
