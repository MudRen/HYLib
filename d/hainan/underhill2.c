// Room: /d/hainan/underhill2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "������");
  set ("long", @LONG
���͵�ɽ�µ�����ͻȻ���˸���,�γ�һ��ͻ����͹��,������ͷ�� 
��Զ�ĵط�,�п��Ჱ��С����ɽ���������.������ϣ��.ͷ���ϰ����� 
��Ʈ��,��������������. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/shuzhi.c" : 1,
]));
  set("outdoors", "/d/hainan");
  set("item_desc", ([ /* sizeof() == 1 */
  "С��" : "һ���Ჱ����,б�����ͱ���.�����ܴ�����(climb)��ȥ.",
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"underhill",
  "southwest" : __DIR__"underhill3",
]));

  setup();
}
int init()
{
object ob;
ob=this_player();
	remove_call_out("greeting");
	call_out("greeting",1,ob);
add_action("do_climb","climb");
}
void greeting(object ob)
{
  if (!ob||environment(ob)!=this_object()) return;
  tell_object(ob,HIC"һ����֦��ɽ���ϵ�����,������һ��.\n"NOR);
  return;
}
int do_climb()
{object ob;
ob=this_player();
if( living(ob) ==0 ) return 1;
message_vision("$NС���������������ȥ!\n",ob);
if (random(ob->query("dex"))>15)
this_player()->move(__DIR__"ontree.c");
else message_vision("ֻ����ͨһ��,$N�Ľų�������ڵ���!\n",this_player());
return 1;

}
