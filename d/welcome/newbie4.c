// /d/welcome/welcome.c
// ����II
// ����(lywin) 2000/6/4

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�����к���II����ѵ����");
  set ("long", @LONG
[1;32m�������һ�����־͵���������һ���ɣ������Ժ����Ϸ�кܴ�İ���
������Ҫ����Ϸ��Ϣ�����Ｘ��ȫ�������ҵ�!���õĿ�ʼ�ǳɹ���һ�롣[2;37;0m
[1;33m����help -old����ȫ�İ���ϵͳ[2;37;0m
[1;33m����help shuoming1������ָ��[2;37;0m
[1;33m����help aboutquest������ָ��[2;37;0m
[1;33m����help questlist �������б�[2;37;0m
[1;33m����help menpai�����ɽ���[2;37;0m
[1;33m����help maps�ǵ�ͼ��ȫ[2;37;0m
[1;33m����help whatsnew����������[2;37;0m
[1;33m����help work��ְҵϵͳ[2;37;0m
[1;33m����skills2�ǲ鿴������漼�ܵȼ���[2;37;0m
[1;33m����help wlmm����������[2;37;0m
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"newbie1",
  //"oldplayer" : "/d/city/kedian",
]));
  set("no_beg", 1);
  set("valid_startroom", "1");
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
