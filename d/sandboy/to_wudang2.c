// Room: /d/sandboy/to_wudang2
inherit ROOM;

void create ()
{
  set ("short", "�䵱ɽǰ");
  set ("long", @LONG
����С·,�����ݴ�,������һ����ɽ��ǰ,����һ��������ʯ��һֱ
ͨ��ɽ��,��ɽ�ĸߴ�����¶�����Ǻ�ǽ.���Ͻ���һ�������ֱ,��˵���Ŵ�
·һֱ��,���ܵ����ϵ�һ��--�ɶ�
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "ʯ��" : "�������<�䵱ɽ>��������.
",
]));
  set("exits", ([ /* sizeof() == 1 */
   "northup" : "/d/wudang/shijie1",
   "east" : __DIR__"to_wudang",	
]));
  set("outdoors", "/d/sandboy");

  setup();
}
