// Room: /d/menggu/xiaolu
inherit ROOM;

void create()
{
  set ("short", "С·");
  set ("long", @LONG
���е�һ��С��,�߰���ƽ,ʱ��Ҫ��һЩ��·�Ĺ�ľ�д���,�߹�
����Ĳ�Զ,һ��ɽ��ƽ�ض���,ɽ�°����������֮��,���������ܵ�
��ȥ.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"downxuanya",
  "eastdown" : __DIR__"shulin4",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
