// Room: /d/yanjing/zhongyuan
inherit ROOM;

void create()
{
  set ("short", "������Ժ");
  set ("long", @LONG
һ������ɫ��ʯ��·ͨ�򱱱ߵ���ѩ��,���ǴӴ�����ɽ�п��ɵ�ʯ��
�̾͵�.ɽʯ�伸յ�������𲻶�,��Ѳ�ߵ��ױ���ͨ�����,�����Ů���Ű���
����÷֦��ɨѩ,�Ա�����ˮ֮��.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"road",
  "north" : __DIR__"xiangxue",
  "south" : __DIR__"qianting",
]));
  set("outdoors", "yanjing");
  setup();
  replace_program(ROOM);
}
