// Room: /d/welcome/newbie2
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "����ѵ����");
  set ("long", @LONG
�������Ǽ������ѿ�������ָ�ϣ����ڳԺȰ�ʦ�������ǾͲ��ٶ�˵
��Ҫ˵��ֻ�ǹ��ں����һЩ��չ�����������뿴�����ϴ����Ǳ���Ϸ
������������ű���Ϸ��һЩ��Ҫ������һ��ҪŬ����ϣ���Ҫ����
�Ҵ������㡣����Ϸ��[1;33mhelp whatsnew[2;37;0m����¼����ĸ�����Ϣ������ÿ�ν�
��Ϸ��ʱ���Ҫ��һ�Σ���������Ϸ�ĸ��¸���������벻������ʧ��
LONG);

  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"newbie3",
  //"oldplayer" : "/d/city/kedian",
]));
  set("no_beg", 1);
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
