// Room: /d/yanjing/to_yj1
inherit ROOM;

void create()
{
  set ("short", "ʢ�����");
  set ("long", @LONG
�����ֱ��,ͨ��[ʢ��],�����ѩ���׷׶���,�������˳���ɡ,��
�˳�,�ϳ���������ձ��,һ�������������.ǰ������ߺܿ�ͱ�ѩ����
ס.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"to_yj2",
  "southwest" : __DIR__"to_yj4",
]));
	set("objects",([
		__DIR__"npc/man6":2,
	]));
  setup();
  replace_program(ROOM);
}
