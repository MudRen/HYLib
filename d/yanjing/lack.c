// Room: /d/yanjing/lack
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
΢�����,��������һƬ�۹�,��֦����������֦��������,�㶯��
ˮ������һȦȦ����.���ϱ�������ʯС��,���Գ�ȥ.���ߵĻ�ľ��һ
���᷿�Ǹ�����ס��.��˵����г������;�ס.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"liangziweng",
  "southwest" : __DIR__"road1",
]));
  setup();
  replace_program(ROOM);
}
