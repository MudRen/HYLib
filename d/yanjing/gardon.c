// Room: /d/yanjing/gardon
inherit ROOM;

void create()
{
  set ("short", "СԺ��");
  set ("long", @LONG
�ƹ�һ�����飬��ǰ�����������߰�ǽ��С�ݡ�����Ѱ�����°���
�ľ��ݣ�����������ݸ���������֮�м���.������Χ���������,����
Щ�߲�,�Աߵ�һ��ˮ�������Ǽ�ˮ�����õ�.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"gardon1",
  "west" : __DIR__"inroom",
]));
  setup();
  replace_program(ROOM);
}
