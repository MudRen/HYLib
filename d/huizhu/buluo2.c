// Room: /d/huizhu/buluo2.c

inherit ROOM;

void create()
{
	set("short", "���岿��");
	set("long", @LONG
�˴����������֣������б��ͨ����ԭ����Ⱥ��ţ���ڲ�ԭ�ϳ�
����Ϸ��Զ����ɽɽ����ͬ���֮���һ�����ϣ��Ѻ����һ�ж��ڵ�
ס�ˡ������Ǽ�������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhangpeng3",
  "east" : __DIR__"zhangpeng2",
  "south" : __DIR__"buluo1",
  "northdown" : __DIR__"xiepo",
]));
	set("outdoors", "huizhu");

	setup();
	replace_program(ROOM);
}
