// Room: /d/japan/xuanguan.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����߸ߵ��ſ�,��������,�Ա߰��ż���ľ��,ȥ�ݷ���������,��
Ҫ�ڴ˻�Ь����ܽ�ȥ,��������ʿ���������ĽӼ�.
LONG
	);
	set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/man" : 2,
            ]));
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"zoulang",
  "north" : __DIR__"liushengfu",
]));

	setup();
	replace_program(ROOM);
}
