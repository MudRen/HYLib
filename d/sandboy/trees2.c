// Room: /d/sandboy/trees2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һƬ�߲���������,�����Ҷ�������Ʈ��,���������˺���һ��,��
�ż�̵Ĺ�ľ���Բ���������׻�������.�����ֵ��ʱ��ʱ����������
�ֵ�����,���������ľ���ս.��������С����������.
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"to_wudang",
  "east" : __DIR__"trees1",
  "north" : __DIR__"to_sandboy2",	
]));

	setup();
	replace_program(ROOM);
}
