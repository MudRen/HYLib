// Room: /d/yandang/luoyan33
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
�ٲ��Ӱٶ��׵İ�Բ�ζ�����ն���,�׷��������������������
̶��,̶�淢��һ���󶣶����˵�����֮��,��ī��ɫ�������,ɢ���
��׺�ŴԴ��̲�.̶���ƺ��ж���������.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhuyoumu.c" : 1,
]));
  set("outdoors", "/d/yandang");
  set("item_desc", ([ /* sizeof() == 1 */
  "̶" : "����ϸ���˿�,�ƺ��ǿ�Сʯ��,��֪�ܲ�����(lao)����.
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "southup" : __DIR__"luoyan32",
]));

  setup();
}
void init()
{
	add_action("do_lao", "lao");
}
do_lao(string arg)
{
	object me,ob;
	me = this_player();
      if ((!arg)||(arg!="Сʯ��")) return notify_fail("��Ҫ��ʲô?\n");
      me=this_player();
      if (me->query("kar")>23)
{  message_vision("$N��ˮ̶���̳�һ���ɫ��ʯ.\n",me);
   ob=new(__DIR__"obj/stone")->move(me);
message("channel:rumor",YEL"��ҥ�ԡ�"+ "ĳ�ˣ�"+me->query("name")+"��ˮ̶���̵�һ�龧ʯ��\n"NOR,users());
me->set("kar",me->query("kar")-1);
        return 1;
    }
else message_vision("$N���˰���,ʲô��û�̵�.\n",me);
return 1;
}
