// Room: /d/yandang/luoyan30.c

inherit ROOM;

void create()
{
	set("short", "�뷿");
	set("long", @LONG
������С��Ĺ뷿,����һ�ź�ľ������֮��,���ڴ��߰���һ����
�����˵Ĵ�ƿ,������˸�ժ�����İ׾�,�Ӵ�������ȥ,Զ����ɽ,��
����ˮ,����ô������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luoyan28",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaojie.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
