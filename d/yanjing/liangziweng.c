// Room: /d/yanjing/liangziweng.c

inherit ROOM;

void create()
{
	set("short", "�����̾Ӵ�");
	set("long", @LONG
��һ̤����,���ҩ�����,�ּ����ϡ���ϡ�����,�������������
ҩ��,�Լ����СС��ƿ�����޶����׶�������,ƿ�����滭�Ķ���Щ����
�����ķ���,����һ������.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liangziweng.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lack",
]));

	setup();
	replace_program(ROOM);
}
