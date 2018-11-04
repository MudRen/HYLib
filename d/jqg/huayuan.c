//huayuan.c ��԰
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short",HIM"��԰"NOR);
          set("long",@LONG
�����ǻ�԰���������黨��(flower)����������һ��С������������ֵ��
�£������ںɻ��������˻��䣬��ֻ����ſ�ں�Ҷ�ϡ����ɡ��ؽи���ͣ����
�Ϸ�һ����ɽ��hill����������һ�����ȡ�
LONG
    );
          set("item_desc",([
                "flower": "��֦Ҷ������С�̣��黨�������ɫ�����ޱȣ��յ����̲�סȥժ������\n",
                "hill": "����һ����ɽ��һ���ʯ����ɽǰ������ȥ����ʯ�ƺ���Щ��֣�\n"+
                        "��ʯ�����ƺ���Щ��ͬѰ�����������µ������ڼ�ɽǰ��\n",
          ]));

          set("outdoors","�����");
	  set("exits",([
              "south": __DIR__"lang1",
          ]));  

          set("objects",([
                 __DIR__"npc/dizi1" : 2,
          ]));
          setup();
}

void init()
{
          add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{    
          object me = this_player();
          if (!arg || (arg != "flower"))
              return notify_fail("��Ҫժʲô����\n");
          if (me->is_busy() || me->is_fighting())
	      return notify_fail("����æ���ģ�\n");
          if (present("flower", this_player()))
	      return notify_fail("�����ϲ�����ô������Ҫ��̫̰���ˡ�\n");
          if(me->query_condition("medicine"))
              return notify_fail("���ժ������ô��ͻ���Ҫ��\n");
          message_vision(HIY"$N�ܿ�֦�ϼ�̣�����ȥժ"HIM"�黨"HIY"����������С�ġ�\n"NOR, this_player());
          new(__DIR__"obj/flower")->move(me);
          me->start_busy(2);
          if ( random(me->query("per")) < 10 ){
          message_vision(HIY"��֪���䱳��������С�̣���$N����ָ�������ˡ�\n"NOR, this_player());
          me->apply_condition("qinghua_poison", me->query("per") + random(me->query("per"))); 
          return 1;
          }
          else {
          message_vision(HIY"$N�ƿ����䱳���С�̣����ֽ�"HIM"�黨"HIY"ժ��������\n"NOR, this_player());
          return 1;
          }
}
