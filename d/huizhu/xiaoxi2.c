// Room: /d/huizhu/xiaoxi2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ת�˼����䣬��һ�Ų��������д��˳�ȥ,��ǰһƬ����������϶�
����һ�����ٲ�,ˮ���Ľ�,�չ�ӳ��,�ֳ�һ���ʺ�,���ܻ����β�ӻ�
�����䣬��ӳ�ڱ��̵ĺ�ˮ֮�У�����Ī����Զ���Ǵ�Ƭ���ƽԭ�ޱ�
�޼�,�������ȥ��������ӣ��ݵ��ϼ���ֻ�����ڱ��ܳԲ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiangxiang.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"xiaoxi1",
  "north" : __DIR__"byriver",
]));

	setup();
	replace_program(ROOM);
}
