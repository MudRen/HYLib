// Room: /d/hainan/taotree3
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�һ���");
  set ("long", @LONG
һƬѤ�õ��һ���,������һ������ʯ���ɵ�ˮ��,�ı�������ݵ�, 
��ɫ��������ˮ����ð����,����ط�Ū����������,������[31m��Ȫ[37m��,�ڰ� 
����,�ƺ��м�������Ӱ. 
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "��Ȫ" : "���ɵ�������������Ȫˮ��,����ϴ�����Ǹ�������!
����,�㶼���̲�סҪ����ȥ��(jump down)!
",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ziyun.c" : 1,
]));
  set("outdoors", "/d/hainan");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"outtree2",
  "south" : __DIR__"taotree1",
]));

  setup();
}
void init()
{
    add_action("do_jump", "jump");
}

int do_jump(string sss)
{object ob;
 ob=this_player();
  if (sss!="down") return 0;
  message_vision("$N�ɿ���ѵ��·�,��ͨһ��������"+RED+"��Ȫ!\n"+NOR,ob);
  tell_room("/d/hainan/wenquan.c",ob->query("name")+"��������,����һƬˮ��!\n");
  ob->move("/d/hainan/wenquan.c");
return 1;
}
