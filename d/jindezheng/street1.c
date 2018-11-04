// Room: /d/jindezheng/street1.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
����һ��ʯ���̳ɵĽֵ�,�ֵ�ͦ��,������������Ⱥ,����,�ŷ�, 
����,��������,ʱ�������������մɵ��������۶���,�ֵ�������һ�� 
ҩ��,����ͦ��. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/maolu.c" : 1,
  __DIR__"npc/silang.c" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"center",
  "east" : __DIR__"jindezhen",
  "north" : __DIR__"doctor-room",
]));
	set("outdoors", "/d/jindezheng");

	setup();
	replace_program(ROOM);
}
