//nan1
  

inherit ROOM;

void create ()
{
  set ("short", "ƽ�����Ͻ�");
  set ("long", @LONG
����ƽ���ǵ��Ͻ֣����Ľֵ������˲�������һ�����ڽֵ���
����������������һ�����ݡ������һ�ҿ�ջ��һ���������������
��������֪����һ�Ҳ�С�Ŀ�Ǯջ��
LONG);

  set("no_beg", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"guangchang",
  "west" : __DIR__"pingankezhan",
  "south" : __DIR__"nan2",
  "east" : __DIR__"xiaochi",
]));
  set("outdoors", "pingan");
  set("pingan", 1);
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}
