// Room: /d/pingan/pinganguangchang
inherit ROOM;

void create ()
{
  set ("short", "ƽ���㳡");
  set ("long", @LONG
�����ƽ���ǵ����Ĺ㳡����ʵ˵�ǹ㳡���ˣ����������һ��ƽ��
�������ĵط�һ�������Ҳ��һƬ��ƽ�ľ���ƽ���ǵľ���������Χ����
��ȥ���Խ������ﲢ���رܡ��㳡����Ҳû�кܸ��ӵĽֵ���ֻ��һ��СС
�ĵ����һ�����ϵ�ƽ�������
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pinganlu2",
  "north" : __DIR__"pingankezhan",
  "east" : __DIR__"wuguan",
]));
  set("pingan", 1);
  set("outdoors", "y");
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);

  setup();
  "/clone/board/pingan_b"->foo();
}
