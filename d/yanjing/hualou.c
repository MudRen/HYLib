// Room: /d/yanjing/hualou.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
¥���ı߿��������ȵĴ���,�λ��Ĵ������ŵ��̲���ɴ,�ݽǵ�
��ľС������һ���׵ľ��²��,���ϵĺ���С��¯���ð�ͭ����ʢ��Щ
��ϸ̿��,һ��С��¥��ͨ���ϲ�.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huayuan",
  "up" : __DIR__"hualou1",
]));
	set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/clone/clothxiaohuolu.c" : 1,
  __DIR__"npc/binu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
