// Room: /d/yandang/luoyan21.c

inherit ROOM;

void create()
{
	set("short", "�е���ԡ��");
	set("long", @LONG
�����ô���ʯ���˸���ԡ��,���ȥ��ʱ��,���м���������ˮ����
ɽׯ���˶���ϰ��,ÿ������֮��,������,��Ҫʹ���ϴ�������,��
��������,�������.
LONG
	);
	set("bath_room", "1");
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luoyan18",
]));

	setup();
	replace_program(ROOM);
}
