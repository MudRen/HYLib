//Cracked by Kafei
// Room: /d/xixia/ysdian.c

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
���ǻʹ������ĵ��ã�Ҳ�����Ļʵ���Ԫ껺�Ⱥ�����µĵط���
��������ѩ�׵���ʯ�壬������ѩ�׵��ᢣ��������з������Σ��Ϸ�
����һ����ң����顺����Ϊ��������ʱ���Ļʵ��������ɣ���������
��ʿ�����ĵĹ����ﵽ�˶��壬����Ĵ��κͶ���Ĵ��ɶ���Ϊ�˼ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"square",
  "north" : __DIR__"huilang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
