// Room: /d/sandboy/trees1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һƬ�߲���������,�����Ҷ�������Ʈ��,���������˺���һ��,��
�ż�̵Ĺ�ľ���Բ���������׻�������.�����ֵ��ʱ��ʱ����������
�ֵ�����,���������ľ���ս.����һƬ�ݵ�.
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"trees2",
  "east" : __DIR__"turf",
]));

	setup();
	replace_program(ROOM);
}
