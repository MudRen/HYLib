// Room: /d/sandboy/huangni
inherit ROOM;

void create()
{
  set ("short", "�����");
  set ("long", @LONG
����һ�������,�Ѿ����˲ȵĸߵ����,�����������˻���ͦ��,
��Ϊ�Ӵ��򶫿��Ե������к���.
LONG);

  set("outdoors", "/d/sandboy");
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/hangzhou/dalu1",
  "west" : __DIR__"well",
]));
  setup();
}
