// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

void create ()
{
  set ("short", "ƽ���㳡");
  set ("long", @LONG
�����ƽ���ǵ����Ĺ㳡����������ķ�չ������������ࡣһ��ƽ
���������ĵط�һ�������Ҳ��һƬ��ƽ�ľ���ƽ���ǵľ���������Χ��
����ȥ���Խ������ﲢ���رܡ��㳡������������ķ�չ��ķ��������ˣ�
�����кܶ෿�ݺͽֵ���
LONG);

  set("no_beg", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nan1",
  "west" : __DIR__"west1",
  "east" : __DIR__"dong1",
  "north" : __DIR__"bei1",
]));
        set("objects", ([
"/clone/master/master"+(random(24)+1): random(2),
"/clone/master/master"+(random(24)+1): 1,
	]));
  set("pingan", 1);
  set("outdoors", "pingan");
  set("no_sleep_room", 1);
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}
