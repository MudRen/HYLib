// Room: /d/hainan/haitan
inherit ROOM;

void create()
{
  set ("short", "��̲");
  set ("long", @LONG
�����Ĵ��Ű��ߵ���ʯ,��׵�ɳ̲�ϼ�ֻ��з��Ŭ���������ȥ.
Զ�������Ϸ���Խˮ����,�ں����ϻ���.ԶԶ��,���ܿ����ں�����һƬ��
����Ӱ��,�Ǿ��Ǻ��ϵ�.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tohaitan",
]));
	set("objects",([
		__DIR__"npc/man6":1,
			__DIR__"npc/yuwen2":1,
	]));
  set("outdoors", "/d/hainan");
  setup();
  replace_program(ROOM);
}
