// Room: /d/huizhu/linzhong
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
���������е�һƬ�յ�,����Ϊ�Ĵ�ɨ�����,�յص�����һ������
�Ѿ�Ϩ��,����ɢ����һЩţ��Ĺ�ͷ,�����ʯ��ɢ�������������.
�ݵ�����������˼�̤���ĺۼ�.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shulin2",
  "north" : __DIR__"shulin1",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
