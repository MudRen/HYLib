// Room: /d/yanjing/huayuan
inherit ROOM;

void create()
{
  set ("short", "С��԰");
  set ("long", @LONG
������÷�����ɵ�̫��ʯ�������,֦ͷ���Ļ�ѩ��δ�ڻ�,�����ɫ
�Ļ�����΢¶����.һ������ʯС��ͨ�򱱱ߵĻ�¥,�ϱߵ�һ�������������
��,�ڴ�԰�ϱ�Χ��һСȦ.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hualou",
  "south" : __DIR__"huilang1",
]));
  set("outdoors", "yanjing");
  setup();
  replace_program(ROOM);
}
