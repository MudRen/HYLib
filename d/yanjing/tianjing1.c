// Room: /d/yanjing/tianjing1
inherit ROOM;

void create()
{
  set ("short", "�쾮");
  set ("long", @LONG
���ķ�����һ���쾮,���������Ǹ߸ߵ�Χǽ,Ժ��ˮĥ��שƽ���ĺ�.
����֮��,��������.��ֻҪ���˽���˵�,��Ϊ��������ڵ�,�Ǳ����ֲ�
��.����ķ���û�д���,��Ҳ���ú�խ,����������.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room",
  "north" : __DIR__"intielao",
]));
  setup();
  replace_program(ROOM);
}
