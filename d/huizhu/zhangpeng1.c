// Room: /d/huizhu/zhangpeng1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ������С�ɵ��������Ż����ĵ�̺���м�����С���������˵ļ�
���ο̳�����Ļ��ƣ�������Ÿ���ƿ�����˼�֦Ұ����һ����ͭ���Ӿ�
��������ı��ϣ����ó��Ǹ������ס����
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huoqingtong.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"buluo1",
]));

	setup();
	replace_program(ROOM);
}
