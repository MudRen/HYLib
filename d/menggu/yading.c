// Room: /d/menggu/yading
inherit ROOM;

void create()
{
  set ("short", "ɽ�¶�");
  set ("long", @LONG
�¶��Ǹ��޴��ƽ̨�������˰�����ѩ������޴��ʯͷ������һ��,
��״ǧ��ٹ�,��������ප����С��,�����,��������.�ıߵ�ɽ��ƽƽ
����,���ð�����б�����±�.
LONG);

  set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"downxuanya",
]));

  setup();
  replace_program(ROOM);
}
