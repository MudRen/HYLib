// Room: /d/welcome/newbie1
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "����ѵ����");
  set ("long", @LONG
�������Ӷ��˿���(eat)�����˿���(drink)�������ж��������
(get)����Ȼ������û���ȥ��(buy),��Ҳ���԰��㲻�õĶ���������
(sell),��������ˣ�����˯��һ��(sleep)����Ȼ������ҵ���˯����
�ط���
���������֮·��һ������֮·����·ͨ����ǹ��Ľ�����Ϊ����
���ڽ��Ľ���·�Ϲ���һ����˳���������ȿ�һ��[1;33mhelp newbie[2;37;0m������
������ϸ�Ľ�˵��һ����������̶�е�����֮����Ҫ�����������Ǳز����١�
LONG);

  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"newbie2",
 // "oldplayer" : "/d/city/kedian",
]));
  set("no_beg", 1);
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
