// Room: /d/yandang/shanlu6.c

inherit ROOM;

void create()
{
	set("short", "���Ʒ�");
	set("long", @LONG
���Ʒ������������ϳ�,���270������,��Ⱥ�廷����ֱ������
��ҹ��,��λ�õõ�,˫��ͳ�Ϊչ�����ɵĲ�ӥ,��ʫ��'�������ʯ,��
ҹ��Ϊӥ,�������ȥ,��ã������.'
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lieren.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"shanlu5",
  "enter" : __DIR__"guanyin",
]));

	setup();
	replace_program(ROOM);
}
