// Room: /d/yandang/jiedao2.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
�ֵ����ߵķ��Ӷ������㵴ɽ�п������Ĵ�ʯ���ɵ�,���������
Զ,ɽʯ����Щ����,��Щ�����ĵط�,������������̦.��˵���ַ���
��ů����,���Ե����˺���ϲ��,�ֵ���������һ�ҿ�ջ.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaohai.c" : 2,
  "/d/hainan/npc/man1.c" : 3,
]));
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"xiaolu",
  "west" : __DIR__"kezhan",
  "south" : __DIR__"jiedao",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
