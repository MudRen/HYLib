// Room: /d/menggu/shulin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�綯����,��Ҷˢˢ����,��Ƶ��¹��¼�ֻ�����ĵ��۾�����������
���ƶ�.ͻȻ����ļ������ë���Ȼ,��ͻأ��ֹͣ,���������ǻ�ɽɽ
��,�������Ӿ��ǲ�ԭ.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhucong.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"hill1",
  "west" : __DIR__"caoyuan1",
]));

	setup();
	replace_program(ROOM);
}
