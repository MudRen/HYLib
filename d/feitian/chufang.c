// Room: /d/feitian/chufang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������Ż������ĳ�������Ȼ��Ż������涨�˿���ʱ�䣬�����ٵ��ӻ�
�ǳ��ų�ʦ������֮����͵͵��Щ�����Ա�����֮ԥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
          "northwest" : __DIR__"xiangfang",
          "northeast" : __DIR__"huayuan",
]));
	set("objects",([
	__DIR__"obj/shousi":2,
	__DIR__"obj/cha":3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
